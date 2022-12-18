#include "graphs.h"
#include <vector>
#include <array>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>

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

void Graph::generateAcyclicGraph(float _saturation){
    int counter = 0, currentRowIndex, fill;
    int saturation =  ((size * (size - 1)/2)* _saturation);
    while(counter < saturation){
        for(int i = 1; i < size; i++){
            for(int j = i+1; j <size; j++){
                fill = rand()%2;
                if(fill && i!=j && !graph[i][j] &&counter < saturation) {
                    graph[i][j] = 1;
                    counter++;
                }
            }
        }
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
                if(fill ==1 && i!=j && !graph[i][j] &&counter <= saturation) {
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
            if(i == current[0]&&current.size()>=3 &&current.size() > longestCycleSize){
                current.push_back(i);
                longestCycleSize = current.size()-1;
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

bool Graph::findLongestCycle(){
    int visited[size];
    for(int i = 0; i<size; i++) visited[i] = 0;
    std::vector<int> current;
    
    for(int i = 0; i<size; i++){
        dfsLongestCycle(i, visited, current);
        current.clear();
    }
    if(longestCycleSize<3){
        std::cout<<"\nGraph is acyclic!\n\n";
        return false;
    }
    std::cout<<"The longest cycle has length of "<< longestCycleSize<<".\n Cycle: ";
    for(int i = 0; i<longestCycle.size();i++){
        std::cout<<longestCycle[i]<<" ";
    }
    std::cout<<"\n\n";
    return true;
}

bool Graph::dfsCheckCyclic(int v, int * visited,  std::vector<int>& current){
    visited[v] =1;
    current.push_back(v);
    
    for(int i = 0; i<size; i++){
        
        if(graph[v][i] == 1  ){
            if(i == current[0]&&current.size()>=3){
                current.push_back(i);
                std::cout<<"Cycle found!: ";
                for (const auto& element : current)
                {
                    std::cout << element << " ";
                }
                return true;
            }
           
            if( visited[i] == 0) {
                if(dfsCheckCyclic(i,visited,current))return true;
            }

        }
    }
    current.pop_back();
    return false;
}



bool Graph::findAnyCycle(){
    int visited[size];
    for(int i = 0; i<size; i++) visited[i] = 0;
    std::vector<int> current;
    
    for(int i = 0; i<size; i++){
        if(dfsCheckCyclic(i, visited, current)) return true;
        current.clear();
    }
    std::cout<<"\nGiven graph is acyclic.";
    return false;
}



bool Graph::dfsExactCycle(int v, int * visited,  std::vector<int>& current, int length, std::vector<int>& exactCycle){
    visited[v] = 1;
    current.push_back(v);    
    for(int i = 0; i<size; i++){
        if(graph[v][i] == 1  ){
            if(i == current[0]&& current.size()>=3&& (abs(static_cast<int>(current.size())-length) )< (abs(static_cast<int>( exactCycle.size())-length))){
                //current.push_back(i);
                exactCycle.clear();
                exactCycle.assign(current.begin(), current.end());
                if(exactCycle.size() == length) return true; 
                break;
            }
            if( visited[i] == 0) {
                if(dfsExactCycle(i,visited,current,length,exactCycle)) return true;
            }
        }
    }
    current.pop_back();
    return false;
}

bool Graph::findExactCycle(int a){
    int visited[size];
    std::vector<int> exactCycle;
    exactCycle.clear();
    for(int i = 0; i<size; i++) visited[i] = 0;
    std::vector<int> current;
    
    for(int i = 0; i<size; i++){
        if(dfsExactCycle(i, visited, current,a,exactCycle)) break;
        current.clear();
    }
    if(exactCycle.size()<3 ){
         std::cout<<"Your graph is acyclic! ";
        return false;
    }else if(exactCycle.size() == a){
        std::cout<<"Cycle of length of "<<a<<" has been found!\n Cycle: ";
    } else if(a>exactCycle.size()){
        std::cout<<"There is no cycle of length "<<a<<". Closest cycle is shorter and has length of "<<exactCycle.size()<<". \n Cycle: ";
    }else {
        std::cout<<"There is no cycle of length "<<a<<". Closest cycle is longer and has length of "<<exactCycle.size()<<". \n Cycle: ";
    }
    
    for(int i = 0; i<exactCycle.size();i++){
        std::cout<<exactCycle[i]<<" ";
    }
    std::cout<<"\n\n";
    return true;
}

int Graph::getSize(){return size;}