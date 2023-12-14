#include <iostream>
#include <set>

using namespace std;

using Tortoise = pair<int, int>;


int main() {
    int numTortoises;
    cin >> numTortoises;

    Tortoise tortoise;
    set<Tortoise> tortoises;
    auto& [front, back] = tortoise;
    unsigned numTruthTellingTortoises = 0;
    for (unsigned tortoiseCountdown = numTortoises; tortoiseCountdown > 0; --tortoiseCountdown) {
        cin >> front >> back;
        if (front >= 0 && back >= 0 &&
            front + back + 1 == numTortoises &&
            tortoises.contains(tortoise) == false) {
            tortoises.emplace(tortoise);
            ++numTruthTellingTortoises;
        }
    }
    cout << numTruthTellingTortoises << endl;

    return EXIT_SUCCESS;
}