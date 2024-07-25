#include <bits/stdc++.h>
#include "./Innings.cpp"
using namespace std;

class Game {
private:
    int n, overs;
    int inning;
    Innings first, second;
public:
    Game() {
        cout << "No. of players in each team : ";
        cin >> n;
        cout << "No. of overs : ";
        cin >> overs;
    }
    void startFirstInnings(){
        first.initializeInnings(n, overs);
        cout << "Batting Order for team 1" << endl;
        first.takeBattingOrder();
        first.startInnings();
        cout << "Target For Team 2: " << first.getTarget();
    }
    void startSecondInnings(){
        second.initializeInnings(n, overs);
        second.takeBattingOrder();
        second.startInnings(first.getTarget());
    }
};