#include<iostream>
#include<vector>
using namespace std;

void draw(int cardNum[], char cardSuit[]);  //The function that randomly assigns our cards from the array to cardPull
int randomGen();    //for generating our random number to use in card draw
void deal(); //calls draw function and assigns values to hands

char DECK_SUIT[52] = {'H','H','H','H','H','H','H','H','H','H','H','H','H','C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','S','S','S','S','S','S','S','S','S','S','S','S','S',};//Suits. H = hearts and so on
int DECK_NUM[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};   //the 1 represents Ace and the 11, 12, 13 represent jack, queen, king respectively
        //The values that hold the deck of cards, they are parallel arrays

char cardPullSuit = 'a';
int cardPullNum = 0;   //This is basically the card that gets pulled from out deck, its purpose is so that we can pass
//an array value to our player hands/river. Since these variables differ we need an intermediary card that can be reset and
//reassigned at will. Like the card variables, this needs to be seperated into Num and Suit.

//These vectors are parallel and should always be the same size
    //player hand vectors
vector<int> playerHandNum; 
vector<char> playerHandSuit;
    //oponent hand vectors
vector<int> opponentHandNum; 
vector<char> opponentHandSuit;

int main(){

   //Random number generator
   unsigned seed = time(0);
   srand(seed);

   deal(); // call deal function to fill hands, bc this is a void function
   //and it affects variables, said variables must live outside main()
   

   //Test
   cout << "Test: " << endl << "CardPullNum: " << cardPullNum << endl
   << "cardPullSuit: " << cardPullSuit << endl;
   cout << "Player hand num and suit: " << playerHandNum[0] << playerHandSuit[0] << endl
   << "plc2" << playerHandNum[1] << playerHandSuit[1] << endl
   << "opc1" << opponentHandNum[0] <<opponentHandSuit[0] << endl
   << "oppc2" << opponentHandNum[1] << opponentHandSuit[1] <<endl;


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

void deal(){
    draw(DECK_NUM, DECK_SUIT);   //player card1
    playerHandNum.push_back(cardPullNum); //pushes value to empty vector
    playerHandSuit.push_back(cardPullSuit); //pushes value to empty vector
    draw(DECK_NUM, DECK_SUIT);   //player card2
    playerHandNum.push_back(cardPullNum); 
    playerHandSuit.push_back(cardPullSuit);
   
    draw(DECK_NUM, DECK_SUIT);   //opponent card1
    opponentHandNum.push_back(cardPullNum); 
    opponentHandSuit.push_back(cardPullSuit);
    draw(DECK_NUM, DECK_SUIT);   //opponent card2
    opponentHandNum.push_back(cardPullNum); 
    opponentHandSuit.push_back(cardPullSuit);
}

int randomGen(){
    return (rand() % 52);
}

