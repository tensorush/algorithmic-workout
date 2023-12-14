#include <iostream>
#include <string>

using namespace std;


int main() {
    string assembly;
    unsigned numOperations;
    cin >> numOperations >> assembly;

    long unsigned numMatches = 0, numWays = 0, assemblyLength = assembly.length();
    for (unsigned i = numOperations; i < assemblyLength; ++i) {
        if (assembly[i] == assembly[i - numOperations]) {
            ++numMatches;
            numWays += numMatches;
        } else {
            numMatches = 0;
        }
    }
    cout << numWays << endl;

    return EXIT_SUCCESS;
}