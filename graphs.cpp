#include "graphs.h"
#include <vector>
#include <iostream>

Graph::Graph(int s){
    size = s;
    for(int i = 0; i<size; i++){
        std::vector<int> row;
        for(int j = 0; j<size; j++){
            row.push_back(0);
        }
        graph.push_back(row);
    }
}

void Graph::showMatrix() {
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            std::cout<<graph[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}
