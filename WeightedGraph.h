#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <vector>
#include "Vertex.h"
using namespace std;

class WeightedGraph {
public:
    WeightedGraph(int);
    bool isEmpty();
    void addNode(Vertex*);
    void addConnection(int, int, int);
    bool isFull();
    void DFS(Vertex*);
    void BFS(Vertex*);
    bool findRoute(Vertex* source, Vertex* destination, vector<string>& route, int& totalWeight);
    Vertex* getNodeByName(const string& name); // Helper function

private:
    static const int NO_EDGE = 0;
    int vertexCount;
    int maxVertices;
    vector<Vertex*> nodes;
    vector<vector<int>> adjacencyMatrix;
    vector<bool> visited;

    int findNodeIndex(Vertex*);
    void resetVisited();
    void performDFS(Vertex*);  // Declaration only
    void performBFS(Vertex*);  // Declaration only
};

#endif // WEIGHTEDGRAPH_H


