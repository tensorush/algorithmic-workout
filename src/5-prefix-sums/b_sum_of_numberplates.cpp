#include <iostream>
#include <vector>

using namespace std;


int main() {
    unsigned numCars, luckyNumber;
    cin >> numCars >> luckyNumber;
    vector<unsigned> numberplatesPrefix(numCars + 1);
    for (unsigned i = 1; i <= numCars; ++i) {
        cin >> numberplatesPrefix[i];
        numberplatesPrefix[i] += numberplatesPrefix[i - 1];
    }

    unsigned curSum, left = 0, right = 0, numSums = 0;
    while (right <= numCars) {
        curSum = numberplatesPrefix[right] - numberplatesPrefix[left];
        if (curSum > luckyNumber) {
            ++left;
        } else if (curSum < luckyNumber) {
            ++right;
        } else if (curSum == luckyNumber) {
            ++left;
            ++right;
            ++numSums;
        }
    }
    cout << numSums << endl;

    return EXIT_SUCCESS;
}