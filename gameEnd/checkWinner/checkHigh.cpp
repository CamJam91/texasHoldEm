#include<iostream>
#include<vector>
using namespace std;

int highCard(vector<int>);
void highCheck(vector<int>, vector<int>, int, int&);

int main(){
    int playerMoney = 0;
    int pool = 90;
    vector<int> playerHandNum = {1,10,11,3,11,9,9};
    vector<char> playerHandSuit = {};
    vector<int> opponentHandNum = {3,12,11,3,11,9,9};
    vector<char>opponentHandSuit ={};

    highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
    cout << "Pool: " << playerMoney << endl;
    cout << "PlayerMoney: " << playerMoney << endl;

}
void highCheck(vector<int> playerHandNum, vector<int>opponentHandNum, int pool, int& playerMoney){ //playerMoney needs to be passed as a reference so we can add to it
    int playerHigh = highCard(playerHandNum);
    int opponentHigh = highCard(opponentHandNum);//return highest value card
    
    if ((playerHigh > opponentHigh) || (playerHigh == 1 && opponentHigh != 1)){
        cout << "You win with a High Card!" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
        
    }else if((opponentHigh > playerHigh) || (playerHigh != 1 && opponentHigh == 1)){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
    }else{
        cout << "Draw" << endl << "Split: $" << pool/2 << endl;
        playerMoney+=(pool/2);
    }
    //This function uses the highCard function to check for a winner. There are three outcomes, a win
    //Wherein the player will be rewarded the pool, a draw where they are rewarded half the pool, and a
    //lose. Where nothing happens, meaning pool is lost. 
}
int highCard(vector<int> handNum){
    int highCard = 0;
    for (int card = 0; card < 7; card++){
        if (handNum[card] == 1)
            highCard = 14;
            else if(handNum[card] > highCard){
            //this if condition is clunky but its easier for other algorithms if ace is represented by 1
            //but we still have ot make it high
            highCard = handNum[card];
        }
    }
    return highCard;
        //Function to find the highest number except in this case 1 will resolve as the highest because it represents the Ace
} 