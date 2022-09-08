#pragma once
#include <vector>
#include <utility>
#include <string>
#include <unordered_set>
#include "heap.h"
#include "dsets.h"

class Roads {
    public:
    Roads(std::string filename);

    vector<int> BFS(int startPoint);


    std::vector<pair<int, int>> prim();

    std::vector<pair<double, int>> dijkstra(int start);

    vector<int> centrality();

    void tracePath(vector<int> & solution, int index);

    std::vector<std::vector<double>> getAdj() {
        return adj;
    }

    int getMaxIndex(vector<int> vec) {
        int index = 0;
        int max = vec[index];
        for (int i = 1; i < (int) vec.size(); i++) {
            if (vec[i] > max) {
                max = vec[i];
                index = i;
            }
        }
        return index;
    }

    bool isconnected() {
        return connected;
    }

    private:

    std::vector<std::vector<double>> adj;

    bool connected;

};





