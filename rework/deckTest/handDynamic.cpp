#include<iostream>
using namespace std;

struct card{
    int cardNumber;
    char suit;
};

const int handSize = 2;

int main(){
    card* playerHand = nullptr;
    playerHand = new card[handSize];

    playerHand->cardNumber = 12;
    playerHand->suit = 'H';
    (playerHand + 1)->cardNumber = 10; //make sure not to dereference with * since we need ti acces pointer not value
    (playerHand + 1)->suit = 'D';

    cout << "Hand: " << playerHand[0].cardNumber << playerHand[0].suit
    << " " << (playerHand + 1)->cardNumber << (playerHand + 1)->suit << endl;

    delete[] playerHand;
    return 0;
}