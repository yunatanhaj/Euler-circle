#pragma once
#include<iostream>
using namespace std;

struct Edge {
    int dest;
    bool used;

};
class Node {
public:
    Edge data;
    Node* next;

    // Constructor
    Node(Edge data);
};
