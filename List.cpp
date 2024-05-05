#include "List.h"


List::List() {
    head = nullptr;
    size = 0;
    pos = head;
}
void List::add_front(Edge data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
    pos = head;
    size++;
}
void List::add_end(Edge data) {
    Node* node = new Node(data);

    if (head == nullptr) {
        head = node;
        pos = head;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
    }

    size++;
}
Edge List::remove_front() {
    if (head == nullptr) {
        cout << "Error: list is empty." << endl;
        exit(1);
    }

    Node* node = head;
    Edge data = node->data;
    head = node->next;
    delete node;
    size--;

    return data;
}
Edge List::remove_end() {
    if (head == nullptr) {
        cout << "Error: list is empty." << endl;
        exit(1);
    }

    Edge data;
    Node* current = head;
    if (current->next == nullptr) {
        data = current->data;
        head = nullptr;
        delete current;
    }
    else {
        while (current->next->next != nullptr) {
            current = current->next;
        }
        data = current->next->data;
        delete current->next;
        current->next = nullptr;
    }

    size--;
    return data;
}