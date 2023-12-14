#include <iostream>

using namespace std;


int main() {
    long unsigned width, height, numDiplomas;
    cin >> width >> height >> numDiplomas;

    long unsigned midBoardSide, midNumDiplomas,
        maxBoardSide = (width > height) ? (width) : (height),
        minBoardSide = maxBoardSide * numDiplomas;
    while (maxBoardSide < minBoardSide) {   
        midBoardSide = maxBoardSide + (minBoardSide - maxBoardSide) / 2;
        midNumDiplomas = (midBoardSide / width) * (midBoardSide / height);
        (midNumDiplomas < numDiplomas) ? (maxBoardSide = midBoardSide + 1) : (minBoardSide = midBoardSide);
    }
    cout << minBoardSide << endl;

    return EXIT_SUCCESS;
}