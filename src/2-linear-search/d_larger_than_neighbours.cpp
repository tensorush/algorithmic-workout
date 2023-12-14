#include <iostream>

using namespace std;


int main() {
    int left, cur;
    cin >> left >> cur;

    int right;
    unsigned numLargerThanNeighbours = 0;
    while (cin >> right) {
        if (cur > left && cur > right)
            ++numLargerThanNeighbours;
        left = cur;
        cur = right;
    }
    cout << numLargerThanNeighbours << endl;

    return EXIT_SUCCESS;
}