#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Event = pair<int, int>;


struct Volunteer {
    int timePerBalloon, numBalloonsBeforeRest, restTime,
        curTime, workSessionTime, numWorkSessions, extraBalloons;
    void setTime(const int& time) {
        auto intDiv = div(time, workSessionTime);
        numWorkSessions = intDiv.quot;
        extraBalloons = min(intDiv.rem / timePerBalloon, numBalloonsBeforeRest);
        if (extraBalloons == 0) {
            --numWorkSessions;
            extraBalloons = numBalloonsBeforeRest;
        }
        curTime = numWorkSessions * workSessionTime + extraBalloons * timePerBalloon;
    }
    void reverseTime() {
        curTime -= timePerBalloon;
        --extraBalloons;
        if (extraBalloons == 0) {
            --numWorkSessions;
            extraBalloons = numBalloonsBeforeRest;
            curTime -= restTime;
        }
    }
    int getNumBalloons() const {
        return numWorkSessions * numBalloonsBeforeRest + extraBalloons;
    }
};


int main() {
    int numBalloons, numVolunteers;
    cin >> numBalloons >> numVolunteers;

    double meanBalloonsPerTime = 0;
    vector<Volunteer> volunteers(numVolunteers);
    for (Volunteer& vol : volunteers) {
        cin >> vol.timePerBalloon >> vol.numBalloonsBeforeRest >> vol.restTime;
        vol.workSessionTime = vol.timePerBalloon * vol.numBalloonsBeforeRest + vol.restTime;
        meanBalloonsPerTime += ((double) vol.numBalloonsBeforeRest) / vol.workSessionTime;
        vol.setTime(0);
    }

    priority_queue<Event> events;
    int index = 0, totalNumBalloons = 0, adjustedTime = numBalloons / meanBalloonsPerTime + 1;
    for (Volunteer& vol : volunteers) {
        vol.setTime(adjustedTime + vol.timePerBalloon);
        totalNumBalloons += vol.getNumBalloons();
        events.emplace(make_pair(vol.curTime, index));
        ++index;
    }

    while (totalNumBalloons > numBalloons) {
        index = events.top().second;
        events.pop();
        volunteers[index].reverseTime();
        events.emplace(volunteers[index].curTime, index);
        --totalNumBalloons;
    }

    int minTime = 0;
    for (Volunteer& vol : volunteers) {
        minTime = max(minTime, vol.curTime);
    }

    cout << minTime << endl;
    for (Volunteer& vol : volunteers) {
        cout << vol.getNumBalloons() << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}