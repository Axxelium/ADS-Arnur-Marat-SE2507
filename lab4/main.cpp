#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)      node->left  = insert(node->left,  key);
        else if (key > node->key) node->right = insert(node->right, key);
        return node;
    }

    bool search(Node* node, int key) const {
        if (!node) return false;
        if (key == node->key) return true;
        return key < node->key ? search(node->left, key) : search(node->right, key);
    }

    Node* minNode(Node* node) const {
        while (node->left) node = node->left;
        return node;
    }

    Node* remove(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            if (!node->left) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            }
            if (!node->right) {
                Node* tmp = node->left;
                delete node;
                return tmp;
            }
            Node* successor = minNode(node->right);
            node->key = successor->key;
            node->right = remove(node->right, successor->key);
        }
        return node;
    }

    void inorder(Node* node) const {
        if (!node) return;
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }

    void preorder(Node* node) const {
        if (!node) return;
        std::cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    void insert(int key) { root = insert(root, key); }
    bool search(int key) const { return search(root, key); }
    void remove(int key) { root = remove(root, key); }
    void inorder()  const { inorder(root);  std::cout << "\n"; }
    void preorder() const { preorder(root); std::cout << "\n"; }
};

int main() {
    BST tree;
    for (int val : {5, 3, 7, 1, 4, 6, 8}) {
        tree.insert(val);
    }

    std::cout << "Inorder (sorted):  ";
    tree.inorder();

    std::cout << "Preorder:          ";
    tree.preorder();

    std::cout << "Search 4: " << (tree.search(4) ? "found" : "not found") << "\n";
    std::cout << "Search 9: " << (tree.search(9) ? "found" : "not found") << "\n";

    tree.remove(3);
    std::cout << "After removing 3 (inorder): ";
    tree.inorder();

    return 0;
}
