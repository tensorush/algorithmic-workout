#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;


int main() {
    string word;
    unsigned numUniqueWords;
    unordered_set<string> uniqueWords;
    while (cin >> word) {
        uniqueWords.emplace(word);
    }
    cout << uniqueWords.size() << endl;

    return EXIT_SUCCESS;
}