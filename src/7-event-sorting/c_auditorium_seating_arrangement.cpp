#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using Student = pair<unsigned, unsigned>;


int main() {
    unsigned numStudents, minDistance;
    cin >> numStudents >> minDistance;

    unsigned i = 0;
    vector<Student> students(numStudents);
    for (auto& [place, index] : students) {
        cin >> place;
        index = i;
        ++i;
    }
    sort(students.begin(), students.end());

    ++minDistance;
    unsigned nextPlace, minNumVariants = 0;
    for (unsigned left = 0, right = 1; right < numStudents; ++left, ++right) {
        nextPlace = students[left].first + minDistance;
        while (right < numStudents && students[right].first < nextPlace) {
            ++right;
        }
        minNumVariants = max(minNumVariants, right - left);
    }

    i = 0;
    vector<unsigned> variants(numStudents);
    for (auto& [place, index] : students) {
        variants[index] = i % minNumVariants + 1;
        ++i;
    }

    cout << minNumVariants << endl;
    for (const unsigned& variant : variants) {
        cout << variant << ' ';
    }

    return EXIT_SUCCESS;
}