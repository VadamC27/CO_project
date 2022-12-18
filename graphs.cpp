#include "graphs.h"
#include <vector>
#include <array>
#include <iostream>
#include <ctime>
#include <stdlib.h>

Graph::Graph(int s){
    size = s;
    for(int i = 0; i<size; i++){
        std::vector<int> row;
        for(int j = 0; j<size; j++){
            row.push_back(0);
        }
        graph.push_back(row);
    }
    longestCycleSize = 0;
    return;
}

void Graph::showMatrix() {
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            std::cout<<graph[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return;
}

void Graph::generateInput(){

    int a;
    std::vector<int> v;
    for(int i =0; i<size;i++){
        for(int j =0; j<size;j++){
            do{
                std::cout<<"Podaj wartosc (1 lub 0) dla pozycji ["<<i<<"]["<<j<<"]: "; 
                std::cin>>a;
            }while(!(a==0 || a==1));
            v.push_back(a);
        }
        graph[i].assign(v.begin(),v.end());
        v.clear();
    }
}

void Graph::generateRing(){
    int position;
    for(int i = 0; i< size;i++){
        position = (i+1)%size;
        graph[i][position] = 1;
    }
    return;
}

void Graph::generateRing(int offset){
    int position;
    for(int i = 0; i< size;i++){
        position = (i+offset)%size;
        graph[i][position] = 1;
    }
    return;
}

void Graph::generateRandomEdges(float _saturation){
        
    int counter = 0, currentRowIndex, fill;
    int saturation =  ((size * (size - 1)/2)* _saturation);
    while(counter < saturation){
        for(int i = 0; i < size; i++){
            for(int j = 0; j <size; j++){
                fill = rand()%2;
                if(fill && i!=j && !graph[i][j] ) {
                    graph[i][j] = 1;
                    counter++;
                }
            }
        }
    }
    return;
}

void Graph::dfsLongestCycle(int v, int * visited,  std::vector<int>& current){
    visited[v] =1;
    current.push_back(v);    
    for(int i = 0; i<size; i++){
        if(graph[v][i] == 1  ){
            if(i == current[0]&&current.size() > longestCycleSize){
                current.push_back(i);
                longestCycleSize = current.size();
                longestCycle.clear();
                longestCycle.assign(current.begin(), current.end());
                break;
            }
            if( visited[i] == 0) dfsLongestCycle(i,visited,current);
        }
    }
    current.pop_back();
    return;
}

void Graph::findLongestCycle(){
    int visited[size];
    for(int i = 0; i<size; i++) visited[i] = 0;
    std::vector<int> current;
    
    for(int i = 0; i<size; i++){
        dfsLongestCycle(i, visited, current);
        current.clear();
    }

    std::cout<<"The longest cycle: ";
    for(int i = 0; i<longestCycle.size();i++){
        std::cout<<longestCycle[i]<<" ";
    }
     std::cout<<"\n\n";
    return;
}

bool Graph::dfsCheckCyclic(int v, int * visited,  std::vector<int>& current){
    visited[v] =1;
    current.push_back(v);
    
    for(int i = 0; i<size; i++){
        
        if(graph[v][i] == 1  ){
            if(i == current[0]){
                current.push_back(i);
                std::cout<<"Cycle found!: ";
                for (const auto& element : current)
                {
                    std::cout << element << " ";
                }
                return 1;
            }
           
            if( visited[i] == 0) {
                if(dfsCheckCyclic(i,visited,current))return true;
            }

        }
    }
    current.pop_back();
    return false;
}



void Graph::findAnyCycle(){
    int visited[size];
    for(int i = 0; i<size; i++) visited[i] = 0;
    std::vector<int> current;
    
    for(int i = 0; i<size; i++){
        if(dfsCheckCyclic(i, visited, current)) return;
        current.clear();
    }
    std::cout<<"\nGiven graph is acyclic.\n\n";
    return;
}



int Graph::getSize(){return size;}