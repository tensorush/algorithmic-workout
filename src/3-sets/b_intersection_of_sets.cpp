#include <unordered_set>
#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;


int main() {
    int integer;

    string firstSet;
    getline(cin, firstSet);
    stringstream line_1(firstSet);

    unordered_set<int> uniqueIntegers;
    while (line_1 >> integer) {
        uniqueIntegers.emplace(integer);
    }

    string secondSet;
    getline(cin, secondSet);
    stringstream line_2(secondSet);

    set<int> orderedIntersection;
    while (line_2 >> integer) {
        if (uniqueIntegers.contains(integer))
            orderedIntersection.emplace(integer);
    }

    for (const int& integer : orderedIntersection) {
        cout << integer << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}