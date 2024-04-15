#include<iostream>
#include<vector>
using namespace std;

bool fourKind(vector<int>, int);
int main(){
       //test
    vector<int>playerHandNum = {12,1,2, 3, 12, 12, 12};
    vector<int>opponentHandNum = {1,3,2, 4, 4, 4, 4};
    bool playerPairs = fourKind(playerHandNum, 7);
    bool opponentPairs = fourKind(opponentHandNum, 7);
    cout << "Player fok: " << playerPairs;
    cout << " Opponent fok: " << opponentPairs << endl;
}

bool fourKind(vector<int> handNum, int handSize){
    bool fourKind = false;
    for (int card = 0; card < handSize - 3 && fourKind == false; card++){ //loop stop 3 cards from last card bc a four match would be impossible
        int matches = 0; //if this == 2 the we have found 3 cards of the same number, careful of 1 off error
        for (int nextCard = card + 1; nextCard < handSize; nextCard++){
            if (handNum[card] == handNum[nextCard])
                matches++;
        }
        if (matches == 3)
            fourKind = true;
    }
    return fourKind;
        //The first for loop is for picking every card(except last 3) to compare, the nested is for looping through every
        //other card and comparing it to the first. Matches is defined inside outer loop so it resets before actual card
        //comparison. if a match is found we must change our bool terminator before another loop starts
}