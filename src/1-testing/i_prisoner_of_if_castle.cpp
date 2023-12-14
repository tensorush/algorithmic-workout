#include <iostream>
#include <string>

using namespace std;


int main() {
    unsigned brickWidth, brickHeight, brickDepth, holeWidth, holeHeight;
    cin >> brickWidth >> brickHeight >> brickDepth >> holeWidth >> holeHeight;

    string isHoleEnough = "NO";

    unsigned minBrickSide;
    if (brickWidth < brickHeight)
        minBrickSide = (brickWidth < brickDepth) ? (brickWidth) : (brickDepth);
    else
        minBrickSide = (brickHeight < brickDepth) ? (brickHeight) : (brickDepth);

    unsigned secondMinBrickSide;
    if (minBrickSide <= holeWidth && minBrickSide <= holeHeight) {
        if (minBrickSide == brickWidth)
            secondMinBrickSide = (brickHeight < brickDepth) ? (brickHeight) : (brickDepth);
        else if (minBrickSide == brickHeight)
            secondMinBrickSide = (brickWidth < brickDepth) ? (brickWidth) : (brickDepth);
        else
            secondMinBrickSide = (brickWidth < brickHeight) ? (brickWidth) : (brickHeight);
        if (secondMinBrickSide <= holeWidth || secondMinBrickSide <= holeHeight)
            isHoleEnough = "YES";
    }
    cout << isHoleEnough << endl;

    return EXIT_SUCCESS;
}