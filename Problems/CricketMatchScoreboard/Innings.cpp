#include <bits/stdc++.h>
#include "./BattingTeam.cpp"
using namespace std;

class Innings {
private:
    BattingTeam team;
    int n, overs;
    bool isPrevNb = false;
    int cnt = 0;
    bool handleEvent(string event){
        if (event == "W") {
            if (isPrevNb) {
                isPrevNb = false;
                return handleEvent("Wd");
            }
            if (team.isNextBatter()) {
                team.setNextBatter();
            } else {
                team.displayAllOut();
                return false;
            }
        } else if (event == "Nb") {
            isPrevNb = true;
            team.handleExtra(event);
        } else if (event == "Wd") {
            team.handleExtra(event);
        } else {
            int run = stoi(event);
            team.updateBalls();
            team.updateScore(run);
        }
        return true;
    }
public:
    Innings(){

    }
    void initializeInnings(int a, int b){
        n = a; overs = b;
    }
    void takeBattingOrder(){
        cnt++;
        vector<string> order(n);
        for (int i=0; i<n; i++) cin >> order[i];
        team.setBattingOrder(n, order);
    }
    void startInnings(int target = -1){
        for (int j=1; j <= overs; j++){
            cout << "Over " << j << ": ";
            for (int i=0; i<6; i++){
                string event; cin >> event;
                if (!handleEvent(event)) {
                    return;
                }
                if (target != -1 && team.getResult().first > target) {
                    cout << "Team 2 Wins" << endl;
                }

            }
            cout << "Scorecard for Team " << cnt << ": " << endl;
            team.displayScore();
        }
    }
    int getTarget(){
        return team.getResult().first + 1;
    }
};