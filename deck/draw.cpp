#include <iostream>
#include <vector>
using namespace std;

void draw(vector<int>&, vector<char>&, int&pullNum, char& pullSuit);
int randomGen(); //calls and returns nrandom number
int main(){
    unsigned seed = time(0);
    srand(seed);

    char DECK_SUIT[52] = {'H','H','H','H','H','H','H','H','H','H','H','H','H','C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','S','S','S','S','S','S','S','S','S','S','S','S','S'};//Suits. H = hearts and so on
    int DECK_NUM[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};   //the 1 represents Ace and the 11, 12, 13 represent jack, queen, king respectively

    char cardPullSuit = 'a';
    int cardPullNum = 0;   //This is basically the card that gets pulled from out deck, its purpose is so that we can pass
    //an array value to our player hands/river. Since these variables differ we need an intermediary card that can be reset and
    //reassigned at will. Like the card variables, this needs to be seperated into Num and Suit.
    //Test
    void draw();
    cout 
}

void draw(vector<int>& cardNum, vector<char>& cardSuit, int& pullNum, char& pullSuit){ //2 vectors are referenced: the number of the card and the suit, an int will hold number, and char will hold suit
    int randomNum = randomGen();    //Weput the random number into a variable so we can use it in multiple instances
    pullNum = cardNum[randomNum];   //our random number decides which card is pulled
    while(cardNum[pullNum] == 0){   //while loop checks is card = 0, if it does ir has been pulled and we run our generator again
        randomNum = randomGen();
        pullNum = cardNum[randomNum];
    }
    pullSuit = cardSuit[randomNum]; //since our arrays are parallel our suit is decided by which array index is pulled
    cardNum[randomNum] = 0;             //We set the card that was pulled to 0 to ensure it isn't pulled again
}

int randomGen(){
    return (rand() % 52);
}
