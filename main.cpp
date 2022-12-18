#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <memory>
#include <cstdio>

#include "graphs.h"
#include "testing.h"

void getLength(Graph * graph){
    int a;
    std::cout<<"\nEnter length you want to look for: ";
    do{
        std::cin>>a;
        if(a>2 && a<=graph->getSize()){
            graph->findExactCycle(a);
            return;
        }
        std::cout<<"Input correct value (at least 3 to the maxium being number of vertices: ";
    }while(1);
}

void findCycle(Graph * graph){
    int a;
    std::cout<<"\nChose an option\n  1. Check if graph is cyclic\n  2. Find maximum cycle \n  3. Find user input lenght cycle \nOption: ";
    do{
        std::cin>>a;
        switch(a){
            case 1:graph->findAnyCycle();break;
            case 2:graph->findLongestCycle();break;
            case 3:getLength(graph);break;
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

void acyclicInput(){
        int s;
    float sat;
    std::cout<<"Enter number of vertices:";
    std::cin>>s;
    Graph * graph = new Graph(s);
    std::cout<<"Enter saturation(0.0 -> 1.0): ";
    std::cin>>sat;
    (*graph).generateAcyclicGraph(sat);
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
    (*graph).generateRing();
    graph->showMatrix();
    findCycle(graph);
    delete graph;
    return;
}


void mainUserMenu(){
  
    int a;
   
        
    do{
        std::cout<<"Chose an option\n  1. Random matrix \n  2. User input matrix\n  3. Ring matrix\n  4. Acyclic Graph \n  5. End program\nOption: ";
        std::cin>>a;
        switch(a){
            case 1: randoomInput();break;
            case 2: userInput();break;
            case 3: ringInput();break;
            case 4: acyclicInput();break;
            case 5: {std::cout<<"\nEnding work.. \n\n"; return;}
            default: std::cout<<"\nInput correct value:  ";
        }
    }while(1);    
}

void testing(){
     int s = 500, e = 15000, g = 500;
    std::cout<<"Random graph 50 percent saturation: \n";
    GraphTest test14 = GraphTest(EXIST,RANDOM_HALF,s,e,g);
    GraphTest test12 = GraphTest(LONGEST,RANDOM_HALF,s,e,g);
    GraphTest test13 = GraphTest(EXACT,RANDOM_HALF,s,e,g);
    

    std::cout<<"Random graph 30 percent saturation: \n";
    GraphTest test3 = GraphTest(EXIST,RANDOM_ONE_THIRD,s,e,g);
    GraphTest test1 = GraphTest(LONGEST,RANDOM_ONE_THIRD,s,e,g);
    GraphTest test2 = GraphTest(EXACT,RANDOM_ONE_THIRD,s,e,g);
    

    std::cout<<"Random graph 70 percent saturation: \n";
    GraphTest test6 = GraphTest(EXIST,RANDOM_TWO_THIRDS,s,e,g);
    GraphTest test4 = GraphTest(LONGEST,RANDOM_TWO_THIRDS,s,e,g);
    GraphTest test5 = GraphTest(EXACT,RANDOM_TWO_THIRDS,s,e,g);
    

    std::cout<<"Random acyclic graph 50 percent saturation: \n";
    GraphTest test0 = GraphTest(EXIST,ACYCLIC,s,e,g);
    GraphTest test7 = GraphTest(LONGEST,ACYCLIC,s,e,g);
    GraphTest test8 = GraphTest(EXACT,ACYCLIC,s,e,g);
    
   
    std::cout<<"Random graph with one cycle containing all of the vertices: \n";
    GraphTest test11 = GraphTest(EXIST,RING,s,e,g);
    GraphTest test9 = GraphTest(LONGEST,RING,s,e,g);
    //GraphTest test10 = GraphTest(2,4,s,e,g); There's only one cycle

    return;   
}

int main(){
    srand(time(NULL));
    int a; 
        
    do{
        std::cout<<"Cycles in graph testing program.\n  1. User menu\n  2. Start testes\n  3. End program\nOption: ";
        std::cin>>a;
        switch(a){
            case 1: mainUserMenu();break;
            case 2: testing();break;
            case 3: {std::cout<<"\nEnding work.. \n\n"; return 0;}
            default: std::cout<<"\nInput correct value:  ";
        }
    }while(1); 
}