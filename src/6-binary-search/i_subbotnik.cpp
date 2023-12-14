#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    unsigned numPupilsPerClass, numTotalBrigades, numPupilsPerBrigade;
    cin >> numPupilsPerClass >> numTotalBrigades >> numPupilsPerBrigade;

    vector<unsigned> heights(numPupilsPerClass);
    for (unsigned& height : heights) {
        cin >> height;
    }
    sort(heights.begin(), heights.end());

    unsigned i, numBrigades, midDiscomfort, minMaxDiscomfort = 0, minDiscomfort = heights.back() - heights.front();
    while (minMaxDiscomfort < minDiscomfort) {
        i = 0;
        numBrigades = 0;
        midDiscomfort = minMaxDiscomfort + (minDiscomfort - minMaxDiscomfort) / 2;
        while (i < numPupilsPerClass - numPupilsPerBrigade + 1) {
            if (heights[i + numPupilsPerBrigade - 1] - heights[i] <= midDiscomfort) {
                ++numBrigades;
                i += numPupilsPerBrigade;
            } else {
                ++i;
            }
        }
        (numBrigades >= numTotalBrigades) ? (minDiscomfort = midDiscomfort) : (minMaxDiscomfort = midDiscomfort + 1);
    }
    cout << minMaxDiscomfort << endl;

    return EXIT_SUCCESS;
}