#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    unsigned numShirts;
    cin >> numShirts;
    vector<int> shirtColours(numShirts);
    for (int& colour : shirtColours) {
        cin >> colour;
    }

    unsigned numPants;
    cin >> numPants;
    vector<int> pantsColours(numPants);
    for (int& colour : pantsColours) {
        cin >> colour;
    }

    unsigned stylishShirtColour, stylishPantsColour,
        stylishShirtColourIndex = 0, stylishPantsColourIndex = 0,
        minColourDiff = abs(shirtColours.front() - pantsColours.front());
    for (unsigned i = 0, j = 0; i < numShirts && j < numPants; (shirtColours[i] < pantsColours[j]) ? (++i) : (++j)) {
        if (shirtColours[i] == pantsColours[j]) {
            stylishShirtColourIndex = i;
            stylishPantsColourIndex = j;
            break;
        } else if (abs(shirtColours[i] - pantsColours[j]) < minColourDiff) {
            minColourDiff = abs(shirtColours[i] - pantsColours[j]);
            stylishShirtColourIndex = i;
            stylishPantsColourIndex = j;
        }
    }
    stylishShirtColour = shirtColours[stylishShirtColourIndex], stylishPantsColour = pantsColours[stylishPantsColourIndex];
    cout << stylishShirtColour << ' ' << stylishPantsColour << endl;

    return EXIT_SUCCESS;
}