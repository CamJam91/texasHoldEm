#include<iostream>
using namespace std;

struct card{
    int cardNumber;
    char suit;
};

int main(){
        //this is the basic of making a card, but we will need to make an array of cards
    card denverCard;
    denverCard.cardNumber = 10;
    denverCard.suit = 'H';
    cout << "Denvers card: " << denverCard.cardNumber << denverCard.suit << endl; 
    
        //now we will make an array that holds two cards
    const int handSize = 2;
    card rishellesCard[handSize];
    rishellesCard[0].cardNumber = 3;
    rishellesCard[0].suit = 'D';
    rishellesCard[1].cardNumber = 5;
    rishellesCard[1].suit = 'S';
        //lets display
    cout << "Rishelles hand: ";
    for (int count = 0; count < handSize; count++){
        cout << "Card " << count + 1 << ": " << rishellesCard[count].cardNumber << rishellesCard[count].suit << endl;
    }
    return 0;
}