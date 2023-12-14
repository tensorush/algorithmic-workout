#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;


int main() {
    string word, script;
    unsigned wordLength, scriptLength;
    cin >> wordLength >> scriptLength >> word >> script;

    unordered_map<char, unsigned> wordCounter;
    for (const char& letter : word) {
        ++wordCounter[letter];
    }

    unordered_map<char, unsigned> scriptCounter;
    for (unsigned i = 0; i < wordLength - 1; ++i) {
        ++scriptCounter[script[i]];
    }

    char scriptLetterToRemove;
    unsigned numOccurrences = 0;
    for (unsigned i = wordLength - 1; i < scriptLength; ++i) {
        ++scriptCounter[script[i]];
        if (scriptCounter == wordCounter)
            ++numOccurrences;
        scriptLetterToRemove = script[i - wordLength + 1];
        --scriptCounter[scriptLetterToRemove];
        if (scriptCounter[scriptLetterToRemove] == 0)
            scriptCounter.erase(scriptLetterToRemove);
    }
    cout << numOccurrences << endl;

    return EXIT_SUCCESS;
}