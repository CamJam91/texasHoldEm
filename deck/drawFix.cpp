//!!!!This is a test function for hands. It deals both hands and the river automatically and checks for a winner!!!!

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void draw(int&, char&);  //The function that randomly assigns our cards from the array to cardPull
int randomGen();    //for generating our random number to use in card draw

void deal(); //calls draw function and assigns values to hands
void flop();  //These are the same as draw except flop adds three cards nad street adds one.
void street(); //street is used for fourth street and fifth street (river)

//Hands
void highCard(vector<int>&, vector<int>&);
void pairCheck(vector<int>&, vector<int>&);

        //The values that hold the deck of cards, they are parallel arrays



int main(){
    char DECK_SUIT[52] = {'H','H','H','H','H','H','H','H','H','H','H','H','H','C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','S','S','S','S','S','S','S','S','S','S','S','S','S',};//Suits. H = hearts and so on
    int DECK_NUM[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};   //the 1 represents Ace and the 11, 12, 13 represent jack, queen, king respectively
    
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

    //Random number generator
   unsigned seed = time(0);
   srand(seed);

    //Here is our test, every function is called to fill both hands with 2 personal cards and 5 community cards
   deal(); // call deal function to fill hands, bc this is a void function
    //and it affects variables, said variables must live outside main()
   flop();
   street();
   street();

   //Output each card value for reference
   cout << "Player hand num and suit: " << endl << "Card 1: "<< playerHandNum[0] << playerHandSuit[0] << endl
   << "Card 2: " << playerHandNum[1] << playerHandSuit[1] << endl
   << "Community Card 1: " << playerHandNum[2] << playerHandSuit[2] << endl
   << "Community Card 2: " << playerHandNum[3] << playerHandSuit[3] << endl
   << "Community Card 3: " << playerHandNum[4] << playerHandSuit[4] << endl
   << "Community Card 4: " << playerHandNum[5] << playerHandSuit[5] << endl
   << "Community Card 5: " << playerHandNum[6] << playerHandSuit[6] << endl;
   
   cout << "Opponent hand num and suit: " << endl << "Card 1: " << opponentHandNum[0] << opponentHandSuit[0] << endl
   << "Card 2: " << opponentHandNum[1] << opponentHandSuit[1] <<endl
   << "Community Card 1: " << opponentHandNum[2] << opponentHandSuit[2] << endl
   << "Community Card 2: " << opponentHandNum[3] << opponentHandSuit[3] << endl
   << "Community Card 3: " << opponentHandNum[4] << opponentHandSuit[4] << endl
   << "Community Card 4: " << opponentHandNum[5] << opponentHandSuit[5] << endl
   << "Community Card 5: " << opponentHandNum[6] << opponentHandSuit[6] << endl;
   highCard(playerHandNum, opponentHandNum);

   //test pair
   pairCheck(playerHandNum, opponentHandNum);


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

void flop(){
    draw(DECK_NUM, DECK_SUIT);   //shared card, it goes into player hand and opponent hand
    playerHandNum.push_back(cardPullNum); //pushes value to empty vector
    playerHandSuit.push_back(cardPullSuit); //pushes value to empty vector
    opponentHandNum.push_back(cardPullNum); 
    opponentHandSuit.push_back(cardPullSuit);
     
    draw(DECK_NUM, DECK_SUIT);   //second card
    playerHandNum.push_back(cardPullNum);
    playerHandSuit.push_back(cardPullSuit);
    opponentHandNum.push_back(cardPullNum); 
    opponentHandSuit.push_back(cardPullSuit);

    draw(DECK_NUM, DECK_SUIT);   //third card
    playerHandNum.push_back(cardPullNum);
    playerHandSuit.push_back(cardPullSuit);
    opponentHandNum.push_back(cardPullNum); 
    opponentHandSuit.push_back(cardPullSuit);
}

void street(){
    draw(DECK_NUM, DECK_SUIT);   //only one card is drawn and shared
    playerHandNum.push_back(cardPullNum);
    playerHandSuit.push_back(cardPullSuit);
    opponentHandNum.push_back(cardPullNum); 
    opponentHandSuit.push_back(cardPullSuit);
}
int randomGen(){
    return (rand() % 52);
}

void highCard(vector<int>&playerHand, vector<int>&opponentHand){
    int playerHigh = 0; //high cards are stored in these variables
    int opponentHigh = 0;
    for (int card : playerHand){   //all cards need to be checked, this may or may not be full 7 
        if (playerHandNum[card] > playerHigh){ //checks each card to make sure playerHigh is highest in array
            playerHigh = playerHandNum[card];
        }
        if (opponentHandNum[card] > opponentHigh){ //same amount of cards in hand so rangeloop applies
            opponentHigh = opponentHandNum[card];
        }
    }
     
    if (playerHigh > opponentHigh){
        //player win;   //placeholder
    }else if(opponentHigh > playerHigh){
        //player lose;
    }else{
        //splti pot, 2 cards are equal
    }
}

void pairCheck(vector<int>&playerHand, vector<int>&opponentHand){
    int playerPair = 0,
    opponentPair = 0;
    for (int card : playerHand){
        if (playerHand[card] == playerHand[card+1]){
            playerPair = playerHand[card];       
        }
        if (opponentHand[card] == opponentHand[card+1]){
            playerPair = opponentHand[card];
        }
    }
    if (playerPair > opponentPair){
        //player wins
        cout << "Player Wins" << endl; //driver
    }else if (opponentPair > playerPair){
        //opponent wins
        cout << "Opponent wins" << endl; //driver
    }else if (opponentPair > 0 && opponentPair == playerPair){
        cout << "PAir match";
    }
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   