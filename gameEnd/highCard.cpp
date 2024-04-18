#include<iostream>
#include <vector>
using namespace std;

int highCard(vector<int>);

int main(){    
    //test
    vector<int>playerHandNum = {2, 4, 7, 9, 12, 9, 2};
    vector<int>opponentHandNum = {2, 4, 7, 1, 11, 10, 5};
    int playerHigh = highCard(playerHandNum);
    int opponentHigh = highCard(opponentHandNum);
    cout << "Player high: " << playerHigh << " Opponent high: " << opponentHigh << endl;
}

int highCard(vector<int> handNum){
    int highCard = 0;
    for (int card = 0; card < 7; card++){
        if (highCard != 1 && handNum[card] > highCard || handNum[card] == 1){
            //this if condition is clunky but its easier for other algorithms if ace is represented by 1
            //but we still have ot make it high
            highCard = handNum[card];
        }
    }
    return highCard;
        //Function to find the highest number except in this case 1 will resolve as the highest because it represents the Ace
} 