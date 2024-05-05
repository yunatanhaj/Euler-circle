#include <stdio.h>
#include "Graph.h"



int main()
{
    int numberofvetices,numberofedges, v1, v2;
    char directed;
    
        cout << "Is the graph directed: y/n" << endl;
        cin >> directed;
        if (!(directed == 'y' || directed == 'n'))
        {
            cout << "invalid input";
            return 0;
         }
    cin >> numberofvetices;
    if (numberofvetices < 1) {
        cout << "invalid input";
        return 0;
    }
    Graph G = { numberofvetices,directed };
    cin >> numberofedges;
    if (numberofedges < 0 || (directed == 'n' && numberofedges > ((numberofvetices) * (numberofvetices - 1)) / 2) || (directed == 'y' && numberofedges > (numberofvetices) * (numberofvetices - 1)))
    {
        cout << "invalid input";
        return 0;

    }
    for (int i = 0; i < numberofedges; i++)
    {
        cin >> v1 >> v2;
        if (v1<1 || v1>numberofvetices || v2<1 || v2>numberofvetices)
        {
            cout << "invalid input";
            return 0;
        }
        G.addEdge(v1-1, v2-1);
    }
    G.printEulerianCycle();
    G.freeData();
    return 0;
   // G.printEuler();
}