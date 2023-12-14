#include <iostream>
#include <string>

using namespace std;


int main() {
    string conditionerMode;
    int roomTemperature, conditionerTemperature;
    cin >> roomTemperature >> conditionerTemperature >> conditionerMode;

    int temperatureAfterAnHour = roomTemperature;
    if (conditionerMode == "auto" ||
        conditionerMode == "heat" && roomTemperature < conditionerTemperature ||
        conditionerMode == "freeze" && roomTemperature > conditionerTemperature)
        temperatureAfterAnHour = conditionerTemperature;
    cout << temperatureAfterAnHour << endl;

    return EXIT_SUCCESS;
}
