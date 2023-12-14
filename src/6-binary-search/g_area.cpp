#include <iostream>

using namespace std;


int main() {
    long unsigned cityWidth, cityLength, numTiles;
    cin >> cityWidth >> cityLength >> numTiles;

    long unsigned cityArea = cityWidth * cityLength, smallerCitySide = (cityWidth < cityLength) ? (cityWidth) : (cityLength),
        midWidth, midWidth_2, midNumTiles, maxWidth = 0, minWidth = smallerCitySide;
    while (maxWidth < minWidth) {
        midWidth = (minWidth + maxWidth + 1) / 2;
        midWidth_2 = 2 * midWidth;
        midNumTiles = cityArea - (cityWidth - midWidth_2) * (cityLength - midWidth_2);
        (midWidth_2 > smallerCitySide || midNumTiles > numTiles) ? (minWidth = midWidth - 1) : (maxWidth = midWidth);
    }
    cout << maxWidth << endl;

    return EXIT_SUCCESS;
}