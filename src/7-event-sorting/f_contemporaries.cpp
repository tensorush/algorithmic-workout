#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

constexpr unsigned MATURE_AGE = 18;
constexpr unsigned SENILE_AGE = 80;
constexpr unsigned NO_CONTEMPORARIES = 0;

using Date = tuple<unsigned, unsigned, unsigned>;
using Event = tuple<Date, bool, unsigned>;


enum PersonType {
    Senile = 0,
    Mature = 1
};


int main() {
    unsigned numPeople;
    cin >> numPeople;

    vector<Event> events;
    Date birth, maturity, senility, death;
    auto& [birthYear, birthMonth, birthDay] = birth;
    auto& [deathYear, deathMonth, deathDay] = death;
    for (unsigned number = 1; number <= numPeople; ++number) {
        cin >> birthDay >> birthMonth >> birthYear
            >> deathDay >> deathMonth >> deathYear;
        maturity = senility = birth;
        get<0>(maturity) += MATURE_AGE;
        if (maturity < death) {
            events.emplace_back(make_tuple(maturity, Mature, number));
            get<0>(senility) += SENILE_AGE;
            events.emplace_back(make_tuple(min(senility, death), Senile, number));
        }
    }
    sort(events.begin(), events.end());

    if (events.empty())
        cout << NO_CONTEMPORARIES << endl;
    else {
        bool foundContemporary = false;
        unordered_set<unsigned> contemporaries;
        for (const auto& [date, type, number] : events) {
            if (type == Mature) {
                contemporaries.emplace(number);
                foundContemporary = true;
            } else {
                if (foundContemporary) {
                    for (const unsigned& contemporary : contemporaries) {
                        cout << contemporary << ' ';
                    }
                    cout << endl;
                    foundContemporary = false;
                }
                contemporaries.erase(number);
            }
        }
    }

    return EXIT_SUCCESS;
}