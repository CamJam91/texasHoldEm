#include<iostream>
#include<vector>
using namespace std;

int pairs(vector<int>);
int main(){
     //test
    vector<int>playerHandNum = {2, 3, 7, 2, 12};
    vector<int>opponentHandNum = {2, 4, 7, 2, 4};
    int playerPairs = pairs(playerHandNum);
    int opponentPairs = pairs(opponentHandNum);
    cout << "Player Pairs: " << playerPairs << " Opponent Pairs: " << opponentPairs << endl;
}

int pairs(vector<int> handNum){
    int numberofPairs = 0;
    for (int card = 0; card < 6; card++){ //we dont need to check the lat card it will already be checked on next to last
        for (int nextCard = card + 1; nextCard < 7; nextCard++){ //keeps card to check the same but loops through every other one
            if (handNum[card] == handNum[nextCard])
                numberofPairs++;
        }
    }
    return numberofPairs;
}