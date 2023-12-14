#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

constexpr double MIN_FREQUENCY = 30;
constexpr double MAX_FREQUENCY = 4000;
constexpr double DEFAULT_PRECISION = 6;
constexpr double DEFAULT_EPSILON = 1e-6;

using Note = pair<double, string>;


int main() {
    unsigned numNotes;
    double firstFrequency;
    cin >> numNotes >> firstFrequency;

    vector<Note> notes(numNotes - 1);
    for (auto& [frequency, proximity] : notes) {
        cin >> frequency >> proximity;
    }

    double minFrequency = MIN_FREQUENCY, maxFrequency = MAX_FREQUENCY,
        prevFrequency = firstFrequency, EPS = DEFAULT_EPSILON;
    for (const auto& [frequency, proximity] : notes) {
        if (abs(frequency - prevFrequency) > EPS) {
            if ((proximity == "closer" && frequency < prevFrequency) ||
                (proximity == "further" && frequency > prevFrequency))
                maxFrequency = max(minFrequency, min((prevFrequency + frequency) / 2, maxFrequency));
            else
                minFrequency = min(maxFrequency, max((prevFrequency + frequency) / 2, minFrequency));
        }
        prevFrequency = frequency;
    }
    cout << fixed << showpoint << setprecision(DEFAULT_PRECISION) << minFrequency << ' ' << maxFrequency << endl;

    return EXIT_SUCCESS;
}