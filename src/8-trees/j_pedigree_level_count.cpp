#include <iostream>
#include <map>
#include <memory>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class FamilyTree final {
public:
    void traverseInOrderAndCountLevels() const
    {
        map<string, unsigned> _levels;
        stack<pair<Person*, unsigned>> s;
        s.emplace(make_pair(_ancestors.back().get(), 0));
        while (s.empty() == false) {
            auto [childData, childLevel] = s.top();
            ++childLevel;
            s.pop();
            for (const auto& child : childData->_children) {
                _levels[child->_name] = childLevel;
                if (child->_children.empty() == false)
                    s.emplace(make_pair(child.get(), childLevel));
            }
        }
        for (const auto& [name, data] : _people) {
            cout << name << ' ' << _levels[name] << endl;
        }
    }
    void insert(const string& child, const string& parent)
    {
        if (_people[parent] == nullptr) {
            unique_ptr<Person> parentNode = make_unique<Person>(parent);
            _people[parent] = parentNode.get();
            _ancestors.emplace_back(std::move(parentNode));
        }
        unique_ptr<Person> childNode = make_unique<Person>(child);
        if (_people[child] == nullptr) {
            _people[child] = childNode.get();
            _people[parent]->_children.emplace_back(std::move(childNode));
        } else {
            Person* childData = _people[child];
            unsigned i, numAncestors = _ancestors.size();
            for (i = 0; i < numAncestors; ++i) {
                if (_ancestors[i].get() == childData) {
                    _people[parent]->_children.emplace_back(std::move(_ancestors[i]));
                    break;
                }
            }
            _ancestors[i] = std::move(_ancestors.back());
            _ancestors.pop_back();
        }
    }

private:
    struct Person {
    public:
        explicit Person(const string& name)
            : _name(name)
        {
        }

    private:
        string _name;
        vector<unique_ptr<Person>> _children;
        friend class FamilyTree;
    };
    map<string, Person*> _people;
    vector<unique_ptr<Person>> _ancestors;
};

int main()
{
    unsigned numPeople;
    cin >> numPeople;

    string child, parent;
    FamilyTree pedigree;
    for (unsigned i = 1; i < numPeople; ++i) {
        cin >> child >> parent;
        pedigree.insert(child, parent);
    }

    pedigree.traverseInOrderAndCountLevels();

    return EXIT_SUCCESS;
}
