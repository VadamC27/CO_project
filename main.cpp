#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <memory>
#include <cstdio>

#include "graphs.h"

void findCycle(Graph * graph){
    int a;
    std::cout<<"\nChose an option\n  1. Check if graph is cyclic\n  2. Find maximum cycle \n  3. Find user input lenght cycle \nOption: ";
    do{
        std::cin>>a;
        switch(a){
            case 1:graph->findAnyCycle();break;
            case 2:graph->findLongestCycle();break;
            case 3:
            default: std::cout<<"\nInput correct value:  ";  a=-1;
        }
     } while(a==-1);
     return;
}

void randoomInput(){
    int s;
    float sat;
    std::cout<<"Enter number of vertices:";
    std::cin>>s;
    Graph * graph = new Graph(s);
    std::cout<<"Enter saturation(0.0 -> 1.0): ";
    std::cin>>sat;
    (*graph).generateRandomEdges(sat);
    std::cout<<"\nYour matrix:\n\n";
    graph->showMatrix();
    findCycle(graph);
    delete graph;
    return;
}


void userInput(){
    int s;
    std::cout<<"Enter number of vertices: ";
    std::cin>>s;
    Graph * graph = new Graph(s);
    (*graph).generateInput();
    std::cout<<"\nYour matrix:\n\n";
    graph->showMatrix();
    findCycle(graph);
    delete graph;
    return;
}

void ringInput(){
    int s;
    std::cout<<"Enter number of vertices: ";
    std::cin>>s;
    Graph * graph = new Graph(s);
    (*graph).generateRing(2);
    graph->showMatrix();
    findCycle(graph);
    delete graph;
    return;
}


int main(){
    // srand(time(NULL));
    // std::cout<<"Hey!\n";
    // Graph a(5);
    // std::cout<<"Same 0:\n";
    // a.showMatrix();
    // a.generateRandomEdges(0.5);
    // std::cout<<"Losowe 50% krawedzi\n";
    // a.showMatrix();
    // a.input();
    // a.showMatrix();
    int a;
    
        
    do{
         std::cout<<"Chose an option\n  1. Random matrix \n  2. User input matrix\n  3. Ring matrix \n  4. End program\nOption: ";
        std::cin>>a;
        switch(a){
            case 1: randoomInput();break;
            case 2: userInput();break;
            case 3: ringInput();break;
            case 4: {std::cout<<"\nEnding work.. \n\n"; return 0;}
            default: std::cout<<"\nInput correct value:  ";
        }
    }while(1);    
}