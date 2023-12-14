#include <iostream>
#include <vector>

using namespace std;


int main() {
    unsigned numTrees, numColours;
    cin >> numTrees >> numColours;

    vector<unsigned> treeColours(numTrees);
    for (unsigned& colour : treeColours) {
        cin >> colour;
    }

    unsigned colour, curNumColours = 0,
        left = 0, right = 0, minLeft = 1, minRight = numTrees;
    vector<unsigned> colourCounter(numColours + 1);
    while (right < numTrees) {
        colour = treeColours[right];
        curNumColours += (colourCounter[colour] > 0) ? (0) : (1);
        ++colourCounter[colour];
        ++right;
        if (curNumColours == numColours) {
            while (colourCounter[colour] > 0) {
                colour = treeColours[left];
                --colourCounter[colour];
                ++left;
            }
            if (right - left < minRight - minLeft) {
                minLeft = left;
                minRight = right;
            }
            --curNumColours;
        }
    }
    cout << minLeft << ' ' << minRight << endl;

    return EXIT_SUCCESS;
}