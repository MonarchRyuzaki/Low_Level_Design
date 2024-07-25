#include <bits/stdc++.h>
#include "./Game.cpp"
using namespace std;

class Match{
private:
    Game g;
public:
    Match(){

    }
    void startMatch(){
        g.startFirstInnings();
        g.startSecondInnings();
    }
};

int main(){
    Match m;
    m.startMatch();
    // Analysis by ChatGPT here -> https://chatgpt.com/c/29044a2d-df9c-46e1-b4f9-9864b3fdc5ec.  
}