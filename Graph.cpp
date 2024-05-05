#include "Graph.h"


 Graph::Graph(int n,char directed){
     numVertices = n;
     directedGraph = directed;
     adjList.resize(n);
    }

 void Graph::addEdge(int u, int v)
 {
     Edge e = { v,false };
     Edge e1 = { u,false };
     if (directedGraph == 'y' || directedGraph == 'n')//adding edge for Directed and non_Directed graph
         adjList[u].add_end(e);
     if (directedGraph == 'n')//adding edge for non_Directed graph
         adjList[v].add_end(e1);

 }
 bool Graph::checkEulerian()
 {
     if (directedGraph == 'n')
     {
         //checking if all the degrees is even
         int oddCount = 0;
         for (int i = 0; i < numVertices; i++) {
             if (adjList[i].size % 2 == 1) {
                 return false;
             }
         }
         //check if the graph connected
         vector<bool> visited(numVertices, false);
         queue<int> q;
         q.push(0);
         visited[0] = true;
         int numVisited = 1;
         while (!q.empty()) {
             int u = q.front();
             q.pop();
             for (Node* i = adjList[u].head; i !=nullptr;i=i->next) {
                 if (!visited[i->data.dest]) {
                     visited[i->data.dest] = true;
                     q.push(i->data.dest);
                     numVisited++;
                 }
             }
           //  adjList[u].pos = adjList[u].head;
         }
         return numVisited == numVertices;


     }
     else {
       
         int *inDegree= new int[this->numVertices];
         int *outDegree = new int[numVertices];
         for (int i = 0; i < numVertices; i++)
         {
             inDegree[i] = 0;
             outDegree[i] = 0;
         }
         for (int u = 0; u < numVertices; u++) {
 
             for (Node* i = adjList[u].head; i != nullptr; i = i->next) {
                 outDegree[u]++;
                 inDegree[i->data.dest]++;
             }
            // adjList[u].pos = adjList[u].head;

         }
         for (int i = 0; i < numVertices; i++)
         {
             if (outDegree[i] != inDegree[i])return false;
         }
         delete []inDegree;
         delete[]outDegree;
         return isStronglyconnected();
     
     
     
     }
}
 bool Graph::isStronglyconnected()
 {
     vector<bool> visited(numVertices, false);

     // Perform a DFS traversal starting from vertex 0
     DFS(0, visited);

     // If any vertex is not visited, then the graph is not strongly connected
     if (find(visited.begin(), visited.end(), false) != visited.end()) {
         return false;
     }

     // Reset the visited array
     visited.assign(numVertices, false);

     // Reverse the direction of the edges in the adjacency list
     vector<vector<int>> revAdjList(numVertices);
     for (int u = 0; u < numVertices; u++) {
         for (Node* i = adjList[u].head; i != nullptr; i = i->next) {
             revAdjList[i->data.dest].push_back(u);
         }
         //adjList[u].pos = adjList[u].head;
     }

     // Perform a DFS traversal starting from vertex 0, but in reverse direction
     DFSReverse(0, revAdjList, visited);

     // If any vertex is not visited, then the graph is not strongly connected
     if (find(visited.begin(), visited.end(), false) != visited.end()) {
         return false;
     }

     // If we reach here, then the graph is strongly connected
     return true;
 }
 void Graph::DFS(int u, vector<bool>& visited)
 {
     visited[u] = true;
     for (Node* i = adjList[u].head; i != nullptr; i = i->next) {
         if (!visited[i->data.dest]) {
             DFS(i->data.dest, visited);
         }
     }
 }
 void Graph::DFSReverse(int u, vector<vector<int>>& revAdjList, vector<bool>& visited)
 {
     visited[u] = true;
     for (int v : revAdjList[u]) {
         if (!visited[v]) {
             DFSReverse(v, revAdjList, visited);
         }
     }
 }
 void Graph::printEulerianCycle() {
     if (!checkEulerian()) {
         cout << "The graph is not aulerian" << endl;
         return;
     }
     else cout << "The graph is aulerian" << endl;
      printEuler();
 }


 vector<int> Graph::findcircuit(int v0)
 {
     int v = v0,size = this->adjList[v0].size;
     int i = 0;
     vector<int> L;
     L.push_back(v0);
    
      //  while (adjList[v].pos!=nullptr&&adjList[v].pos->data.used == true)
            //    adjList[v].pos=adjList[v].pos->next;
       
     while (adjList[v].pos != nullptr)
     {
         if (!adjList[v].pos->data.used)
         {
             int u = adjList[v].pos->data.dest;
             L.push_back(u);
             adjList[v].pos->data.used = true;
             if (directedGraph == 'n')
             {
                 Node* curr = adjList[adjList[v].pos->data.dest].head;
                 while (curr->data.dest != v)
                 {
                     curr = curr->next;
                 }
                 curr->data.used = true;
             }
             adjList[v].pos = adjList[v].pos->next;

             v = u;
         }
         else  adjList[v].pos = adjList[v].pos->next;
      }
     return L;
 }
 void Graph::printEuler()
 {
     vector<int> L = findcircuit(0);
     vector<int> L1;
     int i = 0,size=L.size();
     while (i < size)
     {

         while (adjList[L[i]].pos != nullptr)
         {
             while (adjList[L[i]].pos != nullptr && adjList[L[i]].pos->data.used == true)
             {
                 adjList[L[i]].pos = adjList[L[i]].pos->next;
             }
             if (adjList[L[i]].pos != nullptr)
             {
                 int v = L[i];
                 L1 = findcircuit(v);
                 L.erase(L.begin() + i);
                 L.insert(L.begin() + i, L1.begin(), L1.end());
             }
         }

            i++;
         size = L.size();
     }
     cout << "(";
     for (int j = 0; j < L.size() - 1; j++)
         cout << L[j] + 1 <<",";
     cout << L[L.size() - 1] + 1 << ")" << endl;
 }
 void Graph::freeData()
 {
     for (int i = 0; i < numVertices; i++)
     {
         Node* curr=adjList[i].head;
         Node* temp;
        
         while (curr != nullptr)
         {
             temp = curr;
             curr = curr->next;
             delete temp;

         }

     }


 }
 
 