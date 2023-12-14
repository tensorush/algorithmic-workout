#include <iostream>
#include <vector>

using namespace std;


int main() {
    unsigned numWires, numEqualWires;
    cin >> numWires >> numEqualWires;

    unsigned maxWireLength = 0;
    vector<unsigned> wireLengths(numWires);
    for (unsigned& length : wireLengths) {
        cin >> length;
        if (length > maxWireLength)
            maxWireLength = length;
    }

    unsigned equalWiresCount, midLength, maxLength = 0, minLength = maxWireLength * numEqualWires;
    while (maxLength < minLength) {
        equalWiresCount = 0;
        midLength = (minLength + maxLength + 1) / 2;
        for (unsigned& length : wireLengths) {
            if (equalWiresCount >= numEqualWires)
                break;
            equalWiresCount += length / midLength;
        }
        (equalWiresCount < numEqualWires) ? (minLength = midLength - 1) : (maxLength = midLength);
    }
    cout << maxLength << endl;

    return EXIT_SUCCESS;
}