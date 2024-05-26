#include <iostream>
using namespace std;

class Node {
public:
    double data;
    Node* next;

    Node(double data) {
        this->data = data;
        this->next = NULL;
    }
};

class OneLinkedList {
public:
    Node* head, * tail;

    OneLinkedList() {
        this->head = this->tail = NULL;
    }

    ~OneLinkedList() {
        while (head != NULL) {
            pop_front();
        }
    }

    void pop_front() {
        if (head == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node* node = head;
        head = node->next;
        delete node;
    }

    void push_front(double data) {
        Node* node = new Node(data);
        node->next = head;
        head = node;
        if (tail == NULL) tail = node;
    }

    void push_back(double data) {
        Node* node = new Node(data);
        if (head == NULL) head = node;
        if (tail != NULL) tail->next = node;
        tail = node;
    }

    void pop_back() {
        if (tail == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node* node = head;
        while (node->next != tail) {
            node = node->next;
        }
        delete tail;
        tail = node;
        tail->next = NULL;
    }

    Node* getAt(int k) {
        if (k < 0) return NULL;
        Node* node = head;
        int n = 0;
        while (node && n != k && node->next) {
            node = node->next;
            n++;
        }
        if (n == k) return node;
        else return NULL;
    }

    void insert(int k, double data) {
        Node* left = getAt(k);
        if (left == NULL) return;

        Node* right = left->next;
        Node* node = new Node(data);

        left->next = node;
        node->next = right;
        if (right == NULL) tail = node;
    }

    void erase(int k) {
        if (k < 0) return;
        if (k == 0) {
            pop_front();
            return;
        }   
        Node* left = getAt(k - 1);
        Node* node = left->next;
        if (node == NULL) return;
        Node* right = node->next;

        left->next = right;
        if (node == tail) tail = left;
        delete node;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    OneLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.display();

    return 0;
}