#include<iostream>
#include<vector>
using namespace std;

int pairs(vector<int>);
void draw(int&, int&);
int main(){
    vector<int> playerHand = {1,3,10,3,1};
    vector<int> opponentHand = {11,11,10,10,1};

    int playerPairs = pairs(playerHand);
    int opponentPairs = pairs(opponentHand);

    int stake = 10;
    int playerMoney = 100;

    if (playerPairs == 2){
        if(opponentPairs == 2){
            draw(stake, playerMoney);
        }else{
            cout << "You win" << endl
            << "Stake won: $" << stake << endl;
            stake += playerMoney;
            stake = 0;
        }
    }else if(opponentPairs == 2){
        cout << "You lose" << endl
        << "Stake lost: $" << stake << endl;
        stake = 0;
    }    
    cout << "Player Money: " << playerMoney << endl;
    cout << "Stake: " << stake << endl;
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

void draw(int& stake, int& playerMoney){
    cout << "You Win!" << endl << "Stake won: " << (stake/2);
    playerMoney+=(stake/2);
    stake = 0;
}