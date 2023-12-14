#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void GenerateSequence(vector<int>& sequence, const unsigned& numElementsPerSequence, const int& d_1, const int& a, const int& c, const int& m) {
    int d = d_1;
    for (unsigned i = 0; i < numElementsPerSequence - 1; ++i) {
        sequence.emplace_back(sequence.back() + d);
        d = (a * d + c) % m;
    }
}

unsigned UpperBound(const vector<int>& sequence, const int& key) {
    unsigned mid, low = 0, high = sequence.size();
    while (low < high) {
        mid = low + (high - low) / 2;
        (sequence[mid] > key) ? (high = mid) : (low = mid + 1);
    }
    return high;
}

int LeftMedianOfUnion(const vector<int>& seq_1, const vector<int>& seq_2) {
    int mid, low = min(seq_1.front(), seq_2.front()), high = max(seq_1.back(), seq_2.back());
    while (low < high) {
        mid = low + (high - low) / 2;
        (UpperBound(seq_1, mid) + UpperBound(seq_2, mid) < seq_1.size()) ? (low = mid + 1) : (high = mid);
    }
    return low;
}

int main() {
    unsigned numSequences, numElementsPerSequence;
    cin >> numSequences >> numElementsPerSequence;

    vector<int> sequence;
    int x_1, d_1, a, c, m;
    vector<vector<int>> sequences;
    for (unsigned i = 0; i < numSequences; ++i) {
        cin >> x_1 >> d_1 >> a >> c >> m;
        sequence = { x_1 };
        GenerateSequence(sequence, numElementsPerSequence, d_1, a, c, m);
        sequences.emplace_back(sequence);
    }

    for (unsigned i = 0; i < numSequences; ++i) {
        for (unsigned j = i + 1; j < numSequences; ++j) {
            cout << LeftMedianOfUnion(sequences[i], sequences[j]) << endl;
        }
    }

    return EXIT_SUCCESS;
}