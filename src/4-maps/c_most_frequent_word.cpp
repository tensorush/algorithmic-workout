#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;


int main() {
    string word;
    unordered_map<string, unsigned> wordCounter;
    while (cin >> word) {
        ++wordCounter[word];
    }

    string maxFrequencyWord;
    unsigned maxFrequency = 0;
    for (const auto& [word, frequency] : wordCounter) {
        if (frequency > maxFrequency) {
            maxFrequencyWord = word;
            maxFrequency = frequency;
        }
    }
    cout << maxFrequencyWord << endl;

    return EXIT_SUCCESS;
}