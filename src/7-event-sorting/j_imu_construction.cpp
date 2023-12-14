#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using Block = tuple<unsigned, unsigned, unsigned>;
using BlockBase = tuple<unsigned, bool, unsigned>;


enum BlockBaseType {
    Top = 0,
    Bottom = 1
};


int main() {
    unsigned numBlocks, width, length;
    cin >> numBlocks >> width >> length;

    unsigned x_1, y_1, x_2, y_2;
    vector<Block> blocks(numBlocks);
    for (auto& [z_1, z_2, baseArea] : blocks) {
        cin >> x_1 >> y_1 >> z_1 >> x_2 >> y_2 >> z_2;
        baseArea = (x_2 - x_1) * (y_2 - y_1);
    }

    vector<BlockBase> blockBases;
    for (const auto& [z_1, z_2, baseArea] : blocks) {
        blockBases.emplace_back(make_tuple(z_1, Bottom, baseArea));
        blockBases.emplace_back(make_tuple(z_2, Top, baseArea));
    }
    sort(blockBases.begin(), blockBases.end());

    unsigned blockCount = 0, area = width * length,
        minBlockSetZ = 0, minNumBlocks = numBlocks + 1;
    for (const auto& [z, type, baseArea] : blockBases) {
        if (type == Top) {
            --blockCount;
            area += baseArea;
        } else {
            ++blockCount;
            area -= baseArea;
            if (area == 0) {
                if (blockCount < minNumBlocks) {
                    minBlockSetZ = z;
                    minNumBlocks = blockCount;
                }
            }
        }
    }

    if (minNumBlocks > numBlocks) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl << minNumBlocks << endl;
        unsigned number = 1;
        for (const auto& [z_1, z_2, baseArea] : blocks) {
            if (z_1 <= minBlockSetZ && z_2 > minBlockSetZ)
                cout << number << ' ';
            ++number;
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}