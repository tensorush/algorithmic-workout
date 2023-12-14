#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;


int main() {
    unsigned numKeys;
    cin >> numKeys;

    int numMaxKeystrokes;
    unordered_map<unsigned, int> keystrokeCounter;
    for (unsigned i = 1; i <= numKeys; ++i) {
        cin >> numMaxKeystrokes;
        keystrokeCounter[i] = numMaxKeystrokes;
    }

    unsigned keystroke, numKeystrokes;
    cin >> numKeystrokes;
    for (unsigned i = 0; i < numKeystrokes; ++i) {
        cin >> keystroke;
        --keystrokeCounter[keystroke];
    }

    string isBroken;
    for (unsigned i = 1; i <= numKeys; ++i) {
        isBroken = (keystrokeCounter[i] < 0) ? ("YES") : ("NO");
        cout << isBroken << endl;
    }

    return EXIT_SUCCESS;
}