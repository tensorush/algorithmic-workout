#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

using Point = pair<int, int>;


int main() {
    unsigned numPoints;
    cin >> numPoints;
    vector<Point> points(numPoints);
    for (auto& [x, y] : points) {
        cin >> x >> y;
    }

    Point point;
    set<Point> visitedPoints;
    auto& [pointX, pointY] = point;
    vector<long unsigned> distancesToNeighbours;
    long unsigned numNeighbours, numIsoscelesTriangles = 0;
    for (const auto& [originX, originY] : points) {
        for (const auto& [neighbourX, neighbourY] : points) {
            pointX = originX - neighbourX;
            pointY = originY - neighbourY;
            distancesToNeighbours.emplace_back(pow(pointX, 2) + pow(pointY, 2));
            if (visitedPoints.contains(point))
                --numIsoscelesTriangles;
            pointX = -pointX;
            pointY = -pointY;
            visitedPoints.emplace(point);
        }
        numNeighbours = distancesToNeighbours.size();
        sort(distancesToNeighbours.begin(), distancesToNeighbours.end());
        for (unsigned left = 0, right = 0; left < numNeighbours; ++left) {
            while (right < numNeighbours && distancesToNeighbours[left] == distancesToNeighbours[right]) {
                ++right;
            }
            numIsoscelesTriangles += right - left - 1;
        }
        distancesToNeighbours.clear();
        visitedPoints.clear();
    }
    cout << numIsoscelesTriangles << endl;

    return EXIT_SUCCESS;
}