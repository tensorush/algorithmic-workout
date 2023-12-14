#include <iostream>
#include <cctype>
#include <string>
#include <array>

using namespace std;

constexpr unsigned NUM_PHONES = 3;
constexpr int DEFAULT_PHONE_LENGTH = 11;

using Phone = array<char, DEFAULT_PHONE_LENGTH>;


Phone StandardizePhone(const string& phone) {
    Phone defaultPhone = { "7495" };
    for (int i = phone.size() - 1, j = DEFAULT_PHONE_LENGTH - 1; i >= 0; --i) {
        if (isdigit(phone[i])) {
            defaultPhone[j] = phone[i];
            --j;
            if (j <= 0)
                break;
        }
    }
    return defaultPhone;
}


int main() {
    string newPhone;
    cin >> newPhone;
    Phone defaultNewPhone = StandardizePhone(newPhone);

    string oldPhone, isMatching;
    for (unsigned i = 0; i < NUM_PHONES; ++i) {
        cin >> oldPhone;
        Phone defaultOldPhone = StandardizePhone(oldPhone);
        isMatching = (defaultOldPhone == defaultNewPhone) ? ("YES") : ("NO");
        cout << isMatching << endl;
    }

    return EXIT_SUCCESS;
}