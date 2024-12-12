#include "./include/Skiplist.hpp"
#include "./include/GameManager.hpp"
#include <bits/stdc++.h>
using namespace std;



int main() {
    GameManager skiplist(3, 0.5);
    int choice, playerId, score, N;

    while (true) {
        cout << "1. Add/Update Player Score\n2. Remove Player\n3. Get Player Score\n4. Get Top N Players\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter player ID: ";
                cin >> playerId;
                cout << "Enter score to add/update: ";
                cin >> score;
                skiplist.addPlayer(playerId, score);
                cout << "Player score updated.\n";
                break;
            case 2:
                cout << "Enter player ID to remove: ";
                cin >> playerId;
                skiplist.removePlayer(playerId);
                cout << "Player removed.\n";
                break;
            case 3:
                cout << "Enter player ID to get score: ";
                cin >> playerId;
                if (skiplist.getPlayerScore(playerId)) {
                    cout << "Player score: " << skiplist.getPlayerScore(playerId) << "\n";
                } else {
                    cout << "Player not found.\n";
                }
                break;
            case 4:
                cout << "Enter N to get top N players: ";
                cin >> N;
                cout << "Top " << N << " players:\n";
                skiplist.getTopPlayers(N);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;

}