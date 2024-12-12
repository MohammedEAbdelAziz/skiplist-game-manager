#include <vector>
#include "../include/Node.hpp"

Node::Node(int key, int value, int level) : key(key), value(value), forward(level, nullptr) {}