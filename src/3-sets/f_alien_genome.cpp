#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <set>

using namespace std;


int main() {
    string genome_1, genome_2;
    cin >> genome_1 >> genome_2;

    string basePair;
    multiset<string> basePairs_1;
    unsigned length_1 = genome_1.length();
    char cur, prev = genome_1.front();
    for (unsigned i = 1; i < length_1; ++i) {
        cur = genome_1[i];
        basePair = { prev, cur };
        basePairs_1.emplace(basePair);
        prev = cur;
    }

    set<string> basePairs_2;
    prev = genome_2.front();
    unsigned length_2 = genome_2.length();
    for (unsigned j = 1; j < length_2; ++j) {
        cur = genome_2[j];
        basePair = { prev, cur };
        basePairs_2.emplace(basePair);
        prev = cur;
    }

    vector<string> commonBasePairs;
    unsigned numCommonBasePairs = 0;
    ranges::set_intersection(basePairs_1, basePairs_2, back_inserter(commonBasePairs));
    for (const string& basePair : commonBasePairs) {
        numCommonBasePairs += basePairs_1.count(basePair);
    }
    cout << numCommonBasePairs << endl;

    return EXIT_SUCCESS;
}