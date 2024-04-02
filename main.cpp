#include<iostream>
using namespace std;

void draw();
void deal();
void bet();
int main(){
    int userOption = 0; //option to deal or quit
    do{ 
        cout << "Let's play some Texas Hold 'em!" << endl
        << "1. Deal" << endl << "2. Quit" << endl;
        cin >> userOption;
        if (userOption == 1){
            deal();
            play();
            }
    }
    while (userOption != 1);
} 

void draw(){
    cout << "draw unique num and suit card";
}

void deal(){
    draw();
    cout << "assign to player hand";
    draw();
    cout << "assign to player hand";
    draw();
    cout << "assign to opponent hand";
    draw();
    cout << "assign to opponent hand";
}

void flop(){
    draw();
    cout << "assign to player & opponent hand";
    draw();
    cout << "assign to player & opponent hand";
    draw();
    cout << "assign to player & opponent hand";
}

void street(){
    draw();
    cout << "assign to player & opponent hand";
}

void play(){
    static int bet = 0;
    int userChoice = 0;
    if (bet == 0)
    cout << "1.fold \n2.check \n3.bet";
    cin >> userChoice; 
    switch (userChoice){
        case 1: fold();
                break;
        case 2: cout << "Check";
                //assign bet to pool
                static int bet = 0;
                break;
        case 3: cout << bet;
                break;
    }
}

void fold(){
    cout << "Fold";

}
void bet(){
    cout <<"Bet how Much?: ";
    
}