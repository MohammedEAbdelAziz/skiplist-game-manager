#ifndef __Node_hpp__
#define __Node_hpp__

#include <vector>

class Node {
    public:
        int key;
        int value;
        std::vector<Node*> forward;
        Node(int key, int value, int level);
};

#endif