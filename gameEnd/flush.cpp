#include<iostream>
#include<vector>
using namespace std;

bool flush(vector<char>);
int main(){
    //test
    vector<char>playerHandSuit = {'H','H','D','D','S','S','D'};
    vector<char>opponentHandSuit = {'H','H','D','S','H','H','H'};
    bool playerFlush = flush(playerHandSuit);
    bool opponentFlush = flush(opponentHandSuit);
    cout << "Player flush: " << playerFlush << endl;
    cout << " Opponent flush: " << opponentFlush << endl;
}

bool flush(vector<char>handSuit){
    bool flush = false;
    for (int card = 0; card < 3 && flush == false; card++){   //if a flush isnt found after card 3, flush is impossible
        int match = 0;
        for (int nextCard = card + 1; nextCard < 7; nextCard++){
            if (handSuit[card] == handSuit[nextCard])
                match++;
        }
        if (match >= 4)
            flush = true;
    }
    return flush;
}