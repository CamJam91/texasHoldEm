#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void moneyDisplay(int, int, int);

int main(){
   int pool = 100,
   playerMoney = 190,
   stake = 40;
   moneyDisplay(pool, playerMoney, stake);
   return 0;
}

void moneyDisplay(int pool, int stake, int money){
    cout << "Money: " << setw(10) << "$" << money << endl; //display player money
    cout << "Pool: " << setw(11) << "$" << pool << endl; //current pool
    cout << "Stake: " << setw(10) << "$" << stake << endl; //current bet if any

}