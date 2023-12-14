#include <iostream>
#include <vector>

using namespace std;


int main() {
    unsigned numMonuments, maxDistance;
    cin >> numMonuments >> maxDistance;
    vector<unsigned> monuments(numMonuments);
    for (unsigned& monument : monuments) {
        cin >> monument;
    }

    unsigned i = 0, j = 1;
    long unsigned numWays = 0;
    while (j < numMonuments) {
        if (monuments[j] - monuments[i] > maxDistance) {
            numWays += numMonuments - j;
            ++i;
        } else {
            ++j;
        }
    }
    cout << numWays << endl;

    return EXIT_SUCCESS;
}