#include<iostream>
#include <vector>
using namespace std;

int highCard(vector<int>, int);

int main(){    
    //test
    vector<int>playerHandNum = {2, 4, 7, 9, 12};
    vector<int>opponentHandNum = {2, 4, 7, 1, 11};
    int playerHigh = highCard(playerHandNum, 5);
    int opponentHigh = highCard(opponentHandNum, 5);
    cout << "Player high: " << playerHigh << " Opponent high: " << opponentHigh << endl;
}

int highCard(vector<int> handNum, int handSize){
    int highCard = 0;
    for (int card = 0; card < handSize; card++){
        if (highCard != 1 && handNum[card] > highCard || handNum[card] == 1){
            //this if condition is clunky but its easier for other algorithms if ace is represented by 1
            //but we still have ot make it high
            highCard = handNum[card];
        }
    }
    return highCard;
} 