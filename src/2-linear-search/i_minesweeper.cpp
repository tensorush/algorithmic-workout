#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    int numRows, numColumns, numMines;
    cin >> numRows >> numColumns >> numMines;

    int mineRow, mineColumn, rowRange, columnRange;
    vector<vector<int>> field(numRows, vector<int>(numColumns));
    for (int k = 0; k < numMines; ++k) {
        cin >> mineRow >> mineColumn;
        --mineRow;
        --mineColumn;
        rowRange = min(numRows, mineRow + 2);
        columnRange = min(numColumns, mineColumn + 2);
        for (int i = max(0, mineRow - 1); i < rowRange; ++i) {
            for (int j = max(0, mineColumn - 1); j < columnRange; ++j) {
                ++field[i][j];
            }
        }
        field[mineRow][mineColumn] = -9;
    }

    for (const auto& row : field) {
        for (const int& value : row) {
            if (value < 0)
                cout << '*' << ' ';
            else
                cout << value << ' ';
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}