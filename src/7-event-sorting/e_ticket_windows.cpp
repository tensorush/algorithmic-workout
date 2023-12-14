#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned MINUTES_PER_HOUR = 60;
constexpr unsigned MIDNIGHT_IN_MINUTES = 24 * 60;

using Event = pair<unsigned, int>;


enum TicketWindowStatus {
    Opened = 1,
    Closed = -1
};


int main() {
    unsigned numTicketWindows;
    cin >> numTicketWindows;

    vector<Event> events;
    unsigned openingHours, openingMinutes, openingTime,
        closingHours, closingMinutes, closingTime,
        numOvernightTicketWindows = 0;
    for (unsigned i = 0; i < numTicketWindows; ++i) {
        cin >> openingHours >> openingMinutes
            >> closingHours >> closingMinutes;
        openingTime = openingHours * MINUTES_PER_HOUR + openingMinutes;
        closingTime = closingHours * MINUTES_PER_HOUR + closingMinutes;
        events.emplace_back(make_pair(openingTime, Opened));
        events.emplace_back(make_pair(closingTime, Closed));
        if (openingTime >= closingTime)
            ++numOvernightTicketWindows;
    }
    sort(events.begin(), events.end());

    unsigned startingTimeWhenAllAreOpen = 0, totalTimeWhenAllAreOpen = 0;
    for (const auto& [time, status] : events) {
        numOvernightTicketWindows += status;
        if (numOvernightTicketWindows == numTicketWindows)
            startingTimeWhenAllAreOpen = time;
        if (status == Closed && numOvernightTicketWindows == numTicketWindows - 1)
            totalTimeWhenAllAreOpen += time - startingTimeWhenAllAreOpen;
    }
    if (numOvernightTicketWindows == numTicketWindows)
        totalTimeWhenAllAreOpen += MIDNIGHT_IN_MINUTES - startingTimeWhenAllAreOpen;
    cout << totalTimeWhenAllAreOpen << endl;

    return EXIT_SUCCESS;
}