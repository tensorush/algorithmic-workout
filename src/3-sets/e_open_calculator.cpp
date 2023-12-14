#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    char digit_1, digit_2, digit_3;
    cin >> digit_1 >> digit_2 >> digit_3;
    set<char> availableDigits = { digit_1, digit_2, digit_3 };

    string number;
    cin >> number;
    set<char> requiredDigits;
    for (const char& digit : number) {
        requiredDigits.emplace(digit);
    }

    vector<unsigned> missingDigits;
    ranges::set_difference(requiredDigits, availableDigits, back_inserter(missingDigits));
    cout << missingDigits.size() << endl;

    return EXIT_SUCCESS;
}
