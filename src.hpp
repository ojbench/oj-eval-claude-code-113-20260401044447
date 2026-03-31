#include <iostream>

using namespace std;

// Template LinkedList class
template <typename T>
class LinkedList {
protected:
    // Node structure for the linked list
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    // Default constructor
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    // Copy constructor
    LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), length(0) {
        Node* current = other.head;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }

    // Destructor
    virtual ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert element at the front
    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    // Insert element at the back
    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // Remove element from the front
    T popFront() {
        if (head == nullptr) {
            return T();  // Return default constructed value if empty
        }
        Node* temp = head;
        T value = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        length--;
        return value;
    }

    // Remove element from the back
    T popBack() {
        if (head == nullptr) {
            return T();  // Return default constructed value if empty
        }

        if (head == tail) {
            T value = head->data;
            delete head;
            head = tail = nullptr;
            length--;
            return value;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        T value = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
        length--;
        return value;
    }

    // Return the size of the list
    int size() const {
        return length;
    }

    // Print the list
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Virtual functions
    virtual const char* name() const {
        return "LinkedList";
    }

    virtual T peak() const {
        return T();
    }

    virtual T pop() {
        return T();
    }

    virtual void push(const T& value) {
    }
};

// Stack class - LIFO (Last In First Out)
template <typename T>
class Stack : public LinkedList<T> {
public:
    // Override virtual functions
    const char* name() const override {
        return "Stack";
    }

    T peak() const override {
        // Return the top element (head of the list)
        return this->head->data;
    }

    T pop() override {
        // Pop from the front (top of stack)
        return this->popFront();
    }

    void push(const T& value) override {
        // Push to the front (top of stack)
        this->pushFront(value);
    }
};

// Queue class - FIFO (First In First Out)
template <typename T>
class Queue : public LinkedList<T> {
public:
    // Override virtual functions
    const char* name() const override {
        return "Queue";
    }

    T peak() const override {
        // Return the front element (head of the list)
        return this->head->data;
    }

    T pop() override {
        // Pop from the front
        return this->popFront();
    }

    void push(const T& value) override {
        // Push to the back (end of queue)
        this->pushBack(value);
    }
};
