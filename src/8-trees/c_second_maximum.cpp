#include <iostream>
#include <memory>

using namespace std;


class BinarySearchTree final {
public:
    BinarySearchTree() : _root(nullptr) {}
    int getSecondMaximum() const {
        Node* cur = _root.get();
        if (cur->_right == nullptr) {
            cur = cur->_left.get();
            while (cur->_right != nullptr) {
                cur = cur->_right.get();
            }
        } else {
            while (cur->_right->_right != nullptr) {
                cur = cur->_right.get();
            }
            if (cur->_right->_left != nullptr) {
                cur = cur->_right->_left.get();
                while (cur->_right != nullptr) {
                    cur = cur->_right.get();
                }
            }
        }
        return cur->_value;
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

    cout << tree.getSecondMaximum() << endl;

    return EXIT_SUCCESS;
}