#include <iostream>
#include <memory>
#include <stack>

using namespace std;


class BinarySearchTree final {
public:
    BinarySearchTree() : _root(nullptr) {}
    void traverseForkNodesInOrder() const {
        stack<Node*> s;
        Node* cur = _root.get();
        while (cur != nullptr || s.empty() == false) {
            while (cur != nullptr) {
                s.emplace(cur);
                cur = cur->_left.get();
            }
            cur = s.top();
            s.pop();
            if (cur->_left != nullptr && cur->_right != nullptr)
                cout << cur->_value << endl;
            cur = cur->_right.get();
        }
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
                } else {
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

    tree.traverseForkNodesInOrder();

    return EXIT_SUCCESS;
}