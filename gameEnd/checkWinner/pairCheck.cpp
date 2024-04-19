#include<iostream>
#include<vector>
using namespace std;


void highCheck(vector<int>, vector<int>, int, int&);
int highCard(vector<int>);
int pairs(vector<int>);
void pairCheck(vector<int>, vector<int>, int, int&);

int main(){
    int pool = 90,
    playerMoney = 0;

    vector<int>playerHandNum = {1,4,2, 3, 2, 4, 4};
    vector<int>opponentHandNum = {5,3,12, 2, 6, 4, 4};

    pairCheck(playerHandNum, opponentHandNum, pool, playerMoney);

    cout << "Player money: " << playerMoney << endl;
    
}

void pairCheck(vector<int>playerHandNum, vector<int>opponentHandNum, int pool, int& playerMoney){
    int playerPair = pairs(playerHandNum);
    int opponentPair = pairs(opponentHandNum);

    if(playerPair > opponentPair){
        cout << "You win with " << playerPair << " pair" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
    }else if(opponentPair > playerPair){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
    }else if(playerPair == opponentPair){
        highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
    }
}

int pairs(vector<int> handNum){
    int numberofPairs = 0;
    for (int card = 0; card < 6; card++){ //we dont need to check the lat card it will already be checked on next to last
        for (int nextCard = card + 1; nextCard < 7; nextCard++){ //keeps card to check the same but loops through every other one
            if (handNum[card] == handNum[nextCard])
                numberofPairs++;
        }
    }
    return numberofPairs;
}

void highCheck(vector<int> playerHandNum, vector<int>opponentHandNum, int pool, int& playerMoney){ //playerMoney needs to be passed as a reference so we can add to it
    int playerHigh = highCard(playerHandNum);
    int opponentHigh = highCard(opponentHandNum);//return highest value card
    
    if (playerHigh > opponentHigh){
        cout << "You win with a High Card!" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
        
    }else if(opponentHigh > playerHigh){
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