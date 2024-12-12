#include "WeightedGraph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

WeightedGraph::WeightedGraph(int capacity) {
    vertexCount = 0;
    maxVertices = capacity;
    nodes.resize(capacity);
    for (int i = 0; i < capacity; i++) {
        nodes[i] = nullptr;
    }
    visited.resize(capacity);
    adjacencyMatrix.resize(capacity, vector<int>(capacity, NO_EDGE));
}

void WeightedGraph::addNode(Vertex* newNode) {
    nodes[vertexCount] = newNode;
    for (int i = 0; i < maxVertices; i++) {
        adjacencyMatrix[vertexCount][i] = NO_EDGE;
        adjacencyMatrix[i][vertexCount] = NO_EDGE;
    }
    vertexCount++;
}

void WeightedGraph::addConnection(int fromIndex, int toIndex, int weight) {
    int row = findNodeIndex(nodes[fromIndex]);
    int column = findNodeIndex(nodes[toIndex]);
    adjacencyMatrix[row][column] = weight;
}

int WeightedGraph::findNodeIndex(Vertex* node) const {
    for (int i = 0; i < vertexCount; i++) {
        if (nodes[i] == node) {
            return i;
        }
    }
    return -1;
}

void WeightedGraph::resetVisited() {
    fill(visited.begin(), visited.end(), false);
}

void WeightedGraph::performDFS(Vertex* startNode) {
    if (!startNode) return;
    cout << startNode->getLabel() << " ";
    int index = findNodeIndex(startNode);
    visited[index] = true;

    for (int i = 0; i < vertexCount; i++) {
        if (adjacencyMatrix[index][i] != NO_EDGE && !visited[i]) {
            performDFS(nodes[i]);
        }
    }
}

void WeightedGraph::DFS(Vertex* startNode) {
    resetVisited();
    performDFS(startNode);
}

void WeightedGraph::performBFS(Vertex* startNode) {
    if (!startNode) return;
    queue<Vertex*> q;
    int index = findNodeIndex(startNode);
    visited[index] = true;
    q.push(startNode);

    while (!q.empty()) {
        Vertex* current = q.front();
        q.pop();
        cout << current->getLabel() << " ";
        index = findNodeIndex(current);

        for (int i = 0; i < vertexCount; i++) {
            if (adjacencyMatrix[index][i] != NO_EDGE && !visited[i]) {
                visited[i] = true;
                q.push(nodes[i]);
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* startNode) {
    resetVisited();
    performBFS(startNode);
}

bool WeightedGraph::findRoute(Vertex* start, Vertex* end, vector<string>& route, int& totalWeight) {
    resetVisited();
    stack<pair<Vertex*, int>> s;
    s.push({start, 0});
    int startIdx = findNodeIndex(start);
    int endIdx = findNodeIndex(end);

    if (startIdx == -1 || endIdx == -1) {
        cout << "Start or end vertex not found." << endl;
        return false;
    }

    while (!s.empty()) {
        auto [current, currentWeight] = s.top();
        s.pop();
        int currentIndex = findNodeIndex(current);

        if (visited[currentIndex]) continue;

        visited[currentIndex] = true;
        route.push_back(current->getLabel());
        totalWeight = currentWeight;

        if (current == end) {
            return true;
        }

        for (int i = 0; i < vertexCount; i++) {
            if (adjacencyMatrix[currentIndex][i] != NO_EDGE && !visited[i]) {
                s.push({nodes[i], currentWeight + adjacencyMatrix[currentIndex][i]});
            }
        }
        if (route.back() != end->getLabel()) {
            route.pop_back();
        }
    }

    cout << "No route exists between " << start->getLabel() << " and " << end->getLabel() << "." << endl;
    return false;
}

Vertex* WeightedGraph::getNodeByName(const string& nodeName) const {
    for (auto node : nodes) {
        if (node && node->getLabel() == nodeName) {
            return node;
        }
    }
    return nullptr;
}

