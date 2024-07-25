#include <bits/stdc++.h>
using namespace std;

class Batter {
private:
    string name;
    int score;
    int four;
    int six;
    int ballsFaced;
    void updateFour() {four++;}
    void updateSix() {six++;}
public:
    Batter(string name) {
        this->name = name;
        this->score = 0;
        this->four = 0;
        this->six = 0;
        this->ballsFaced = 0;
    }
    int updateScore(int run) {
        if (run == 4) updateFour();
        if (run == 6) updateSix();
        score += run;
        return run;
    }
    void incBalls(){
        ballsFaced++;
    }
    string getName() {return name;}
    int getScore() {return score;}
    int getFour() {return four;}
    int getSix() {return six;}
    int getBalls() {return ballsFaced;}
};