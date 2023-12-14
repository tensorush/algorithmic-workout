#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using SupervisionRange = pair<unsigned, unsigned>;


int main() {
    unsigned numStudents, numTeachers;
    cin >> numStudents >> numTeachers;
    vector<SupervisionRange> ranges(numTeachers);
    for (auto& [first, last] : ranges) {
        cin >> first >> last;
    }
    sort(ranges.begin(), ranges.end());

    unsigned cur = 0, numUnsupervisedStudents = 0;
    for (const auto& [first, last] : ranges) {
        if (first > cur)
            numUnsupervisedStudents += first - cur;
        if (last >= cur)
            cur = last + 1;
    }
    if (cur < numStudents)
        numUnsupervisedStudents += numStudents - cur;
    cout << numUnsupervisedStudents << endl;

    return EXIT_SUCCESS;
}