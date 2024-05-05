#include<iostream>
#include<vector>
using namespace std;

bool flush(vector<char>);
void flushCheck(vector<char>, vector<char>, vector<int>, vector<int>, int, int&);
void highCheck(vector<int>, vector<int>, int, int&);
int highCard(vector<int>handNum);

int main(){
    vector<int> playerHandNum = {1,11,5,6,9,8,6,6,8};
    vector<int> opponentHandNum = {9,11,5,6,9,8,6,6,8};
    vector<char> playerHandSuit = {'D','H','D','H','D','D','S'};
    vector<char> opponentHandSuit = {'H','H','D','D','D','D','S'};

    int pool = 90,
    playerMoney = 0;

    flushCheck(playerHandSuit, opponentHandSuit, playerHandNum, opponentHandNum, pool, playerMoney);
    cout << "Player money: " << playerMoney << endl;


}

void flushCheck(vector<char>playerHand, vector<char>opponentHand,vector<int>playerHandNum, vector<int>opponentHandNum, int pool, int& playerMoney){
    bool playerFlush = flush(playerHand);
    bool opponentFlush = flush(opponentHand);

    if(playerFlush && !opponentFlush){
        cout << "You win with a Flush!" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
    }else if(opponentFlush && !playerFlush){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
    }else if(playerFlush && opponentFlush){
        highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
    }
    //This function calls the flush function for both hands and will trigger a win or loss if either hand has an exlusive flush
    //If both have a flush, it calls highCard and decides the winner based on that, which is why the handNum vectors are passed.
    //If neither have a flush it should do nothing. 
}

bool flush(vector<char>handSuit){
    bool flush = false;
    for (int card = 0; card < 3 && flush == false; card++){   //if a flush isnt found after card 3, flush is impossible
        int match = 0;
        for (int nextCard = card + 1; nextCard < 7; nextCard++){
            if (handSuit[card] == handSuit[nextCard])
                match++;
        }
        if (match >= 4)
            flush = true;
    }
    return flush;
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