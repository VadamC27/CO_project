#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>

class Graph{
    int size;
    int longestCycleSize;
    std::vector<int> longestCycle;    
    bool dfsCheckCyclic(int v, int * visited,  std::vector<int>& current);
    void dfsLongestCycle(int v, int * visited,  std::vector<int>& current);

public:
    std::vector<std::vector<int>> graph;
    
    //functions
    void findLongestCycle();
    void findAnyCycle();
    void generateInput();       
    void generateRing();
    void generateRing(int offset);
    void generateRandomEdges(float _saturation);      
    void showMatrix();    
    
    int getSize();
     
    Graph(int s);
};

#endif