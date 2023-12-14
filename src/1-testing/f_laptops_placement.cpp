#include <iostream>

using namespace std;


int main() {
    unsigned width_1, length_1, width_2, length_2;
    cin >> width_1 >> length_1 >> width_2 >> length_2;

    unsigned longSide_1 = (width_1 > length_1) ? (width_1) : (length_1),
        shortSide_1 = (longSide_1 == length_1) ? (width_1) : (length_1),

        longSide_2 = (width_2 > length_2) ? (width_2) : (length_2),
        shortSide_2 = (longSide_2 == length_2) ? (width_2) : (length_2),

        longestSide = (longSide_1 > longSide_2) ? (longSide_1) : (longSide_2),
        shorterSide = (longestSide == longSide_2) ? (longSide_1) : (longSide_2),

        shortestSide = (shortSide_1 < shortSide_2) ? (shortSide_1) : (shortSide_2),
        longerSide = (shortestSide == shortSide_2) ? (shortSide_1) : (shortSide_2),

        longTableSide_1 = longestSide,
        shortTableSide_1 = shortSide_1 + shortSide_2,
        tableArea_1 = longTableSide_1 * shortTableSide_1,

        longTableSide_2 = longestSide + shortestSide,
        shortTableSide_2 = (shorterSide > longerSide) ? (shorterSide) : (longerSide),
        tableArea_2 = longTableSide_2 * shortTableSide_2;

    if (tableArea_1 < tableArea_2)
        cout << longTableSide_1 << ' ' << shortTableSide_1 << endl;
    else
        cout << longTableSide_2 << ' ' << shortTableSide_2 << endl;

    return EXIT_SUCCESS;
}