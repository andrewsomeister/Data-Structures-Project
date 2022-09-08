#include "road.h"
#include <queue>
#include <unordered_set>
#include <map>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>




Roads::Roads(std::string filename) {
    std::ifstream lineFile(filename);
    std::string line;
    int lines;

    //lineFile.open(filename);


    int ind0, node10, node20;
    double d0;

    int max = 0;

    while (lineFile >> ind0 >> node10 >> node20 >> d0) {
        
        if (node10 > max) {
            max = node10;
        }
        if (node20 > max) {
            max = node20;
        }
    }
    
    DisjointSets dsets;
    dsets.addelements(max + 1);
    

    adj = vector<vector<double>>(max + 1, vector<double>(max + 1, 0));

    std::ifstream openFile(filename);

    int ind, node1, node2;
    double d;

    while (openFile >> ind >> node1 >> node2 >> d) {
        adj[node1][node2] = d;
        adj[node2][node1] = d;
        dsets.setunion(node1, node2);
    }
    connected = dsets.size(0) == max + 1;

}





vector<int> Roads::BFS(int startPoint) {
    std::queue<int> que;

    
    que.push(startPoint);
    unordered_set<int> set;
    set.insert(startPoint);

    vector<int> toreturn;
    while(que.empty() == false) {
        int current = que.front();
        
        que.pop();
        
        toreturn.push_back(current);
        for (int i = 0; i < (int) adj[current].size(); i++) {
            if (adj[current][i] > 0 && set.find(i) == set.end()) {
                que.push(i);
                set.insert(i);
            }
        }
    }

    return toreturn;
}


vector<pair<int, int>> Roads::prim() {
    std::unordered_set<int> included;

    std::vector<double> keys;

    std::vector<int> parent(adj.size(), -1);

    keys.push_back(0);

    for (int i = 1; i < (int) adj.size(); i++) {
        keys.push_back(99999);
    }

    std::vector<std::pair<int, double>> start;
    start.push_back(std::pair<int, double>(0, 0));
    heap heep(start);

    std::vector<std::pair<int, int>> toreturn;


    while(included.size() < adj.size()) {
        std::pair<int, double> min = heep.pop();

        if (included.find(min.first) != included.end()) {
            continue;
        }

        included.insert(min.first);


        for (int i = 0; i < (int) adj.size(); i++) {
            if (adj[i][min.first] > 0 && included.find(i) == included.end()) {
                if (adj[i][min.first] < keys[i]) {
                    keys[i] = adj[i][min.first];
                    parent[i] = min.first;
                }
                std::pair<int, double> toadd(i, adj[i][min.first]);
                heep.push(toadd);
            }
        }


    }

    for (int i = 0; i < (int) parent.size(); i++) {
            if (parent[i] >= 0) {
                toreturn.push_back(std::pair<int, int>(i, parent[i]));
            }
    }
    return toreturn;

}

std::vector<pair<double, int>> Roads::dijkstra(int start) {
    std::unordered_set<int> included;
    std::vector<double> keys = std::vector<double>(adj.size(), 999999);
     std::vector<int> parents = std::vector<int>(adj.size(), -1);
     std::vector<pair<double, int>> solution;

    parents[start] = start;
    keys[start] = 0;

    std::vector<std::pair<int, double>> startv;
    startv.push_back(std::pair<int, double>(start, 0));
    heap heep(startv);

    while (included.size() < adj.size()) {
        std::pair<int, double> min = heep.pop();

        if (included.find(min.first) != included.end()) {
            continue;
        }

        included.insert(min.first);

        for (int i = 0; i < (int) adj.size(); i++) {
            if (adj[i][min.first] > 0) {
                double dist_to_neigh = adj[i][min.first] + keys[min.first];
                if (dist_to_neigh < keys[i]) {
                    keys[i] = dist_to_neigh;
                    parents[i] = min.first;
                }
                std::pair<int, double> toadd(i, adj[i][min.first]);
                heep.push(toadd);
            }
        }
    }

    for (auto i = 0; i < (int) keys.size(); i++) {
        solution.push_back(pair<double, int> (keys[i], parents[i]));
    }

    return solution;
}

vector<int> Roads::centrality() {
    vector<int> solution(adj.size(), 0);

    for (int i = 0; i < (int) adj.size(); i++) {
        tracePath(solution, i);
    }

    return solution;
}


void Roads::tracePath(vector<int> & solution, int index) {
    vector<pair<double, int>> paths = dijkstra(index);
    for (int i = 0; i < (int) adj.size(); i++) {
        int current = i;
        while (paths[current].first > 0) {
            solution[current]++;
            current = paths[current].second;
        }
    }
}

