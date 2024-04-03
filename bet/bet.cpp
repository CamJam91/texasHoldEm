#include <iostream>
#include<string>
using namespace std;

int bet(int&, int&);

int main(){
    //stake is an int that exists in main. It will be added to int pool but needs to be a seperate value so that it can be used in reference for calls and raises
    int stake = 0;
    int playerMoney = 100;
    int pool = 0;
    //test
    int testOption = 0;
    do{
        cout << "Lets test this bet function. 1. to engage and 2. to quit" << endl;
        cin >> testOption;
        if (testOption == 1){
            bet(stake, playerMoney);
        }
    }while (testOption < 1 || testOption > 2);
    
}

int bet(int& stake, int& money){ //pass stake as a reference so we can add to it. Pass player or opponent money to affect it
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
            stake+=bet; //player "money" is put into stake
            break; //if this is call the math here doesn't matter as stake is 0 and nothing is + or -
        case 3: return 3;   //game needs to immediatley end, 3 will be used to clean up
    }
    return 0;
}