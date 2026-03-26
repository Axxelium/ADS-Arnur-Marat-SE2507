#include <iostream>
#include <stdexcept>

// Stack implemented using a linked list
template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* top_;
    int size_;

public:
    Stack() : top_(nullptr), size_(0) {}

    ~Stack() {
        while (top_) {
            Node* tmp = top_;
            top_ = top_->next;
            delete tmp;
        }
    }

    void push(T val) {
        Node* node = new Node(val);
        node->next = top_;
        top_ = node;
        ++size_;
    }

    T pop() {
        if (empty()) throw std::underflow_error("Stack is empty");
        T val = top_->data;
        Node* tmp = top_;
        top_ = top_->next;
        delete tmp;
        --size_;
        return val;
    }

    T peek() const {
        if (empty()) throw std::underflow_error("Stack is empty");
        return top_->data;
    }

    bool empty() const { return top_ == nullptr; }
    int size() const { return size_; }
};

// Queue implemented using a linked list
template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* front_;
    Node* back_;
    int size_;

public:
    Queue() : front_(nullptr), back_(nullptr), size_(0) {}

    ~Queue() {
        while (front_) {
            Node* tmp = front_;
            front_ = front_->next;
            delete tmp;
        }
    }

    void enqueue(T val) {
        Node* node = new Node(val);
        if (!back_) {
            front_ = back_ = node;
        } else {
            back_->next = node;
            back_ = node;
        }
        ++size_;
    }

    T dequeue() {
        if (empty()) throw std::underflow_error("Queue is empty");
        T val = front_->data;
        Node* tmp = front_;
        front_ = front_->next;
        if (!front_) back_ = nullptr;
        delete tmp;
        --size_;
        return val;
    }

    T frontVal() const {
        if (empty()) throw std::underflow_error("Queue is empty");
        return front_->data;
    }

    bool empty() const { return front_ == nullptr; }
    int size() const { return size_; }
};

int main() {
    // Stack demo
    Stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    std::cout << "Stack top: " << stk.peek() << "\n";
    std::cout << "Popping: ";
    while (!stk.empty()) {
        std::cout << stk.pop() << " ";
    }
    std::cout << "\n";

    // Queue demo
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Queue front: " << q.frontVal() << "\n";
    std::cout << "Dequeuing: ";
    while (!q.empty()) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << "\n";

    return 0;
}
