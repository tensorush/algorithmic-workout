#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class BinarySearchTree final {
public:
    BinarySearchTree() : _root(nullptr) {}
    auto getDepths() const {
        return _depths;
    }
    void insert(const int& value) {
        if (_root == nullptr) {
            _root = make_unique<Node>(value);
            _depths.emplace_back(1);
        } else {
            unsigned curDepth = 1;
            bool isDuplicate = true;
            Node* cur = _root.get();
            while (cur->_value != value) {
                if (value < cur->_value) {
                    if (cur->_left == nullptr) {
                        cur->_left = make_unique<Node>(value);
                        isDuplicate = false;
                    }
                    cur = cur->_left.get();
                } else {
                    if (cur->_right == nullptr) {
                        cur->_right = make_unique<Node>(value);
                        isDuplicate = false;
                    }
                    cur = cur->_right.get();
                }
                ++curDepth;
            }
            if (isDuplicate == false)
                _depths.emplace_back(curDepth);
        }
    }
private:
    struct Node {
    public:
        explicit Node(const int& value) : _value(value), _left(nullptr), _right(nullptr) {}
    private:
        int _value;
        unique_ptr<Node> _left;
        unique_ptr<Node> _right;
        friend class BinarySearchTree;
    };
    unique_ptr<Node> _root;
    vector<unsigned> _depths;
};


int main() {
    int element;
    BinarySearchTree tree;
    while (cin >> element && element != 0) {
        tree.insert(element);
    }

    auto depths = tree.getDepths();
    for (const unsigned& depth : depths) {
        cout << depth << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}