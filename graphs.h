#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>

class Graph{
    int size;
    int longestCycleSize;
    std::vector<int> longestCycle;    
    bool dfsCheckCyclic(int v, int * visited,  std::vector<int>& current);    
    bool dfsExactCycle(int v, int * visited,  std::vector<int>& current, int length, std::vector<int>& exactCycle);
    void dfsLongestCycle(int v, int * visited,  std::vector<int>& current);

public:
    std::vector<std::vector<int>> graph;
    
    //functions    
    bool findAnyCycle();
    bool findExactCycle(int a);
    bool findLongestCycle();
    void generateAcyclicGraph(float _saturation);
    void generateInput();
    void generateRandomEdges(float _saturation);          
    void generateRing();
    void generateRing(int offset);   
    void showMatrix();    
    
    int getSize();
     
    Graph(int s);
};

#endif