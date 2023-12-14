#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

constexpr int IMPOSSIBLE_SCHEDULE = -1;
constexpr unsigned MINUTES_PER_HOUR = 60;

using Event = tuple<unsigned, bool, unsigned>;


enum BusStatus {
    Arrived = 0,
    Departed = 1
};

void ReadEvent(istream& in, unsigned& time, bool& type, unsigned& cityID, vector<Event>& events, const bool& busStatus) {
    unsigned hours, minutes;
    in >> cityID >> hours;
    in.ignore();
    in >> minutes;
    time = MINUTES_PER_HOUR * hours + minutes;
    type = busStatus;
    --cityID;
    events.emplace_back(make_tuple(time, type, cityID));
}


int main() {
    unsigned numCities, numTrips;
    cin >> numCities >> numTrips;

    bool type;
    vector<Event> events;
    unsigned time, cityID;
    unsigned arrival, departure, minNumBuses = 0;
    for (unsigned i = 0; i < numTrips; ++i) {
        ReadEvent(cin, time, type, cityID, events, Departed);
        departure = time;
        ReadEvent(cin, time, type, cityID, events, Arrived);
        arrival = time;
        if (departure > arrival)
            ++minNumBuses;
    }
    sort(events.begin(), events.end());

    vector<int> minBusesPerCity(numCities), busesPerCityCounter(numCities);
    for (const auto& [time, type, cityID] : events) {
        if (type == Arrived) {
            ++busesPerCityCounter[cityID];
        } else {
            --busesPerCityCounter[cityID];
            minBusesPerCity[cityID] = min(minBusesPerCity[cityID], busesPerCityCounter[cityID]);
        }
    }

    for (unsigned i = 0; i < numCities; ++i) {
        if (busesPerCityCounter[i] != 0) {
            minNumBuses = IMPOSSIBLE_SCHEDULE;
            break;
        }
        minNumBuses -= minBusesPerCity[i];
    }
    cout << minNumBuses << endl;

    return EXIT_SUCCESS;
}