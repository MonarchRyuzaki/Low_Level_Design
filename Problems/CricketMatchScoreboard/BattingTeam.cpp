#include <bits/stdc++.h>
#include "./Batter.cpp"
using namespace std;

class BattingTeam{
private:
    int striker, nonStriker, nextBatter;
    vector<Batter*> batsmen;
    int numBatters, score, wickets;
    int ballsFaced;
    int extras;
public: 
    BattingTeam(){

    }
    void setBattingOrder(int n, vector<string> name) {
        striker = 0, nonStriker = 1, nextBatter = 2;
        numBatters = n;
        ballsFaced = 0;
        extras = 0;
        wickets = 0;
        score = 0;
        for (int i=0; i<n; i++){
            batsmen.push_back(new Batter(name[i]));
        }
    }
    void rotateStrike(){
        int temp = striker;
        striker = nonStriker;
        nonStriker = temp;
    }
    bool isNextBatter(){
        return (nextBatter < numBatters);
    }
    void setNextBatter(){
        wickets++;
        striker = nextBatter++;
    }
    void updateScore(int run){
        score += batsmen[striker]->updateScore(run);
        // cout << score << endl;
        if (run == 1 || run == 3 || run == 5) {
            rotateStrike();
        }
    }
    void updateBalls(){
        batsmen[striker]->incBalls();
        ballsFaced++;
    }
    void handleExtra(string extra) {
        if (extra == "Wd") {
            extras++;
        } 
    }
    void displayScore(){
        cout << "Name\tScore\t4s\t6s\tBalls" << endl;
        for (auto &it: batsmen) {
            cout << it->getName() << "\t" << it->getScore() << "\t" << it->getFour() << "\t" << it->getSix() << "\t" << it->getBalls() << endl; 
        }
        cout << "Total : " << (score+extras) << "/" << wickets << endl;
        cout << "Extras: " << extras << endl;
        cout << "Overs: " << ballsFaced/6 << "." << ballsFaced%6 << endl;
    }
    void displayAllOut(){
        cout << "Innings Over" << endl;
        cout << "Total : " << score << "/" << wickets << endl;
        cout << "Overs: " << ballsFaced/6 << "." << ballsFaced%6 << endl;
    }
    pair<int, int> getResult(){
        return {score, wickets};
    }
};