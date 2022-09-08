#pragma once
#include <vector>


class DisjointSets {
    private:
    
    std::vector<int> data_;


    

    public:

    void addelements(int num);

    int find(int elem);

    void setunion(int a, int b);

    int size(int elem);

};