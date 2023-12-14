#include <unordered_set>
#include <iostream>

using namespace std;

using AngryBird = pair<unsigned, unsigned>;


int main() {
    unsigned numAngryBirds;
    cin >> numAngryBirds;

    AngryBird angryBird;
    unsigned minNumShots;
    auto& [x, y] = angryBird;
    unordered_set<unsigned> angryBirdsXCoordinates;
    for (unsigned i = 0; i < numAngryBirds; ++i) {
        cin >> x >> y;
        angryBirdsXCoordinates.emplace(x);
    }
    cout << angryBirdsXCoordinates.size() << endl;

    return EXIT_SUCCESS;
}