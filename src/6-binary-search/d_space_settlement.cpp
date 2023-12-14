#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    long unsigned numModules, width, length, fieldWidth, fieldHeight;
    cin >> numModules >> width >> length >> fieldWidth >> fieldHeight;

    long unsigned midThickness, midNumModules, midNumModules_1, midNumModules_2, maxThickness = 0, minThickness = 1e18;
    while (maxThickness < minThickness) {
        midThickness = (maxThickness + minThickness + 1) / 2;
        midNumModules_1 = (fieldWidth / (width + 2 * midThickness)) * (fieldHeight / (length + 2 * midThickness));
        midNumModules_2 = (fieldHeight / (width + 2 * midThickness)) * (fieldWidth / (length + 2 * midThickness));
        midNumModules = max(midNumModules_1, midNumModules_2);
        (midNumModules < numModules) ? (minThickness = midThickness - 1) : (maxThickness = midThickness);
    }
    cout << maxThickness << endl;

    return EXIT_SUCCESS;
}