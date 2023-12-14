#include <algorithm>
#include <iostream>
#include <map>

using namespace std;


int main() {
    long unsigned numCards, differenceMultiplier;
    cin >> numCards >> differenceMultiplier;

    unsigned card;
    map<unsigned, unsigned> cardsCounter;
    for (unsigned i = 0; i < numCards; ++i) {
        cin >> card;
        ++cardsCounter[card];
    }

    numCards = 0;
    unsigned numDuplicates = 0;
    long unsigned numScores = 0;
    for (auto left = cardsCounter.begin(), right = cardsCounter.begin(); right != cardsCounter.end(); ++right) {
        while (differenceMultiplier * left->first < right->first) {
            --numCards;
            if (left->second > 1)
                --numDuplicates;
            ++left;
        }
        numScores += 3 * (numCards * (numCards - 1) + numDuplicates);
        if (right->second > 1) {
            numScores += 3 * numCards;
            if (right->second > 2)
                ++numScores;
            ++numDuplicates;
        }
        ++numCards;
    }
    cout << numScores << endl;

    return EXIT_SUCCESS;
}