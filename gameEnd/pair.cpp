#include<iostream>
#include<vector>
using namespace std;

int pairs(vector<int>, int);
int main(){
     //test
    vector<int>playerHandNum = {2, 3, 7, 2, 12};
    vector<int>opponentHandNum = {2, 4, 7, 2, 4};
    int playerPairs = pairs(playerHandNum, 5);
    int opponentPairs = pairs(opponentHandNum, 5);
    cout << "Player Pairs: " << playerPairs << " Opponent Pairs: " << opponentPairs << endl;
}

int pairs(vector<int> handNum, int handSize){
    int numberofPairs = 0;
    for (int card = 0; card < handSize -1; card++){ //we dont need to check the lat card it will already be checked on next to last
        for (int nextCard = card + 1; nextCard < handSize; nextCard++){ //keeps card to check the same but loops through every other one
            if (handNum[card] == handNum[nextCard])
                numberofPairs++;
        }
    }
    return numberofPairs;
}