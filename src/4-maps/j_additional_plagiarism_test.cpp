#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <sstream>
#include <cctype>
#include <string>

using namespace std;


void MakeLowercase(string& potentialIdentifier) {
    for (char& symbol : potentialIdentifier) {
        symbol = tolower(symbol);
    }
}

void LeaveOnlyLettersDigitsAndUnderscores(string& programLine) {
    char symbol;
    unsigned length = programLine.length();
    for (unsigned i = 0; i < length; ++i) {
        symbol = programLine[i];
        if (symbol != '_' && isalnum(symbol) == false)
            programLine.replace(i, 1, " ");
    }
}

bool IsCorrectIdentifier(const string& potentialIdentifier, const string& canDigitBeFirst) {
    bool isDigit = true;
    for (const char& symbol : potentialIdentifier) {
        if (isdigit(symbol) == false) {
            isDigit = false;
            break;
        }
    }
    bool isCorrectIdentifier = (isDigit || canDigitBeFirst == "no" && isdigit(potentialIdentifier.front())) ? (false) : (true);
    return isCorrectIdentifier;
}


int main() {
    unsigned numKeywords;
    cin >> numKeywords;

    string isCaseSensitive, canDigitBeFirst;
    cin >> isCaseSensitive >> canDigitBeFirst;
    unordered_set<string> keywords;
    if (numKeywords > 0) {
        string keyword;
        for (unsigned i = 0; i < numKeywords; ++i) {
            cin >> keyword;
            if (isCaseSensitive == "no")
                MakeLowercase(keyword);
            keywords.emplace(keyword);
        }
    }

    unsigned newIdentifierIndex = 0;
    string programLine, potentialIdentifier;
    unordered_map<string, pair<unsigned, unsigned>> identifierCounter;
    while (getline(cin, programLine)) {
        LeaveOnlyLettersDigitsAndUnderscores(programLine);
        stringstream clearedLine(programLine);
        while (clearedLine >> potentialIdentifier) {
            if (isCaseSensitive == "no")
                MakeLowercase(potentialIdentifier);
            if (keywords.contains(potentialIdentifier) == false &&
                IsCorrectIdentifier(potentialIdentifier, canDigitBeFirst)) {
                if (identifierCounter.contains(potentialIdentifier)) {
                    ++identifierCounter[potentialIdentifier].first;
                } else {
                    identifierCounter[potentialIdentifier].second = newIdentifierIndex;
                    ++identifierCounter[potentialIdentifier].first;
                    ++newIdentifierIndex;
                }
            }
        }
    }

    string mostFrequentIdentifier;
    unsigned maxCount = 0, minPosition = UINT32_MAX;
    for (const auto& [identifier, countPosition] : identifierCounter) {
        auto [count, position] = countPosition;
        if (count > maxCount ||
            count == maxCount && position < minPosition) {
            maxCount = count;
            minPosition = position;
            mostFrequentIdentifier = identifier;
        }
    }
    cout << mostFrequentIdentifier << endl;

    return EXIT_SUCCESS;
}