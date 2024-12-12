#ifndef VERTEX_H
#define VERTEX_H
#include <string>
using namespace std;

class Vertex {
public:
    Vertex(string nodeName);
    string getLabel() const;
    void setLabel(string nodeName);

private:
    string nodeLabel;
};

#endif // VERTEX_H

