#include <iostream>
#include <string>

using namespace std;


int main() {
    int prev, next;
    cin >> prev >> next;

    string SequenceType = (prev == next) ? ("CONSTANT") : ((prev < next) ? ("ASCENDING") : ("DESCENDING"));

    cin >> prev >> next;
    int stopNumber = -2e9;
    while (next > stopNumber) {
        if (SequenceType == "CONSTANT") {
            if (next > prev)
                SequenceType = "WEAKLY ASCENDING";
            else if (next < prev)
                SequenceType = "WEAKLY DESCENDING";
        } else if (SequenceType == "ASCENDING" || SequenceType == "WEAKLY ASCENDING") {
            if (SequenceType == "ASCENDING" && next == prev) {
                SequenceType = "WEAKLY ASCENDING";
            } else if (next < prev) {
                SequenceType = "RANDOM";
                break;
            }
        } else if (SequenceType == "DESCENDING" || SequenceType == "WEAKLY DESCENDING") {
            if (SequenceType == "DESCENDING" && next == prev) {
                SequenceType = "WEAKLY DESCENDING";
            } else if (next > prev) {
                SequenceType = "RANDOM";
                break;
            }
        }
        prev = next;
        cin >> next;
    }
    cout << SequenceType << endl;

    return EXIT_SUCCESS;
}