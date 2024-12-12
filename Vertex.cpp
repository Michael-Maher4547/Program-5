#include "Vertex.h"

Vertex::Vertex(string nodeName) {
    nodeLabel = nodeName;
}

string Vertex::getLabel() const {
    return nodeLabel;
}

void Vertex::setLabel(string nodeName) {
    nodeLabel = nodeName;
}

