#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//Creating array that holds 52 card deck
//Creating player hand and opponent hand and filling them with deck array values. 

char DECK_SUIT[52] = {'H','H','H','H','H','H','H','H','H','H','H','H','H','C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','S','S','S','S','S','S','S','S','S','S','S','S','S',};//Suits. H = hearts and so on
int DECK_NUM[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};   //the 1 represents Ace and the 11, 12, 13 represent jack, queen, king respectively
        //The values that hold the deck of cards, they are parallel arrays

char cardPullSuit = 'a';
int cardPullNum = 0;   //This is basically the card that gets pulled from out deck, its purpose is so that we can pass
//an array value to our player hands/river. Since these variables differ we need an intermediary card that can be reset and
//reassigned at will. Like the card variables, this needs to be seperated into Num and Suit.

void draw(int cardNum[], char cardSuit[]);  //The function that randomly assigns our cards from the array to cardPull
int randomGen();    //for generating our random number to use in card draw

int main(){
   //Random number generator
   unsigned seed = time(0);
   srand(seed);

   //2 variables equal a single card in hand, one for number and one for suit
        //Player hand
   int
   playerCardLeftNum = 0,
   playerCardRightNum = 0,
   opponentCardLeftNum = 0,
   opponentCardRightNum = 0;
   
   char
   playerCardLeftSuit = 'a',
   playerCardRightSuit = 'a',
   opponentCardLeftSuit = 'a',
   opponentCardRightSuit = 'a';

   //Cards are pulled. Similar to real poker we draw to pick each card. 
   draw(DECK_NUM, DECK_SUIT);   //player left
   playerCardLeftNum = cardPullNum;
   playerCardLeftSuit = cardPullSuit;
   draw(DECK_NUM, DECK_SUIT);   //player right
   playerCardRightNum = cardPullNum;
   playerCardRightSuit = cardPullSuit;
   draw(DECK_NUM, DECK_SUIT);   //opponent left
   opponentCardLeftNum = cardPullNum;
   opponentCardLeftSuit = cardPullSuit;
   draw(DECK_NUM, DECK_SUIT);
   opponentCardRightNum = cardPullNum;
   opponentCardRightSuit = cardPullSuit;

   return 0;
}

void draw(int cardNum[], char cardSuit[]){
    int randomNum = randomGen();    //We put the random number into a variable so we can use it in multiple instances
    cardPullNum = cardNum[randomNum];   //our random number decides which card is pulled
    while(cardNum[cardPullNum] == 0){   //while loop checks is card = 0, if it does ir has been pulled and we run our generator again
        randomNum = randomGen();
        cardPullNum = cardNum[randomNum];
    }
    cardPullSuit = cardSuit[randomNum]; //since our arrays are parallel our suit is decided by which array index is pulled
    cardNum[randomNum] = 0;             //We set the card that was pulled to 0 to ensure it isn't pulled again
}

int randomGen(){
    return (rand() % 52);
}