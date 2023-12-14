#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <set>

using namespace std;


template<typename T>
void PrintContainer(const T& container) {
    cout << container.size() << endl;
    for (const auto& element : container) {
        cout << element << ' ';
    }
    cout << endl;
}


int main() {
    unsigned numAnyasCubes, numBoryasCubes;
    cin >> numAnyasCubes >> numBoryasCubes;

    unsigned colour;
    set<unsigned> AnyasColours;
    for (unsigned i = 0; i < numAnyasCubes; ++i) {
        cin >> colour;
        AnyasColours.emplace(colour);
    }

    set<unsigned> BoryasColours;
    for (unsigned j = 0; j < numBoryasCubes; ++j) {
        cin >> colour;
        BoryasColours.emplace(colour);
    }

    vector<unsigned> orderedIntersection;
    ranges::set_intersection(AnyasColours, BoryasColours, back_inserter(orderedIntersection));
    PrintContainer(orderedIntersection);

    vector<unsigned> AnyasUniqueColours;
    ranges::set_difference(AnyasColours, orderedIntersection, back_inserter(AnyasUniqueColours));
    PrintContainer(AnyasUniqueColours);

    vector<unsigned> BoryasUniqueColours;
    ranges::set_difference(BoryasColours, orderedIntersection, back_inserter(BoryasUniqueColours));
    PrintContainer(BoryasUniqueColours);

    return EXIT_SUCCESS;
}