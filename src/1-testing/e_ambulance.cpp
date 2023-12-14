#include <unordered_set>
#include <iostream>

using namespace std;


auto Ambulance(const int& flat_1, const int& numFloors, const int& flat_2, const int& porch_2, const int& floor_2) {
    int porch_1 = -1, floor_1 = -1;
    if (floor_2 > numFloors)
        return make_pair(porch_1, floor_1);

    int option;
    unordered_set<int> flatsPerFloorOptions;
    if (porch_2 == 1 && floor_2 == 1) {
        for (option = flat_2; option <= flat_2 + numFloors; ++option) {
            flatsPerFloorOptions.emplace(option);
        }
    } else {
        int numFloorsUpToFloor_2 = numFloors * (porch_2 - 1) + floor_2 - 1,
            bound_1 = (flat_2 - 1) / numFloorsUpToFloor_2,
            bound_2 = flat_2 / (numFloorsUpToFloor_2 + 1),
            lowerBound = (bound_1 < bound_2) ? (bound_1) : (bound_2),
            upperBound = (bound_1 > bound_2) ? (bound_1) : (bound_2);
        for (option = lowerBound; option <= upperBound; ++option) {
            if (option > 0 && numFloorsUpToFloor_2 * option + (flat_2 - 1) % option == flat_2 - 1)
                flatsPerFloorOptions.emplace(option);
        }
    }

    if (flatsPerFloorOptions.empty()) {
        return make_pair(porch_1, floor_1);
    } else {
        int floorIndex, optionPorch_1, optionFloor_1;
        for (const int& option : flatsPerFloorOptions) {
            floorIndex = (flat_1 - 1 - (flat_1 - 1) % option) / option + 1;
            optionFloor_1 = floorIndex % numFloors;
            optionPorch_1 = (floorIndex - optionFloor_1) / numFloors + 1;
            if (optionFloor_1 == 0) {
                optionPorch_1 -= 1;
                optionFloor_1 = numFloors;
            }
            if (porch_1 == -1)
                porch_1 = optionPorch_1;
            else if (optionPorch_1 != porch_1)
                porch_1 = 0;
            if (floor_1 == -1)
                floor_1 = optionFloor_1;
            else if (optionFloor_1 != floor_1)
                floor_1 = 0;
        }
        return make_pair(porch_1, floor_1);
    }
}


int main() {
    int numFloors, flat_1, flat_2, porch_2, floor_2;
    cin >> flat_1 >> numFloors >> flat_2 >> porch_2 >> floor_2;

    auto [porch_1, floor_1] = Ambulance(flat_1, numFloors, flat_2, porch_2, floor_2);
    cout << porch_1 << ' ' << floor_1 << endl;

    return EXIT_SUCCESS;
}