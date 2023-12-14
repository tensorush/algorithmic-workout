#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

constexpr unsigned AD_DURATION = 5;
constexpr unsigned MIN_TIME_BETWEEN_AD_STARTS = 10;

using Event = tuple<unsigned, bool, unsigned>;


enum CustomerStatus {
    Arrived = 0,
    Departed = 1
};


int main() {
    unsigned numCustomers;
    cin >> numCustomers;

    vector<Event> events;
    unsigned arrival, departure;
    for (unsigned index = 0; index < numCustomers; ++index) {
        cin >> arrival >> departure;
        if (departure - arrival >= AD_DURATION) {
            events.emplace_back(make_tuple(arrival, Arrived, index));
            events.emplace_back(make_tuple(departure - AD_DURATION, Departed, index));
        }
    }
    sort(events.begin(), events.end());

    unsigned numEvents = events.size(), maxViews = 0,
        bestFirstAdStart = MIN_TIME_BETWEEN_AD_STARTS,
        bestSecondAdStart = bestFirstAdStart + MIN_TIME_BETWEEN_AD_STARTS;
    if (numEvents == 2) {
        ++maxViews;
        bestFirstAdStart = get<0>(events.front());
        bestSecondAdStart = bestFirstAdStart + MIN_TIME_BETWEEN_AD_STARTS;
    } else if (numEvents > 2) {
        unordered_set<unsigned> firstAdViewers;
        unsigned numFirstAdViewers, numSecondAdViewers;
        for (unsigned firstAdStart = 0; firstAdStart < numEvents; ++firstAdStart) {
            auto [time_1, status_1, index_1] = events[firstAdStart];
            if (status_1 == Arrived) {
                firstAdViewers.emplace(index_1);
                if (maxViews < firstAdViewers.size()) {
                    maxViews = firstAdViewers.size();
                    bestFirstAdStart = time_1;
                    bestSecondAdStart = time_1 + AD_DURATION;
                }
            }
            numSecondAdViewers = 0;
            numFirstAdViewers = firstAdViewers.size();
            for (unsigned secondAdStart = firstAdStart + 1; secondAdStart < numEvents; ++secondAdStart) {
                auto [time_2, status_2, index_2] = events[secondAdStart];
                if (status_2 == Arrived && firstAdViewers.contains(index_2) == false)
                    ++numSecondAdViewers;
                if (time_2 - time_1 >= AD_DURATION && numFirstAdViewers + numSecondAdViewers > maxViews) {
                    maxViews = numFirstAdViewers + numSecondAdViewers;
                    bestFirstAdStart = time_1;
                    bestSecondAdStart = time_2;
                }
                if (status_2 == Departed && firstAdViewers.contains(index_2) == false)
                    --numSecondAdViewers;
            }
            if (status_1 == Departed)
                firstAdViewers.erase(index_1);
        }
    }
    cout << maxViews << ' ' << bestFirstAdStart << ' ' << bestSecondAdStart << endl;

    return EXIT_SUCCESS;
}