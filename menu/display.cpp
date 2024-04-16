#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void display(vector<int>, vector<char>, int, int, int, int);

int main(){
    vector<int>playerHandNum = {1,5,12,11,13};
    vector<char>playerHandSuit = {'D','D','H','S','S'};
    int money = 100,
    pool = 200,
    stake = 30;

    display(playerHandNum, playerHandSuit, pool, stake, 5, money);
}

void display(vector<int>handNum, vector<char> handSuit, int pool, int stake, int handSize, int money){
    //this function has a lot of parameters as it displays all info to player except opponents hand
    cout << "Money: " << setw(10) << "$" << money << endl; //display player money
    cout << "Pool: " << setw(11) << "$" << pool << endl; //current pool
    cout << "Stake: " << setw(10) << "$" << stake << endl; //current bet if any

    //These two for loop sare the same but one is formatted as a hand and the other as community cards. They make the 
    //ints appear as face Cards to the player. 
    cout << "Hand:" << endl;
    for (int card = 0; card < 2; card++){
            switch (handNum[card]){
                case 13: cout << "K" << handSuit[card] << " ";
                break;
                case 12: cout << "Q" << handSuit[card] << " ";
                break;
                case 11: cout << "J" << handSuit[card] << " ";
                break;
                case 1: cout << "A" << handSuit[card] << " ";
                break;
                default: cout << handNum[card] << handSuit[card] << " ";} //if card isnt a face just output it like normal
        }
    cout << endl << "Community: " << endl;
    for (int card = 2; card < handSize;card++){
         switch (handNum[card]){
                case 13: cout << "K" << handSuit[card] << " ";
                break;
                case 12: cout << "Q" << handSuit[card] << " ";
                break;
                case 11: cout << "J" << handSuit[card] << " ";
                break;
                case 1: cout << "A" << handSuit[card] << " ";
                break;
                default: cout << handNum[card] << handSuit[card] << " ";
                break;}
    }
    }