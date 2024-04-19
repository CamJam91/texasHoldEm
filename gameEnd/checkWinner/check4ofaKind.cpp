#include<iostream>
#include<vector>
using namespace std;


void highCheck(vector<int>, vector<int>, int, int&);
int highCard(vector<int>);
bool fourKind(vector<int>);
void fourCheck(vector<int>, vector<int>, int, int&);

int main(){
    int pool = 90,
    playerMoney = 0;

    vector<int>playerHandNum ={3,2,5,12,2,6,2,};
    vector<int>opponentHandNum ={12,12,12,12,2,6,2};

    fourCheck(playerHandNum, opponentHandNum, pool, playerMoney);

    cout << "Player money: " << playerMoney << endl;
}

void fourCheck(vector<int>playerHandNum, vector<int>opponentHandNum, int pool, int& playerMoney){
    bool playerfourKind = fourKind(playerHandNum);
    bool opponentfourKind = fourKind(opponentHandNum);

    if(playerfourKind && !opponentfourKind){
        cout << "You win with a Four of a Kind!" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
    }else if(opponentfourKind && !playerfourKind){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
    }else if(playerfourKind && opponentfourKind){
        highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
    }
}

bool fourKind(vector<int> handNum){
    bool fourKind = false;
    for (int card = 0; card <= 4 && fourKind == false; card++){ //loop stops at card 4 bc a three match would be impossible
        int matches = 0; //if this == 3 the we have found 4 cards of the same number, careful of 1 off error
        for (int nextCard = card + 1; nextCard < 7; nextCard++){    //compare all 7 cards to target card
            if (handNum[card] == handNum[nextCard])
                matches++;
        }
        if (matches == 3)
            fourKind = true; //after each card is checked against every other we see if we have 3 of a kind
    }
    return fourKind;
        //The first for loop is for picking every card(except last 2) to compare, the nested is for looping through every
        //other card and comparing it to the first. Matches is defined inside outer loop so it resets before actual card
        //comparison. if a match is found we must change our bool terminator before another loop starts
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