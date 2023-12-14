#include <iostream>
#include <vector>
#include <string>

using namespace std;


unsigned LeftmostBinarySearch(const vector<int>& array, const int& key) {
    unsigned mid, low = 0, high = array.size();
    while (low < high) {
        mid = low + (high - low) / 2;
        (array[mid] < key) ? (low = mid + 1) : (high = mid);
    }
    return low;
}

int main() {
    unsigned numElements, numKeys;
    cin >> numElements >> numKeys;
    vector<int> array(numElements);
    for (int& element : array) {
        cin >> element;
    }

    int key;
    unsigned low;
    string hasFound;
    for (unsigned k = 0; k < numKeys; ++k) {
        cin >> key;
        low = LeftmostBinarySearch(array, key);
        hasFound = (array[low] == key) ? ("YES") : ("NO");
        cout << hasFound << endl;
    }

    return EXIT_SUCCESS;
}