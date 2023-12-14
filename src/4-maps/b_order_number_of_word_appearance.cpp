#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;


int main() {
    string word;
    unordered_map<string, unsigned> wordCounter;
    while (cin >> word) {
        cout << wordCounter[word] << ' ';
        ++wordCounter[word];
    }
    cout << endl;

    return EXIT_SUCCESS;
}