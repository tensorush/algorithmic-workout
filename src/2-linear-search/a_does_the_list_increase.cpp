#include <iostream>
#include <string>

using namespace std;


int main() {
    int prev;
    cin >> prev;

    int next;
    string doesIncrease = "YES";
    while (cin >> next) {
        if (next <= prev) {
            doesIncrease = "NO";
            break;
        }
        prev = next;
    }
    cout << doesIncrease << endl;

    return EXIT_SUCCESS;
}