#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;


class BinarySearchTree final {
public:
    BinarySearchTree() : _root(nullptr) {}
    bool isAVLBalanced() const {
        // Traverse Post-Order
        stack<Node*> s;
        Node* cur = _root.get();
        bool isAVLBalanced = true;
        int leftSubtreeHeight, rightSubtreeHeight;
        while (isAVLBalanced) {
            while (cur != nullptr) {
                s.emplace(cur);
                s.emplace(cur);
                cur = cur->_left.get();
            }
            if (s.empty())
                break;
            cur = s.top();
            s.pop();
            if (s.empty() == false && s.top() == cur) {
                cur = cur->_right.get();
            } else {
                // Check AVL Balance Condition
                if (cur->_left != nullptr || cur->_right != nullptr) {
                    leftSubtreeHeight = rightSubtreeHeight = 0;
                    if (cur->_left != nullptr)
                        leftSubtreeHeight = getHeight(cur->_left.get());
                    if (cur->_right != nullptr)
                        rightSubtreeHeight = getHeight(cur->_right.get());
                    if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1)
                        isAVLBalanced = false;
                }
                cur = nullptr;
            }
        }
        return isAVLBalanced;
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
    unsigned getHeight(Node* cur) const {
        queue<Node*> q;
        q.emplace(cur);
        unsigned curLevelNodeCount, height = 0;
        while (true) {
            curLevelNodeCount = q.size();
            if (curLevelNodeCount == 0)
                break;
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
};


int main() {
    int element;
    BinarySearchTree tree;
    while (cin >> element && element != 0) {
        tree.insert(element);
    }

    cout << (tree.isAVLBalanced() ? ("YES") : ("NO")) << endl;

    return EXIT_SUCCESS;
}