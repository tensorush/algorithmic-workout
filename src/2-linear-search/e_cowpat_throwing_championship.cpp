#include <iostream>
#include <vector>

using namespace std;


int main() {
    unsigned numThrows;
    cin >> numThrows;
    vector<unsigned> throws(numThrows);
    for (unsigned& cur : throws) {
        cin >> cur;
    }

    unsigned next, cur = throws[1], farthestThrow = throws.front(), farthestVasilyThrow = 0;
    for (unsigned i = 2; i < numThrows; ++i) {
        next = throws[i];
        if (cur > farthestThrow) {
            farthestThrow = cur;
            farthestVasilyThrow = 0;
        } else if (next < cur && farthestVasilyThrow < cur && cur % 10 == 5) {
            farthestVasilyThrow = cur;
        }
        cur = next;
    }

    unsigned highestVasilyPlace = 0;
    if (farthestVasilyThrow != 0) {
        ++highestVasilyPlace;
        for (const unsigned& cur : throws) {
            if (cur > farthestVasilyThrow)
                ++highestVasilyPlace;
        }
    }
    cout << highestVasilyPlace << endl;

    return EXIT_SUCCESS;
}