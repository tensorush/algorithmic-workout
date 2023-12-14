#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using Point = tuple<int, int, int>;


enum PointType {
    SegmentStart = 0,
    OffSegment = 1,
    SegmentEnd = 2
};


int main() {
    unsigned numSegments, numPoints;
    cin >> numSegments >> numPoints;

    int start, end;
    vector<Point> points;
    for (unsigned i = 0; i < numSegments; ++i) {
        cin >> start >> end;
        if (start > end)
            swap(start, end);
        points.emplace_back(make_tuple(start, SegmentStart, -1));
        points.emplace_back(make_tuple(end, SegmentEnd, -1));
    }

    int coordinate;
    for (int index = 0; index < numPoints; ++index) {
        cin >> coordinate;
        points.emplace_back(make_tuple(coordinate, OffSegment, index));
    }
    sort(points.begin(), points.end());

    unsigned numCoveringSegments = 0;
    vector<unsigned> coveringSegmentCounter(numPoints);
    for (const auto& [coordinate, type, index] : points) {
        if (type == OffSegment)
            coveringSegmentCounter[index] = numCoveringSegments;
        else if (type == SegmentStart)
            ++numCoveringSegments;
        else
            --numCoveringSegments;
    }
    for (const unsigned& numCoveringSegments : coveringSegmentCounter) {
        cout << numCoveringSegments << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}