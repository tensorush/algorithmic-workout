#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

template <typename T>
void PrintContainer(const T& container)
{
    cout << container.size() << endl;
    for (const auto& element : container) {
        cout << element << endl;
    }
}

int main()
{
    unsigned numPupils;
    cin >> numPupils;

    string lang;
    unsigned numLangs;
    unordered_set<string> allLangs, commonLangs;
    for (cin >> numLangs; numLangs > 0; --numLangs) {
        cin >> lang;
        allLangs.emplace(lang);
        commonLangs.emplace(lang);
    }

    for (unsigned i = 1; i < numPupils; ++i) {
        unordered_set<string> langs;
        for (cin >> numLangs; numLangs > 0; --numLangs) {
            cin >> lang;
            commonLangs.emplace(lang);
            if (allLangs.find(lang) != allLangs.end())
                langs.emplace(lang);
        }
        allLangs = std::move(langs);
    }

    PrintContainer(allLangs);
    PrintContainer(commonLangs);

    return EXIT_SUCCESS;
}
