#include<iostream>
#include<vector>
using namespace std;

bool fourKind(vector<int>);
int main(){
       //test
    vector<int>playerHandNum = {12,1,2, 3, 12, 12, 12};
    vector<int>opponentHandNum = {1,3,2, 4, 4, 4, 4};
    bool playerPairs = fourKind(playerHandNum);
    bool opponentPairs = fourKind(opponentHandNum);
    cout << "Player fok: " << playerPairs;
    cout << " Opponent fok: " << opponentPairs << endl;
}

bool fourKind(vector<int> handNum){
    bool fourKind = false;
    for (int card = 0; card <= 4 && fourKind == false; card++){ //loop stops at card 4 bc a three match would be impossible
        int matches = 0; //if this == 3 the we have found 4 cards of the same number, careful of 1 off error
        for (int nextCard = card + 1; nextCard < 7; nextCard++){    //compare all 7 cards to target card
            if (handNum[card] == handNum[nextCard])
                matches++;
        }
        if (matches == 3)
            fourKind = true; //after each card is checked against every other we see if we have 3 of a kind
    }
    return fourKind;
        //The first for loop is for picking every card(except last 2) to compare, the nested is for looping through every
        //other card and comparing it to the first. Matches is defined inside outer loop so it resets before actual card
        //comparison. if a match is found we must change our bool terminator before another loop starts
}