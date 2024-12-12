#include "../include/Skiplist.hpp"
#include "../include/Node.hpp"
#include <bits/stdc++.h>
using namespace std;


int SkipList::randomLevel() {
    int level = 1;
    while (((float)std::rand() / RAND_MAX) < probability && level < maxLevel) {
        level++;
    }
    return level;
}


SkipList::SkipList(int maxLevel, float probability) : maxLevel(maxLevel), probability(probability), currentLevel(0) {
    head = new Node(-1, -1, maxLevel);
    std::srand(std::time(nullptr));
}

SkipList::~SkipList() {
    Node* current = head;
    while (current) {
        Node* next = current->forward[0];
        delete current;
        current = next;
    }
}
void SkipList::insert(int key, int value) {
    std::vector<Node*> update(maxLevel, nullptr);
    Node* current = head;

    for (int i = currentLevel; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (!current || current->key != key) {
        int newLevel = randomLevel();

        if (newLevel > currentLevel) {
            for (int i = currentLevel + 1; i < newLevel; i++) {
                update[i] = head;
            }
            currentLevel = newLevel - 1;
        }

        Node* newNode = new Node(key, value, newLevel);
        for (int i = 0; i < newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    } else {
        current->value = value;
    }
}
bool SkipList::remove(int key) {
    std::vector<Node*> update(maxLevel, nullptr);
    Node* current = head;

    for (int i = currentLevel; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current && current->key == key) {
        for (int i = 0; i <= currentLevel; i++) {
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }

        delete current;

        while (currentLevel > 0 && !head->forward[currentLevel]) {
            currentLevel--;
        }
        return true;
    }
    return false;
}

int SkipList::search(int key) {
    Node* current = head;

    for (int i = currentLevel; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];
    if (current && current->key == key) {
        return current->value;
    } else {
        throw std::runtime_error("Key not found");
    }
}

void SkipList::print() {
    for (int i = 0; i <= currentLevel; i++) {
        Node* current = head->forward[i];
        std::cout << "Level " << i << ": ";
        while (current) {
            std::cout << "(" << current->key << ", " << current->value << ") ";
            current = current->forward[i];
        }
        std::cout << "\n";
    }
}
