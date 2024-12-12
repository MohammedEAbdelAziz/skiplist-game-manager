#ifndef __Skiplist_hpp__
#define __Skiplist_hpp__
#include "Node.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class SkipList {


public:
    Node* head;
    int maxLevel;
    float probability;
    int currentLevel;

    int randomLevel();
   
    SkipList(int maxLevel, float probability);

    ~SkipList();

    void insert(int key, int value);

    bool remove(int key);

    int search(int key);

    void print();
};

#endif