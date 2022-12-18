#include "testing.h"
#include <chrono>
#include <iostream>


GraphTest::GraphTest(int type, int graphType, int start_v, int end_v, int g){
    std::ofstream out_file;
 
    for(int i = start_v; i<=end_v; i+=g){
        Graph * graph = new Graph(i);
        switch(graphType){
            case RANDOM_HALF: graph->generateRandomEdges(0.5);  out_file.open("out/outputRND50.txt", std::ofstream::app); break;
            case RANDOM_ONE_THIRD:graph->generateRandomEdges(0.3);out_file.open("out/outputRND30.txt", std::ofstream::app);break;
            case RANDOM_TWO_THIRDS:graph->generateRandomEdges(0.8);out_file.open("out/outputRND70.txt", std::ofstream::app);break;
            case ACYCLIC:graph->generateAcyclicGraph(0.5);out_file.open("out/outputAcyclic50.txt", std::ofstream::app);break;
            case RING: graph->generateRing();out_file.open("out/outputRing.txt", std::ofstream::app);break;
        }
        bool success;
        auto start = std::chrono::steady_clock::now();
        switch(type){
            
            case EXIST:{
                success = graph->findAnyCycle(); 
                out_file<<"Check if exists: ";
                break;
            }
            case LONGEST:{
                success = graph->findLongestCycle();
                out_file<<"Find the longest cycle: ";
                break;
            }
            case EXACT:{                
                success = graph->findExactCycle(static_cast<int> (i/2));
                out_file<<"Exact cycle: ";
                break;
            }
        }
        auto end = ( std::chrono::steady_clock::now());
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() ;
        if(success)out_file << "For "<< i<< " vertices found: " << duration << " milliseconds." << std::endl;
        else out_file << "For "<< i<< " vertices failure: " << duration<< " milliseconds." << std::endl;
        out_file.close();
        delete graph;
    }
}