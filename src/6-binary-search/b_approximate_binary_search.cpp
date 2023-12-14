#include <iostream>
#include <vector>

using namespace std;


unsigned NearestNeighbourSearch(const vector<int>& array, const int& key) {
    unsigned predecessor, successor, nearestNeighbour, mid, low = 0, high = array.size();
    while (low < high) {
        mid = low + (high - low) / 2;
        if (array[mid] > key)
            high = mid;
        else if (array[mid] < key)
            low = mid + 1;
        else
            return mid;
    }
    predecessor = low - 1, successor = low;
    nearestNeighbour = (successor < array.size() && (successor == 0 || array[successor] - key < key - array[predecessor])) ? (successor) : (predecessor);
    return nearestNeighbour;
}

int main() {
    unsigned numElements, numKeys;
    cin >> numElements >> numKeys;
    vector<int> array(numElements);
    for (int& element : array) {
        cin >> element;
    }

    unsigned key, nearestNeighbour;
    for (unsigned k = 0; k < numKeys; ++k) {
        cin >> key;
        nearestNeighbour = NearestNeighbourSearch(array, key);
        cout << array[nearestNeighbour] << endl;
    }

    return EXIT_SUCCESS;
}