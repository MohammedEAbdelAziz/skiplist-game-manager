#include "../include/GameManager.hpp"

GameManager::GameManager(int maxLevel, float probability) : skipList(maxLevel, probability) {}

void GameManager::addPlayer(int playerId, int initialScore) {
    skipList.insert(playerId, initialScore);
}

void GameManager::removePlayer(int playerId) {
    skipList.remove(playerId);
}

void GameManager::updatePlayerScore(int playerId, int score) {
    if (skipList.search(playerId)) {
        skipList.remove(playerId);
    }
    skipList.insert(playerId, score);
}

int GameManager::getPlayerScore(int playerId) {
    return skipList.search(playerId);
}

std::vector<std::pair<int, int>> GameManager::getTopPlayers(int N) {
    std::vector<std::pair<int, int>> topPlayers;
    Node* current = skipList.head->forward[0];

    while (current && N > 0) {
        topPlayers.push_back({current->key, current->value});
        current = current->forward[0];
        N--;
    }
    for (const auto& player : topPlayers) {
        std::cout << "Player ID: " << player.first << ", Score: " << player.second << std::endl;
    }
    return topPlayers;
}