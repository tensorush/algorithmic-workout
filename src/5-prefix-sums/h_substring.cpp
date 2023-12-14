#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr char FIRST_LETTER = 'a';
constexpr unsigned ALPHABET_SIZE = 26;


int main() {
    string word;
    unsigned wordLength, maxRepetitions;
    cin >> wordLength >> maxRepetitions >> word;

    vector<unsigned> letterCounter(ALPHABET_SIZE);
    unsigned leftIndex, rightIndex,
        left = 0, maxSubstringLength = 0, maxSubstringIndex = 0;
    for (unsigned right = 0; right < wordLength; ++right) {
        rightIndex = word[right] - FIRST_LETTER;
        ++letterCounter[rightIndex];
        if (letterCounter[rightIndex] > maxRepetitions) {
            if (right - left > maxSubstringLength) {
                maxSubstringLength = right - left;
                maxSubstringIndex = left;
            }
            do {
                leftIndex = word[left] - FIRST_LETTER;
                --letterCounter[leftIndex];
                ++left;
            } while (leftIndex != rightIndex);
        }
    }

    if (wordLength - left > maxSubstringLength) {
        maxSubstringLength = wordLength - left;
        maxSubstringIndex = left;
    }
    cout << maxSubstringLength << ' ' << ++maxSubstringIndex << endl;

    return EXIT_SUCCESS;
}