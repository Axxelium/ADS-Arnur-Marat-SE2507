#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void pushFront(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
    }

    void pushBack(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }

    bool remove(int val) {
        if (!head) return false;
        if (head->data == val) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return true;
        }
        Node* cur = head;
        while (cur->next && cur->next->data != val) cur = cur->next;
        if (!cur->next) return false;
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        return true;
    }

    bool search(int val) const {
        Node* cur = head;
        while (cur) {
            if (cur->data == val) return true;
            cur = cur->next;
        }
        return false;
    }

    void print() const {
        Node* cur = head;
        while (cur) {
            std::cout << cur->data;
            if (cur->next) std::cout << " -> ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
};

int main() {
    LinkedList list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushFront(0);

    std::cout << "List: ";
    list.print();

    std::cout << "Search 2: " << (list.search(2) ? "found" : "not found") << "\n";
    std::cout << "Search 5: " << (list.search(5) ? "found" : "not found") << "\n";

    list.remove(2);
    std::cout << "After removing 2: ";
    list.print();

    return 0;
}
