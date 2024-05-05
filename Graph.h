#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include "List.h"
using namespace std;

// Edge struct to represent a weighted edge in the graph


// Graph class to represent the graph using adjacency list
class Graph {
private:
    int numVertices; // number of vertices in the graph
    char directedGraph;
    vector<List> adjList; // adjacency list to store edges connected to each vertex

public:
    // Constructor to create a graph with n vertices
    Graph(int n,char directed);

    // Add edge between vertices u and v with weight w
    void addEdge(int u, int v);
    //init the graph with the data that the user type
    bool checkEulerian();
    bool isStronglyconnected();// Check if the graph is strongly connected
    void DFS(int u, vector<bool>& visited);// Helper function to perform DFS traversal from a vertex u
    void DFSReverse(int u, vector<vector<int>>& revAdjList, vector<bool>& visited); // Helper function to perform DFS traversal from a vertex u, but in reverse direction
    void printEulerianCycle();// Check if the graph has an Eulerian cycle and print it
   // bool hasEulerianCycleFromVertex(int u);
    vector<int> findcircuit(int v0);
    void printEuler();
    void freeData();
};

