#include <iostream>
using namespace std;

int bet();

int main(){}

int bet(){
    int stake;  //will be added to pool when bet is done
    int userBet; //This holds bet to be added to stake. It ensures proper bet amount is entered
    int userOption;
    if (stake == 0){    //Check option is effectively the same as call since checking a 0 stake has no effect.
    //raise is effectively the same as bet, this if statment just outputs terms that make more sense in context to the player
        cout << "1.Check \n2.Bet \n3.Fold" << endl;
        while (userOption < 1 || userOption > 3){   //ensure that option is valid
            cout << "1.Check \n2.Bet \n3.Fold" << endl;
            cin >> userOption;
        }
        }else{
            cout << "1.Call \n2.Raise \n 3.Fold" << endl;   //betting menu for an already existing bet
            while (userOption < 1 || userOption > 3){
                cout << "1.Call \n2.Raise \n 3.Fold" << endl;
                cin >> userOption;
            }
        }
    switch (userOption){
        case 1: stake += userBet;
            break;
        case 2: while (userBet == 0){
            cout << "How much would you like to bet? ";
            cin >> userBet;
        }
        stake+=userBet;
        break;
        case 3: exit(1); //This is a quick fix, we want an alternative that wont exit program entirely
    }
    return stake;   //We need to return stake to main so it can be added to the pool and bet can be run again if stakes are still on table

        
    }