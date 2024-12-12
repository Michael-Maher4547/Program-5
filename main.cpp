#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"
using namespace std;

int main() {
    WeightedGraph graph(10);

    Vertex* startNode = new Vertex("A");
    graph.addNode(startNode);
    graph.addNode(new Vertex("B"));
    graph.addNode(new Vertex("C"));
    graph.addNode(new Vertex("D"));
    graph.addNode(new Vertex("E"));

    graph.addConnection(0, 1, 12);
    graph.addConnection(0, 2, 17);
    graph.addConnection(0, 4, 22);
    graph.addConnection(1, 3, 9);
    graph.addConnection(1, 2, 6);
    graph.addConnection(3, 4, 1);

    cout << "Depth-First Search (DFS): ";
    graph.DFS(startNode);  // Corrected method call
    cout << endl;

    cout << "Breadth-First Search (BFS): ";
    graph.BFS(startNode);  // Corrected method call
    cout << endl;

    cout << "Testing route finding between nodes:" << endl;
    vector<string> route;
    int totalWeight = 0;

    Vertex* source = graph.getNodeByName("A");
    Vertex* destination = graph.getNodeByName("D");

    if (graph.findRoute(source, destination, route, totalWeight)) {
        cout << "Route found from " << source->getLabel() << " to " << destination->getLabel() << ": ";
        for (const auto& step : route) {
            cout << step << " ";
        }
        cout << "\nTotal route weight: " << totalWeight << endl;
    } else {
        cout << "No route exists between the nodes." << endl;
    }

    return 0;
}

