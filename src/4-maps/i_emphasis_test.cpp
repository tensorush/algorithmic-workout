#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <set>

using namespace std;


int main() {
    unsigned dictionarySize;
    cin >> dictionarySize;

    string word, lowercaseWord;
    map<string, set<string>> dictionary;
    for (unsigned i = 0; i < dictionarySize; ++i) {
        cin >> word;
        lowercaseWord = word;
        for (char& letter : lowercaseWord) {
            letter = tolower(letter);
        }
        dictionary[lowercaseWord].emplace(word);
    }

    unsigned emphasisCount, numMistakes = 0;
    bool hasNoEmphasis, hasWrongEmphasis, hasMoreThanOneEmphasis;
    while (cin >> word) {
        lowercaseWord = word;
        for (char& letter : lowercaseWord) {
            letter = tolower(letter);
        }

        hasNoEmphasis = (word == lowercaseWord) ? (true) : (false);
        if (hasNoEmphasis) {
            ++numMistakes;
            continue;
        }

        hasWrongEmphasis = (dictionary.contains(lowercaseWord) && dictionary[lowercaseWord].contains(word) == false) ? (true) : (false);
        if (hasWrongEmphasis) {
            ++numMistakes;
            continue;
        }

        emphasisCount = 0;
        hasMoreThanOneEmphasis = false;
        for (const char& letter : word) {
            if (isupper(letter)) {
                ++emphasisCount;
                if (emphasisCount > 1) {
                    hasMoreThanOneEmphasis = true;
                    break;
                }
            }
        }
        if (hasMoreThanOneEmphasis) {
            ++numMistakes;
            continue;
        }
    }
    cout << numMistakes << endl;

    return EXIT_SUCCESS;
}