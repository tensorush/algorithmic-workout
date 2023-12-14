#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr unsigned TIME_START = 0;
constexpr unsigned TIME_END = 10'000;

using WorkShift = pair<unsigned, unsigned>;


string IsSecure(const vector<WorkShift>& workShifts) {
    unsigned numGuards = workShifts.size();
    string no = "Wrong Answer", yes = "Accepted";
    if (workShifts.front().first > TIME_START || workShifts.back().second < TIME_END)
        return no;
    unsigned prevTimeLeave = TIME_START;
    for (unsigned i = 1; i < numGuards; ++i) {
        if (prevTimeLeave >= workShifts[i].first)
            return no;
        prevTimeLeave = workShifts[i - 1].second;
        if (workShifts[i].first > prevTimeLeave || prevTimeLeave >= workShifts[i].second)
            return no;
    }
    return yes;
}


int main() {
    unsigned numTests;
    cin >> numTests;

    unsigned numGuards;
    for (unsigned i = 0; i < numTests; ++i) {
        cin >> numGuards;
        vector<WorkShift> workShifts(numGuards);
        for (auto& [start, end] : workShifts) {
            cin >> start >> end;
        }
        sort(workShifts.begin(), workShifts.end());
        cout << IsSecure(workShifts) << endl;
    }

    return EXIT_SUCCESS;
}