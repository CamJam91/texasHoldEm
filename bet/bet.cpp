#include <iostream>
#include<string>
using namespace std;

int bet(int&, int&, int&);
bool opponentBet(int&, int&);

int main(){
    //stake is an int that exists in main. It will be added to int pool but needs to be a seperate value so that it can be used in reference for calls and raises
    int stake = 0;
    int playerMoney = 100;
    int pool = 0;
    bool fold = false;
    //test
     do{
                fold = bet(stake, playerMoney, pool); //every draw is followed by a bet
                //bet works like our other void functions but it returns true if there is a fold
                if (!fold){ //if player folds dont trigger ai bet 
                    fold = opponentBet(stake, pool);  //ai function that will call check bet or fold
                }}while(stake!=0 && !fold);
}

int bet(int& stake, int& money,int& pool){ //pass stake as a reference so we can add to it. Pass player or opponent money to affect it
    int bet = 0; //This holds bet to be added to stake. It ensures proper bet amount is entered
    int userOption = 0;
    string betPrompt = "";  //This is so we can change prompt bsed on user input
    string userPrompt = ""; //changes prompt based on user user input for 
    
    if (stake == 0){
        userPrompt = "1.Check \n2.Bet \n3.Fold";}    //Check option is effectively the same as call since checking a 0 stake has no effect.
    //raise is effectively the same as bet, this if statment just outputs terms that make more sense in context to the player
    else{ userPrompt = "1.Call \n2.Raise \n3.Fold";}

    do {
        cout << userPrompt;
        cin >> userOption; //menu choice
    } while (userOption < 1 || userOption > 3);   //ensure that option is valid

    switch (userOption){
        case 1: money-=stake; //take money from player equal to stake amount
            stake += stake;   //adds doubles stake to mimic call.
            pool+=stake;
            stake =0;
            break;            //If this is a check then stake == 0 and expressoins don't change anything
        case 2: if (stake == 0){
            betPrompt = "How much would you like to bet?";
            }else{                //if stake != 0 then it is called raise not bet
                betPrompt = "How much would you like to raise?";
            }
            do {
                cout << betPrompt << "$1 - $" << money << endl;
                cin >> bet;
            }while(bet < 1 || bet > money); //0 or less bets arent allowed, neither is more than players money
            money-=bet; //player "pays" money
            stake+=bet;
            break; //if this is call the math here doesn't matter as stake is 0 and nothing is + or -
        case 3: 
            return true;   //game needs to immediatley end, 3 will be used to clean up
    }
    return false;
    /*This function works like a void function in that most of what it does is displaying something and affecting variables passed to it. It will
    always reutrn false(which will do nothing in main) unless there is a fold. It is meant to be run in a do while loop. When there is a raise/bet it affects
    stake. Which will keep the loop going. if a check or call is made stake is 0 so the loop stops. */
}

//this is a driver function for ai betting
bool opponentBet(int& stake, int& pool){
    cout << "opponent checks" << endl;
    stake+=stake;
    pool+=stake;
    stake = 0;
}