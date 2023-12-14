#include <iostream>
#include <memory>
#include <queue>

using namespace std;


class BinarySearchTree final {
public:
    BinarySearchTree() : _root(nullptr) {}
    unsigned getHeight() const {
        queue<Node*> q;
        q.emplace(_root.get());
        unsigned curLevelNodeCount, height = 0;
        while (true) {
            curLevelNodeCount = q.size();
            if (curLevelNodeCount == 0)
                return height;
            ++height;
            while (curLevelNodeCount > 0) {
                Node* cur = q.front();
                q.pop();
                if (cur->_left != nullptr)
                    q.emplace(cur->_left.get());
                if (cur->_right != nullptr)
                    q.emplace(cur->_right.get());
                --curLevelNodeCount;
            }
        }
        return height;
    }
    void insert(const int& value) {
        if (_root == nullptr) {
            _root = make_unique<Node>(value);
        } else {
            Node* cur = _root.get();
            while (cur->_value != value) {
                if (value < cur->_value) {
                    if (cur->_left == nullptr)
                        cur->_left = make_unique<Node>(value);
                    cur = cur->_left.get();
                } else if (value > cur->_value) {
                    if (cur->_right == nullptr)
                        cur->_right = make_unique<Node>(value);
                    cur = cur->_right.get();
                }
            }
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
};


int main() {
    int element;
    BinarySearchTree tree;
    while (cin >> element && element != 0) {
        tree.insert(element);
    }

    cout << tree.getHeight() << endl;

    return EXIT_SUCCESS;
}