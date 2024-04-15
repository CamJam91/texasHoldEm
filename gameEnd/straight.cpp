#include<iostream>
#include<vector>
using namespace std;

void swap(int&, int&);

bool straight(vector<int>&);
int main(){
    //test
    vector<int>playerHandNum = {1,8,2, 9, 11, 10,1};
    vector<int>opponentHandNum = {12,3,2, 2, 4, 4, 5};
    bool playerStraight = straight(playerHandNum);
    bool opponentStraight = straight(opponentHandNum);
    cout << "Player straight: " << playerStraight;
    cout << " Opponent straight: " << opponentStraight << endl;
}

bool straight(vector<int>& handNum){
    bool outcome = false; //this turns true if straight is found
    for (int maxCard = 6; maxCard > 0; maxCard--){
        for (int index = 0; index < maxCard; index++){
            if (handNum[index] > handNum[index+1])
                swap(handNum[index], handNum[index+1]);
        }
    } //We need to use a bubble algorithm to sort our arrays to make finding a straight possible

    for (int card = 0; card <= 2 && outcome == false; card++){   //if the first 3 cards don't make a straight then it is impossible so we stop loop
        int match = 0;
        int cardHold = card;    //we need to change the value of card but only for each loop
        for (int nextCard = cardHold +1; nextCard <= 7; nextCard++){
            if (handNum[cardHold] == (handNum[nextCard] - 1)){   //checks if the next card in array is 1 more
                match++;
                cardHold = nextCard;                
            }
        }
        if (true){
            outcome = true; 
        }
    }
    return outcome;
        //This function uses bubbleSort (and swap) to order cards so we can check them for a straight. It takes a card of
        //the first 3 only and checks it with the card right after. If the expression: card1 == card2 -1, isn't true then
        //it goes on to the next card, if it is true, however we move both targets up one, meaning card1 = card2 && card2 = card3
        //and add a number to match. If match == 4, then we've found 5 cards in a row. 
}
void swap(int& bottomCard, int& topCard){
    int temp = topCard;
    topCard = bottomCard;
    bottomCard = temp; 
    }