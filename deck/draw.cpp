#include <iostream>
#include <vector>
using namespace std;

void draw(int (&cardNum)[52], char (&cardSuit)[52], vector<int>&handNum, vector<char>&handSuit); //2 vectors are referenced: the number of the card and the suit, an int will hold number, and char will hold suit
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

    
    /* test :
    for (int i = 0; i < 20; i++){
        draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
    }
    for (int i = 0; i < 20; i++){
        cout << playerHandNum[i] << playerHandSuit[i] << endl;
    }
    return 0;
    */
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
    
