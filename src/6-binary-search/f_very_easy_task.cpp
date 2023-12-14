#include <iostream>

using namespace std;


int main() {
    long unsigned numCopies, copyTime_1, copyTime_2;
    cin >> numCopies >> copyTime_1 >> copyTime_2;

    long unsigned minTotalCopyTime, lessCopyTime = (copyTime_1 < copyTime_2) ? (copyTime_1) : (copyTime_2);
    if (numCopies == 1) {
        minTotalCopyTime = lessCopyTime;
    } else {
        --numCopies;
        long unsigned midCopyTime, midNumCopies, maxCopyTime = 0, minCopyTime = numCopies * lessCopyTime;
        while (maxCopyTime < minCopyTime) {
            midCopyTime = maxCopyTime + (minCopyTime - maxCopyTime) / 2;
            midNumCopies = midCopyTime / copyTime_1 + midCopyTime / copyTime_2;
            (midNumCopies < numCopies) ? (maxCopyTime = midCopyTime + 1) : (minCopyTime = midCopyTime);
        }
        minTotalCopyTime = minCopyTime + lessCopyTime;
    }
    cout << minTotalCopyTime << endl;

    return EXIT_SUCCESS;
}