#include <iostream>

using namespace std;


int main() {
    long long number,
        min_1 = INT64_MAX, min_2 = INT64_MAX, min_3 = INT64_MAX,
        max_1 = INT64_MIN, max_2 = INT64_MIN, max_3 = INT64_MIN;
    while (cin >> number) {
        if (number < min_1) {
            min_3 = min_2;
            min_2 = min_1;
            min_1 = number;
        } else if (number < min_2) {
            min_3 = min_2;
            min_2 = number;
        } else if (number < min_3) {
            min_3 = number;
        }
        if (number > max_1) {
            max_3 = max_2;
            max_2 = max_1;
            max_1 = number;
        } else if (number > max_2) {
            max_3 = max_2;
            max_2 = number;
        } else if (number > max_3) {
            max_3 = number;
        }
    }

    long long min = min_1 * min_2 * min_3,
        max = max_1 * max_2 * max_3,
        twoMinOneMax = min_1 * min_2 * max_1;
    if (min > max && min > twoMinOneMax)
        cout << min_1 << ' ' << min_2 << ' ' << min_3 << endl;
    else if (max > min && max > twoMinOneMax)
        cout << max_1 << ' ' << max_2 << ' ' << max_3 << endl;
    else
        cout << min_1 << ' ' << min_2 << ' ' << max_1 << endl;

    return EXIT_SUCCESS;
}