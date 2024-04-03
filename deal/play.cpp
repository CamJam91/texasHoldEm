#include <iostream>
#include <vector>
using namespace std;

void draw(int (&cardNum)[52], char (&cardSuit)[52], vector<int>&handNum, vector<char>&handSuit); //2 vectors are referenced: the number of the card and the suit, an int will hold number,
//and char will hold suit
int randomGen(); //calls and returns nrandom number

int main(){
    //for the random number generator
    unsigned seed = time(0);
    srand(seed);

        //deck arrays
    char DECK_SUIT[52] = {'H','H','H','H','H','H','H','H','H','H','H','H','H','C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','S','S','S','S','S','S','S','S','S','S','S','S','S'};//Suits. H = hearts and so on
    int DECK_NUM[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};   //the 1 represents Ace and the 11, 12, 13 represent jack, queen, king respectively
        //hand vectors
    //These vectors are parallel and should always be the same size, their initial size is 0 and will only need to be expanded to 7
        //player hand vectors
    vector<int> playerHandNum; 
    vector<char> playerHandSuit;
        //oponent hand vectors
    vector<int> opponentHandNum; 
    vector<char> opponentHandSuit;
    int userOption = 0;
    do {
        cout << "1.Deal \n2.Quit\n";
        cin >> userOption;
        if (userOption == 1){ 
                //player hand
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                //opponent hand
            draw(DECK_NUM, DECK_SUIT, opponentHandNum, opponentHandSuit);
            draw(DECK_NUM, DECK_SUIT, opponentHandNum, opponentHandSuit);
            for (int count = 0; count < 2; count++){
                cout << playerHandNum[count] << playerHandSuit[count] << " ";
            }
            cout << endl;
            //bet() function here;
            //flop
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                //since these cards are community we assign the values to opponent array
            for (int hand = 2; hand < 5; hand++){
                int numFill = playerHandNum[hand]; //fill variable with player card num value
                int suitFill = playerHandSuit[hand]; //fill variable with player card suit value
                opponentHandNum.push_back(numFill);
                opponentHandSuit.push_back(suitFill);   //share values with opponent hand
            }
            //bet() function here;
            //fourth street
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);   //draw another community card
                int numFill = playerHandNum[5]; //fill variable with player card num value
                int suitFill = playerHandSuit[5]; //fill variable with player card suit value
                opponentHandNum.push_back(numFill);
                opponentHandSuit.push_back(suitFill);   //share values with opponent hand
            //bet() function here;
            //river
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);   //draw another community card
                numFill = playerHandNum[6]; //fill variable with player card num value
                suitFill = playerHandSuit[6]; //fill variable with player card suit value
                opponentHandNum.push_back(numFill);
                opponentHandSuit.push_back(suitFill);   //share values with opponent hand
            //bet() function here;
            //test
            cout << "player hand: " << endl;
            for (int count = 0; count < 7; count++){
                cout << playerHandNum[count] << playerHandSuit[count] << " ";
            }
            cout << endl;
            cout << "opponent hand: " << endl;
            for (int count = 0; count < 7; count++){
                cout << opponentHandNum[count] << opponentHandSuit[count] << " ";
            }
            cout << endl;
        }
    }while(userOption != 2);

}

void draw(int (&cardNum)[52], char (&cardSuit)[52], vector<int>&handNum, vector<char>&handSuit){ //2 vectors are referenced: the number of the card and the suit, an int will hold number, and char will hold suit
    int randomNum = randomGen();    //Weput the random number into a variable so we can use it in multiple instances
    int pullNum = 0;
    pullNum = cardNum[randomNum];   //our random number decides which card is pulled
    while(pullNum == 0){   //while loop checks is card = 0, if it does ir has been pulled and we run our generator again
        randomNum = randomGen();
        pullNum = cardNum[randomNum];
    }
    handNum.push_back(pullNum); //since our arrays are parallel our suit is decided by which array index is pulled
    handSuit.push_back(cardSuit[randomNum]);        //since number and suit are parallel arrays we use the same number for suit and no need to erase the value in the actual array, if we pull from our num array correctly this will always be correct
    cardNum[randomNum] = 0;             //We set the card that was pulled to 0 to ensure it isn't pulled again
}


int randomGen(){
    return (rand() % 52);
}




/* Problem: When I run my test for assigning hands 0's are being pulled. 
Test: 
    1. Since we are able to affect arrays in functions by referencing the address in our parameters we can delete the pull variables but for now we will use them for testing
    2. call draw function and assign the cout pull values 50 times
    3. if 2 doesnt work try deleting the while loop and and moving the while loop into main\
    fixed: while loop had incorrect parameters

    simplifying:
    1. erase pull variables and replace with hand vects
    fixed: moved pullNum to inside function
    */
    
