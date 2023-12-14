#include <iostream>

using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c < 0 ||
        a == 0 && b < 0 ||
        a == 0 && c * c != b) {
        cout << "NO SOLUTION" << endl;
    } else if (a == 0 && c * c == b) {
        cout << "MANY SOLUTIONS" << endl;
    } else {
        int x = (c * c - b) / a;
        if (x * a == c * c - b)
            cout << x << endl;
        else
            cout << "NO SOLUTION" << endl;
    }

    return EXIT_SUCCESS;
}