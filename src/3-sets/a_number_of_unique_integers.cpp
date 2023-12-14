#include <unordered_set>
#include <iostream>

using namespace std;


int main() {
    int integer;
    unordered_set<int> uniqueIntegers;
    while (cin >> integer) {
        uniqueIntegers.emplace(integer);
    }
    cout << uniqueIntegers.size() << endl;

    return EXIT_SUCCESS;
}