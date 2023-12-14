#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    int numHeights;
    cin >> numHeights;

    int distance, height;
    vector<int> heights(numHeights);
    for (int& height : heights) {
        cin >> distance >> height;
    }

    vector<int> forwardAscents(numHeights);
    int prevHeight = heights.front(), curHeight;
    for (int i = 1; i < numHeights; ++i) {
        curHeight = heights[i];
        forwardAscents[i] = forwardAscents[i - 1] + max(0, curHeight - prevHeight);
        prevHeight = curHeight;
    }

    prevHeight = heights.back();
    vector<int> backwardAscents(numHeights);
    for (int j = numHeights - 2; j >= 0; --j) {
        curHeight = heights[j];
        backwardAscents[j] = backwardAscents[j + 1] + max(0, curHeight - prevHeight);
        prevHeight = curHeight;
    }

    int numRoutes;
    cin >> numRoutes;

    int start, finish, ascentSum;
    for (int k = 0; k < numRoutes; ++k) {
        cin >> start >> finish;
        --start;
        --finish;
        ascentSum = (start < finish) ? (forwardAscents[finish] - forwardAscents[start]) : (backwardAscents[finish] - backwardAscents[start]);
        cout << ascentSum << endl;
    }

    return EXIT_SUCCESS;
}