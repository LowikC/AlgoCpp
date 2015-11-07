#ifndef bst_hpp
#define bst_hpp

#include <vector>

class BST {
public:
    BST();

    void insert(const int x);

    bool contains(const int x) const;

    int min() const;

    int max() const;

    int floor(int x) const;

    int size() const;

    void inOrder(std::vector<int>& values) const;

private:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node(int key, Node* left = nullptr, Node* right = nullptr):
            key(key), left(left), right(right)
        {}
    };
    static Node* insert(Node* root, const int x);
    static bool contains(BST::Node* root, const int x);
    static void pushInOrder(const BST::Node* root, std::vector<int>& stack);
    static BST::Node* floor(BST::Node* root, int x);

    Node* _root;
    int _size;
};


#endif