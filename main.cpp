#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "road.h"

int main(int argc, char** argv) {
    // should be of the form: 
    // ./main datasmall.txt BFS[0] prim centrality
    // ./main data.txt prim


    


    // there has to be at least 2 arguments
    if (argc < 2) {
        
        return 0;
    }

    char* filename = argv[1];

    // accessing the file
    Roads graph(filename);

    if (graph.getAdj().size() < 1) {
        std::cout << "file does not exist" << std::endl;
        return 0;
    } 

    if (graph.isconnected() == false) {
        std::cout << "graph is not connected" << std::endl;
        return 0;
    }


    ofstream outputfile;
    outputfile.open("output.txt");

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "prim") == 0) {
            std::vector<std::pair<int, int>> primed = graph.prim();

            outputfile << "Prim's Algorithm:\n" << "This is the set of edges that make up the minimum spanning tree.\n";
            for (int i = 0; i < (int) primed.size(); i++) {
                outputfile << primed[i].first << " <-> " << primed[i].second << "\n";
            }

            outputfile << "\n";

        } else if (strcmp(argv[i], "centrality") == 0) {
            std::vector<int> central = graph.centrality();
            outputfile << "Betweenness Centrality:\n" << "The following are the amount of times each node is appears in a shortest path. A higher score indicates a more central node.\n\n";
            int maxIndex = graph.getMaxIndex(central);
            outputfile << "The most central node is node " << maxIndex << " with a score of " << central[maxIndex] << ".\n\n";
            for (int i = 0; i < (int) central.size(); i++) {
                outputfile << "Node " << i << ": " << central[i] << "\n";
            }

            outputfile << "\n";
        } else if (argv[i][0] == 'B' && argv[i][1] == 'F' && argv[i][2] == 'S') {
            std::vector<int> bfs = graph.BFS((int) argv[i][4] - 48);
            outputfile << "Breadth First Search:\n";

            for (int i = 0; i < (int) bfs.size(); i++) {
                outputfile << bfs[i] << " ";
                if (i % 20 == 19) {
                    outputfile << "\n";
                }
            }

            outputfile << "\n\n";

        }
    }

    
    outputfile.close();
    

    return 0;
}