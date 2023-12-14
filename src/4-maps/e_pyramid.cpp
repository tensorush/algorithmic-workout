#include <unordered_map>
#include <iostream>

using namespace std;


int main() {
    unsigned numBlocks;
    cin >> numBlocks;

    unsigned width, height;
    unordered_map<unsigned, unsigned> blocks;
    for (unsigned i = 0; i < numBlocks; ++i) {
        cin >> width >> height;
        if (height > blocks[width])
            blocks[width] = height;
    }

    long unsigned maxPyramidHeight = 0;
    for (const auto& [width, height] : blocks) {
        maxPyramidHeight += height;
    }
    cout << maxPyramidHeight << endl;

    return EXIT_SUCCESS;
}