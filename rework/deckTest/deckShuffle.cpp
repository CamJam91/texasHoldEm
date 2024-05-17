#include<iostream>
using namespace std;

struct Card{
    int cardNum;
    char suit;
};

void shuffler(Card[], int);
int randomGen(int);
void swap(int&, int&);

int main(){
    unsigned seed = time(0);
    srand(seed);

    const int DECKSIZE = 12;
    Card Deck[DECKSIZE];

    //fill deck
    for (int count = 0;count < DECKSIZE; count++){
        Deck[count].cardNum = count + 1;
        Deck[count].suit = 'H';
    }
    //show deck
    for (int count = 0; count < DECKSIZE; count++){
        cout << "Card" << count + 1 << ": " << Deck[count].cardNum << Deck[count].suit << endl;
    }
    //shuffle deck
    shuffler(Deck, DECKSIZE);
    //reshow deck
    for (int count = 0; count < DECKSIZE; count++){
        cout << "Card" << count + 1 << ": " << Deck[count].cardNum << Deck[count].suit << endl;
    }
}

void shuffler(Card deck[], int deckSize){
   for (int count = 0; count < deckSize; count++){
    int randomNum = randomGen(deckSize);
    swap(deck[count], deck[randomNum]);
   } 
}

int randomGen(int deckSize){
    return (rand() & deckSize);
}

void swap (int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}


//Here is a much better and simpler way to shuffle a virtual deck. We can see that now we use a struct 
//to create a Card data type. Instead of using the random number generator to figure a card to pull and checking if that card == 0
//or replacing it with zero, we simply use the random number generator to start at the first card and swap it with a random
//number. Then we pull the cards in order. This way we will only ever change a card position equal to the exact amount
//of cards in the deck. And we only ever pull in array order. 