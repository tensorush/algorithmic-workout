#include <iostream>
#include <vector>

using namespace std;


int main() {
    unsigned numElements;
    cin >> numElements;

    vector<int> array(numElements);
    for (int& element : array) {
        cin >> element;
    }

    int target;
    cin >> target;

    int closestNumber;
    unsigned distance, minDistance = INT32_MAX;
    for (const int& number : array) {
        distance = abs(target - number);
        if (distance < minDistance) {
            minDistance = distance;
            closestNumber = number;
        }
    }
    cout << closestNumber << endl;

    return EXIT_SUCCESS;
}