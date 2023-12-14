#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using Conditioner = pair<unsigned, unsigned>;


int main() {
    unsigned numClassrooms;
    cin >> numClassrooms;
    vector<unsigned> minPowers(numClassrooms);
    for (unsigned& minPower : minPowers) {
        cin >> minPower;
    }
    sort(minPowers.begin(), minPowers.end());

    unsigned numConditioners;
    cin >> numConditioners;
    vector<Conditioner> conditioners(numConditioners);
    for (auto& [price, power] : conditioners) {
        cin >> power >> price;
    }
    sort(conditioners.begin(), conditioners.end());

    unsigned cur = 0, minCost = 0;
    for (const unsigned& minPower : minPowers) {
        while (cur < numConditioners) {
            if (conditioners[cur].second < minPower) {
                ++cur;
            } else {
                minCost += conditioners[cur].first;
                break;
            }
        }
    }
    cout << minCost << endl;

    return EXIT_SUCCESS;
}