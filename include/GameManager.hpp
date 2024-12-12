#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "SkipList.hpp"
#include <vector>
#include <utility>

class GameManager {
private:
    SkipList skipList;

public:
    GameManager(int maxLevel, float probability);
    void addPlayer(int playerId, int initialScore);
    void removePlayer(int playerId);
    void updatePlayerScore(int playerId, int score);
    int getPlayerScore(int playerId);
    std::vector<std::pair<int, int>> getTopPlayers(int N);
};

#endif