#include<iostream>
using namespace std;

struct Card{
    int cardNum;
    char suit;
};

int main(){
    const int DECKSIZE = 52;
    Card Deck[DECKSIZE];
    char suitLetter[4] = {'H', 'D', 'S', 'C'}; //for assigning deck array with a for loop

    for (int iCount = 0; iCount < 4; iCount++){
        
        for (int jCount = 0; jCount < 13; jCount++){
            Deck[jCount + (iCount * 13)].cardNum = jCount + 1; //we dont want to reassign numbers so we use (icount * 13)
            Deck[jCount + (iCount * 13)].suit = suitLetter[iCount];
        }
    } //The outer loop, triggers 4 times, assigning a group of suit letters, the nested loop triggers 12 times giving each
    //group of suit card a number 1 - 13;

    //show cards in deck
    for (int count = 0; count < DECKSIZE; count++){
        cout << Deck[count].cardNum << Deck[count].suit << endl;
    }
}
