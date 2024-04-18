#include<iostream>
#include<vector>
using namespace std;

void handDisplay(vector<int>, vector<char>, int);

int main(){
    vector<int>handNum = {10,11,13,1, 12};
    vector<char>handSuit = {'H','D','D','H','S'};
    handDisplay(handNum, handSuit, 5);
    
}

void handDisplay(vector<int>handNum, vector<char> handSuit, int handSize){

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
        cout << endl;
    if (handSize > 2){  //This is the loop to display community cards which inside the program is apart of the players hand. since the size od community cards change
                        //we use handSize parameter
        cout << "Community: " << endl;
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
                    cout << endl;
                    }

    /*This functino does two things, 
    1. It loops through the players hand, showing them their cards. There are two loops because 1. the player should view
    the "community" cards as separate from their hand and the amount of community cards may vary but the players 2 unique hand cards stays the same."
    2. It displays any 1, 11, 12,13 as am A, J, Q, K, respectively. So the playher can see the cards as their proper face but we can work with them as 
    a number. This function is generally combined with money display.*/
}