#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

using Point = pair<int, int>;


int main() {
    int time, distance;
    unsigned numMessages;
    cin >> time >> distance >> numMessages;

    int x, y, x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0;
    for (unsigned i = 0; i < numMessages; ++i) {
        cin >> x >> y;
        x_1 = max(x_1 - time, x + y - distance);
        y_1 = max(y_1 - time, x - y - distance);
        x_2 = min(x_2 + time, x + y + distance);
        y_2 = min(y_2 + time, x - y + distance);
    }

    set<Point> points;
    for (x = x_1; x <= x_2; ++x) {
        for (y = y_1; y <= y_2; ++y) {
            if ((x + y) % 2 == 0)
                points.emplace(make_pair((x + y) / 2, (x - y) / 2));
        }
    }
    cout << points.size() << endl;
    for (const auto& [x, y] : points) {
        cout << x << ' ' << y << endl;
    }

    return EXIT_SUCCESS;
}