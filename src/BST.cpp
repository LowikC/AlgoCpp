#include "BST.hpp"
#include <stdexcept>

BST::BST() :
_root(nullptr),
_size(0)
{}

BST::Node* BST::insert(BST::Node* root, const int x) {
    if (root == nullptr) {
        return new Node(x);
    }
    else {
        if (x < root->key) {
            root->left = insert(root->left, x);
        }
        else {
            root->right = insert(root->right, x);
        }
        return root;
    }
}
void BST::insert(const int x) {
    _root = insert(_root, x);
    _size++;
}

bool BST::contains(BST::Node* root, const int x) {
    if (root == nullptr) return false;
    if (root->key == x) return true;
    if (root->key < x) return contains(root->right, x);
    return contains(root->left, x);
}

bool BST::contains(const int x) const {
    return contains(_root, x);
}

int BST::min() const {
    if (_root == nullptr) throw std::underflow_error("Empty BST");
    Node* current = _root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->key;
}

int BST::max() const {
    if (_root == nullptr) throw std::underflow_error("Empty BST");
    Node* current = _root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->key;
}

void BST::pushInOrder(const BST::Node* root, std::vector<int>& stack) {
    if (root == nullptr) return;
    pushInOrder(root->left, stack);
    stack.push_back(root->key);
    pushInOrder(root->right, stack);
}
void BST::inOrder(std::vector<int>& values) const {
    values.clear();
    pushInOrder(_root, values);
}

BST::Node* BST::floor(BST::Node* root, int x) {
    if (root == nullptr) return nullptr;

    if (root->key == x) return root;
    if (root->key > x) return floor(root->left, x);
    
    Node* fl = floor(root->right, x);
    if (fl == nullptr) return root;
    return fl;
}

int BST::floor(int x) const {
    Node* fl = floor(_root, x);
    if (fl == nullptr) throw std::range_error("No floor");
    return fl->key;
}

int BST::size() const {
    return _size;
}