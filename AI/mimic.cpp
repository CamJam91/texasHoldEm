#include<iostream>
#include<vector>
using namespace std;


void handMimic(vector<int>, vector<char>, vector<int>&, vector<char>&, int);

int main(){

    vector<int> playerHandNum = {3,11,12,4,5,7,11}; 
    vector<char> playerHandSuit = {'H','H','S','D','H','S','S'};
        //opponent hand
    vector<int> opponentHandNum = {4,12}; 
    vector<char> opponentHandSuit = {'D','D'};

    handMimic(playerHandNum,playerHandSuit, opponentHandNum, opponentHandSuit, 3);
    handMimic(playerHandNum,playerHandSuit, opponentHandNum, opponentHandSuit, 4);
    handMimic(playerHandNum,playerHandSuit, opponentHandNum, opponentHandSuit, 5);
    handMimic(playerHandNum,playerHandSuit, opponentHandNum, opponentHandSuit, 6);
    handMimic(playerHandNum,playerHandSuit, opponentHandNum, opponentHandSuit, 7);
    for (int card = 0; card < 7; card++){
        cout << "Card " << card + 1<< ": " << opponentHandNum[card] << opponentHandSuit[card] << endl;
    }

}

void handMimic(vector<int>playerNum, vector<char>playerSuit, vector<int>&opponentNum, vector<char>&opponentSuit, int missing){//The first 2 vectors are read only but the second are changed so we pass a reference to vector address
    //since flop and street are community cards they need to be copied into opponent hand
    //the missing parameter is where we pass the subscript of the community cards that we need to copy
    int numFill;
    char suitFill;   //interum variables to hold hand values
    numFill = playerNum[missing-1]; 
    suitFill = playerSuit[missing-1];
    opponentNum.push_back(numFill);
    opponentSuit.push_back(suitFill);   //push values to opponent vector
    //This function takes in the parallel player hand arrays and the parallel opponent hand arrays. It also takes the index that needs to be copied. 
    //Because it works with one index at a time it needs to be called for every card that needs copied.  
}