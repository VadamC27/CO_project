#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>

class Graph{
    int size;
public:
    std::vector<std::vector<int>> graph;
    void showMatrix();
    Graph(int s);
};


#endif