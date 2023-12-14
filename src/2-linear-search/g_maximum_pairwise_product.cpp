#include <iostream>

using namespace std;


int main() {
    long long number,
        min_1 = INT64_MAX, min_2 = INT64_MAX,
        max_1 = INT64_MIN, max_2 = INT64_MIN;
    while (cin >> number) {
        if (number < min_1) {
            min_2 = min_1;
            min_1 = number;
        } else if (number < min_2) {
            min_2 = number;
        }
        if (number > max_1) {
            max_2 = max_1;
            max_1 = number;
        } else if (number > max_2) {
            max_2 = number;
        }
    }

    long long smaller, larger,
        min = min_1 * min_2,
        max = max_1 * max_2;
    if (min > max) {
        smaller = min_1;
        larger = min_2;
    } else {
        smaller = max_2;
        larger = max_1;
    }
    cout << smaller << ' ' << larger << endl;

    return EXIT_SUCCESS;
}