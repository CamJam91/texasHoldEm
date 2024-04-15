#include<iostream>
#include<vector>
using namespace std;

bool threeKind(vector<int>, int);
int main(){
       //test
    vector<int>playerHandNum = {1,1,2, 3, 12, 12, 12};
    vector<int>opponentHandNum = {1,3,2, 2, 4, 4, 4};
    bool playerPairs = threeKind(playerHandNum, 7);
    bool opponentPairs = threeKind(opponentHandNum, 7);
    cout << "Player tok: " << playerPairs;
    cout << " Opponent tok: " << opponentPairs << endl;
}

bool threeKind(vector<int> handNum, int 7){
    bool threeKind = false;
    for (int card = 0; card < handSize - 2 && threeKind == false; card++){ //loop stop 2 cards from last card bc a three match would be impossible
        int matches = 0; //if this == 2 the we have found 3 cards of the same number, careful of 1 off error
        for (int nextCard = card + 1; nextCard < handSize; nextCard++){
            if (handNum[card] == handNum[nextCard])
                matches++;
        }
        if (matches == 2)
            threeKind = true;
    }
    return threeKind;
        //The first for loop is for picking every card(except last 2) to compare, the nested is for looping through every
        //other card and comparing it to the first. Matches is defined inside outer loop so it resets before actual card
        //comparison. if a match is found we must change our bool terminator before another loop starts
}
