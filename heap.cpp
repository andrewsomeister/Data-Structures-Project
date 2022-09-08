
#include "heap.h"






int heap::leftChild(int currentIdx) const
{
    return 2 * currentIdx;
}

int heap::rightChild(int currentIdx) const
{
    // @TODO Update to return the index of the right child.
    return 2 * currentIdx + 1;
}

int heap::parent(int currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return (int) (currentIdx / 2);
}

bool heap::hasAChild(int currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    return (int) leftChild(currentIdx) < (int) _elems.size();
}

int heap::maxPriorityChild(int currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    if (rightChild(currentIdx) >= (int) _elems.size()) {
        return leftChild(currentIdx);
    }

    if (_elems[leftChild(currentIdx)].second < _elems[rightChild(currentIdx)].second) {
        return leftChild(currentIdx);
    } else {
        return rightChild(currentIdx);
    }
}

void heap::heapifyDown(int currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    if (hasAChild(currentIdx)) {
        int min_child = maxPriorityChild(currentIdx);
        if (_elems[min_child].second < _elems[currentIdx].second) {
            std::swap(_elems[currentIdx], _elems[min_child]);
            heapifyDown(min_child);
        }
    }
}

void heap::heapifyUp(int currentIdx)
{
    if (currentIdx == root())
        return;
    int parentIdx = parent(currentIdx);
    if (_elems[currentIdx].second < _elems[parentIdx].second) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

heap::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
    _elems.push_back(pair<int, double>(1,1.0));
}

heap::heap(const std::vector<pair<int, double>>& elems) 
{
    // @TODO Construct a heap using the buildHeap algorithm
    _elems.push_back(pair<int, double>(1, 1.0));
    
    for (int i = 0; i < (int) elems.size(); i++) {
        _elems.push_back(elems[i]);
    }
    

    for (int i = (int) _elems.size() - 1; i > 0; i--) {
        heapifyDown(i);
    }

}

pair<int, double> heap::pop()
{
    // @TODO Remove, and return, the element with highest priority
    std::swap(_elems[1], _elems[_elems.size() - 1]);
    pair<int, double> result = _elems[_elems.size() - 1];
    _elems.pop_back();
    heapifyDown(root());
    return result;
}

pair<int, double> heap::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    return _elems[root()];
}

void heap::push(const pair<int, double>& elem)
{
    // @TODO Add elem to the heap
    _elems.push_back(elem);
    heapifyUp(_elems.size() - 1);
}

void heap::updateElem(const int & idx, const pair<int, double>& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
    pair<int, double> old = _elems[idx];
    _elems[idx] = elem;

    if (_elems[idx].second < old.second) {
        heapifyUp(idx);
    } else {
        heapifyDown(idx);
    }
}


bool heap::empty() const
{
    // @TODO Determine if the heap is empty
    return _elems.size() <= 1;
}

void heap::getElems(std::vector<pair<int, double>> & heaped) const
{
    for (int i = root(); i < (int) _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}