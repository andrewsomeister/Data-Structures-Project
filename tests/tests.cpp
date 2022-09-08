

#include "../cs225/catch/catch.hpp"
#include "../road.h"
#include <vector>
#include <algorithm>

TEST_CASE("Graph is connected") {
    Roads graph("datasmall.txt");

    REQUIRE(graph.isconnected());
}

TEST_CASE("Unconnected graph is rejected") {
    Roads graph("data_unconnected.txt");

    REQUIRE(graph.isconnected() == false);
}

TEST_CASE("Constructor Works") {
    Roads graph("datasmall.txt");

    std::vector<double> row1 = {0, 4, 0,  0,  0, 0, 0,  0,  0,   0};
    std::vector<double> row2 = {4, 0, 6,  0,  0, 7, 0,  0,  0,   0};
    std::vector<double> row3 = {0, 6, 0, 12,  1, 0, 0,  0,  0,   0};
    std::vector<double> row4 = {0, 0, 12, 0, 15, 0, 7,  0,  0,   0};
    std::vector<double> row5 = {0, 0, 1, 15,  0, 8, 9, 11,  0,   0};
    std::vector<double> row6 = {0, 7, 0,  0,  8, 0, 0,  5,  0,   0};
    std::vector<double> row7 = {0, 0, 0,  7,  9, 0, 0,  0,  3,   0};
    std::vector<double> row8 = {0, 0, 0,  0, 11, 5, 0,  0, 10,   0};
    std::vector<double> row9 = {0, 0, 0,  0,  0, 0, 3, 10,  0,   4};
    std::vector<double> row10 = {0, 0, 0, 0,  0, 0, 0,  0,  4,   0};

    std::vector<std::vector<double>> solution = {row1, row2, row3, row4, row5, row6, row7, row8, row9, row10};

    std::vector<std::vector<double>> constructor = graph.getAdj();

    REQUIRE(solution == constructor);
    
}

TEST_CASE("BFS works") {
    Roads graph("datasmall.txt");

    std::vector<int> trav = graph.BFS(0);

    for (int i = 0; i < 10; i++) {
        REQUIRE(std::find(trav.begin(), trav.end(), i) != trav.end());
    }
    REQUIRE( (int) trav.size() == 10);

}



TEST_CASE("Prim's Algorithm Works") {
    Roads graph("datasmall.txt");

    std::vector<std::pair<int, int>> trav = graph.prim();

    bool c1 = (std::find(trav.begin(), trav.end(), std::pair<int, int>(0, 1)) != trav.end()) || (std::find(trav.begin(), trav.end(), std::pair<int, int>(1, 0)) != trav.end());
    REQUIRE(c1);
    bool c2 = std::find(trav.begin(), trav.end(), std::pair<int, int>(2, 1)) != trav.end() || std::find(trav.begin(), trav.end(), std::pair<int, int>(1, 2)) != trav.end();
    REQUIRE(c2);
    bool c3 = std::find(trav.begin(), trav.end(), std::pair<int, int>(4,2)) != trav.end() || std::find(trav.begin(), trav.end(), std::pair<int, int>(2,4)) != trav.end();
    REQUIRE(c3);
    bool c4 = std::find(trav.begin(), trav.end(), std::pair<int, int>(5, 1)) != trav.end() || std::find(trav.begin(), trav.end(), std::pair<int, int>(1, 5)) != trav.end();
    REQUIRE(c4);
    bool c5 = std::find(trav.begin(), trav.end(), std::pair<int, int>(7,5)) != trav.end() || std::find(trav.begin(), trav.end(), std::pair<int, int>(5,7)) != trav.end();
    REQUIRE(c5);
    bool c6 = std::find(trav.begin(), trav.end(), std::pair<int, int>(6,4)) != trav.end() || std::find(trav.begin(), trav.end(), std::pair<int, int>(4,6)) != trav.end();
    REQUIRE(c6);
    bool c7 = std::find(trav.begin(), trav.end(), std::pair<int, int>(8,6)) != trav.end() || std::find(trav.begin(), trav.end(), std::pair<int, int>(6,8)) != trav.end();
    REQUIRE(c7);
    bool c8 = std::find(trav.begin(), trav.end(), std::pair<int, int>(8,9)) != trav.end() || std::find(trav.begin(), trav.end(), std::pair<int, int>(9,8)) != trav.end();
    REQUIRE(c8);
    bool c9 = std::find(trav.begin(), trav.end(), std::pair<int, int>(3,6)) != trav.end() || std::find(trav.begin(), trav.end(), std::pair<int, int>(6,3)) != trav.end();
    REQUIRE(c9);

    REQUIRE((int) trav.size() == 9);
}

TEST_CASE("Dijkstra's Algorithm Works") {

    Roads graph("datasmall.txt");

    vector<pair<double, int>> algo = graph.dijkstra(0);

    vector<double> solution = {0, 4, 10, 22, 11, 11, 20, 16, 23, 27};
    vector<double> solution_parent = {0, 0, 1, 2, 2, 1, 4, 5, 6, 8};


    for (int i = 0; i < 10; i++) {
        REQUIRE(algo[i].first == solution[i]);
        REQUIRE(algo[i].second == solution_parent[i]);
    }
    REQUIRE(algo.size() == solution.size());
}

TEST_CASE("Betweenness Centrality Works") {
    Roads graph("datasmall.txt");

    vector<int> central = graph.centrality();

    vector<int> solution = {9, 25, 32, 9, 36, 13, 30, 13, 28, 9};

    REQUIRE(central == solution);
}