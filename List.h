#pragma once
#include "Node.h"

class List {
public:
    Node* head;
    int size;
    Node* pos;

    // Constructor
    List();

    // Add a new node with the given data to the front of the list
    void add_front(Edge data);

    // Add a new node with the given data to the end of the list
    void add_end(Edge data);

    // Remove the node at the front of the list and return its data
    Edge remove_front();

    // Remove the node at the end of the list and return its data
    Edge remove_end();
};
