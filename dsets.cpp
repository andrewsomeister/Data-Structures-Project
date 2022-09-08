#include "dsets.h"
#include <iostream>

void DisjointSets::addelements(int num) {

    for (int i = 0; i < num; i++) {
        data_.push_back(-1);
    }

}


int DisjointSets::find(int elem) {
    int toreturn;
    if (data_[elem] < 0) {
        return elem;
    } else {
        toreturn = find(data_[elem]);
    }

    data_[elem] = toreturn;

    return toreturn;

}

void DisjointSets::setunion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
        return;
    }

    if (data_[a] > data_[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    int new_size = data_[a] + data_[b];
    data_[b] = a;
    data_[a] = new_size;
}

int DisjointSets::size(int elem) {
    return -1 * data_[find(elem)];
}