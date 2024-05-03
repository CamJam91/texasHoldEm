#include<iostream>
#include<vector>
#include<ctime>
#include<iomanip>
#include<fstream>
using namespace std;

//function prototypes

int menu(int);
int randomGen();
void draw(int (&cardNum)[52], char (&cardSuit)[52], vector<int>&handNum, vector<char>&handSuit);
void handMimic(vector<int>, vector<char>, vector<int>&, vector<char>&, int);
void handDisplay(vector<int>, vector<char>, int);
void moneyDisplay(int, int, int);
void handReset(vector<int>&, vector<char>&, int);
bool opponentBet(int&, int&);
bool bet(int&, int&, int&);
int highCard(vector<int>);
int pairs(vector<int>);
bool threeKind(vector<int>);
bool fourKind(vector<int>);
bool flush(vector<char>);
void highCheck(vector<int>, vector<int>, int&, int&);
void pairCheck(vector<int>, vector<int>, int&, int&);
void threeCheck(vector<int>, vector<int>, int&, int&);
void fourCheck(vector<int>, vector<int>, int&, int&);
void flushCheck(vector<char>, vector<char>, vector<int>, vector<int>, int&, int&);




int main(){
    //hand vectors
    //These vectors are parallel and should always be the same size, their initial size is 0 and will only need to be expanded to 7
        //player hand
    vector<int> playerHandNum; 
    vector<char> playerHandSuit;
        //opponent hand
    vector<int> opponentHandNum; 
    vector<char> opponentHandSuit;

    //for the random number generator
    unsigned seed = time(0);
    srand(seed);

    //variables for play
    int userOption = 0;     //for menu option
        //money
        //open wallet file for player money
    fstream wallet; //we will use this for reading and writing file
    wallet.open("wallet.txt", ios::in);
    int playerMoney;  //overall wallet
    wallet >> playerMoney;
    wallet.close();     //put int from wallet into player money then close


    //menu and play loop
    do{
        //deck arrays
        //These need to be initialized (reset) every deal
        char DECK_SUIT[52] = {'H','H','H','H','H','H','H','H','H','H','H','H','H','C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','S','S','S','S','S','S','S','S','S','S','S','S','S'};//Suits. H = hearts and so on
        int DECK_NUM[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};   //the 1 represents Ace and the 11, 12, 13 represent jack, queen, king respectively


        userOption = menu(playerMoney); //cout prompt and fills userOption
        int pool = 0,               //winning for eacah hand
        stake = 0,              //money added to pool
        popNumber = 0;          //this is how many cards are in hand and that we need to popback
        bool fold = false;      //if this is true, hand ends

        if (userOption == 1){
             //draw 2 cards for player hand
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                //draw 2 cards for opponent hand
            draw(DECK_NUM, DECK_SUIT, opponentHandNum, opponentHandSuit);
            draw(DECK_NUM, DECK_SUIT, opponentHandNum, opponentHandSuit);

            pool+= 10; //blind
            playerMoney-=10;
                //player options after draw
            handDisplay(playerHandNum, playerHandSuit,2);   //show player pertinent info
            moneyDisplay(pool, stake, playerMoney);
            do{
                fold = bet(stake, playerMoney, pool); //every draw is followed by a bet
                //bet works like our other void functions but it returns true if there is a fold
                if (!fold) //if player folds dont trigger ai bet 
                    fold = opponentBet(stake,pool);  //ai function that will call check bet or fold
                }while(stake!=0 && !fold);
                if (fold)
                   popNumber = 2; //used to reset hand vector 

            if (!fold){
                //Flop call draw function for 3 cards. Since they are community cards we only call draw for player hand
                //and copy them to opponent hand
                draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,3);//copy community cards to opponent hand
                handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,4);
                handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,5);
                
                handDisplay(playerHandNum, playerHandSuit,5);
                moneyDisplay(pool, stake, playerMoney);
                do{
                    fold = bet(stake, playerMoney, pool); //every draw is followed by a bet
                    //bet works like our other void functions but it returns true if there is a fold
                    if (!fold) //if player folds dont trigger ai bet 
                        fold = opponentBet(stake,pool);  //ai function that will call check bet or fold
                }while(stake!=0 && !fold);
                if (fold)
                   popNumber = 5; //used to reset hand vector 

                if (!fold){
                    //fourth street
                    draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                    handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,6);

                    handDisplay(playerHandNum, playerHandSuit,6);
                    moneyDisplay(pool, stake, playerMoney);
                    do{
                        fold = bet(stake, playerMoney, pool); //every draw is followed by a bet
                        //bet works like our other void functions but it returns true if there is a fold
                        if (!fold) //if player folds dont trigger ai bet 
                            fold = opponentBet(stake,pool);  //ai function that will call check bet or fold
                    }while(stake!=0 && !fold);
                }
                if (fold){
                   popNumber = 6;} //used to reset hand vector

                if (!fold){
                    //fifth street, "river"
                    draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                    handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,7);

                    handDisplay(playerHandNum, playerHandSuit,7);
                    moneyDisplay(pool, stake, playerMoney);
                    do{
                        fold = bet(stake, playerMoney, pool); //every draw is followed by a bet
                        //bet works like our other void functions but it returns true if there is a fold
                        if (!fold) //if player folds dont trigger ai bet 
                            fold = opponentBet(stake,pool);  //ai function that will call check bet or fold
                        }while(stake!=0 && !fold);
                }
                if (fold){
                   popNumber = 7;} //used to reset hand vector 
                if (!fold){ //now hands are checked for winner  
                    popNumber = 7;
                    handDisplay(playerHandNum, playerHandSuit,7);
                    cout << "Opponent ";
                    handDisplay(opponentHandNum, opponentHandSuit,2); //Show 2 opponent cards 

                    // call each winning algorithm to check each hand for winner
                    flushCheck(playerHandSuit, opponentHandSuit, playerHandNum, opponentHandNum, pool, playerMoney);
                    if (pool != 0)  //if a winner is declared then pool is set to 0 in each function. we should thne end 
                        fourCheck(playerHandNum, opponentHandNum, pool, playerMoney);
                    if (pool != 0)
                        threeCheck(playerHandNum, opponentHandNum, pool, playerMoney);
                    if (pool != 0)
                        pairCheck(playerHandNum, opponentHandNum, pool, playerMoney);
                    if (pool != 0)
                        highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
                    }
                handReset(playerHandNum, playerHandSuit, popNumber);//reset both hand vectors
                handReset(opponentHandNum, opponentHandSuit, popNumber);
            }
        }
    }while(userOption != 2);
    wallet.open("wallet.txt", ios::out);
    wallet << playerMoney;  //open wallet for output now, and replace int with new player money total

    return 0;
}



    /*****************************************************************************
     **************Menu and Display functions*************************************
    ******************************************************************************/
int menu(int money){
    int userOption;
    cout << "Money: $" << money << endl;
    cout << "1.Deal \n2.Quit\n";
    cin >> userOption;
    return userOption;
    //A simple function to kick off the gameplay loop
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

    /*This function does two things, 
    1. It loops through the players hand, showing them their cards. There are two loops because 1. the player should view
    the "community" cards as separate from their hand and the amount of community cards may vary but the players 2 unique hand cards stays the same."
    2. It displays any 1, 11, 12,13 as am A, J, Q, K, respectively. So the playher can see the cards as their proper face but we can work with them as 
    a number. This function is generally combined with money display.*/
}

void moneyDisplay(int pool, int stake, int money){
    cout << "Money: " << setw(10) << "$" << money << endl; //display player money
    cout << "Pool: " << setw(11) << "$" << pool << endl; //current pool
    cout << "Stake: " << setw(10) << "$" << stake << endl; //current bet if any

}




    /*****************************************************************************
     **************Deck and hand functions****************************************
    ******************************************************************************/

int randomGen(){
    return (rand() % 52);
    //random number generator will give us numbers from 0 -51 for use in pullinng cards from deck using draw function
}

void draw(int (&cardNum)[52], char (&cardSuit)[52], vector<int>&handNum, vector<char>&handSuit){ //2 vectors are referenced: the number of the card and the suit, an int will hold number, and char will hold suit
    int randomNum = randomGen();    //Weput the random number into a variable so we can use it in multiple instances
    int pullNum = 0;
    pullNum = cardNum[randomNum];   //our random number decides which card is pulled
    while(pullNum == 0){   //while loop checks is card = 0, if it does ir has been pulled and we run our generator again
        randomNum = randomGen();
        pullNum = cardNum[randomNum];
    }
    handNum.push_back(pullNum); //since our arrays are parallel our suit is decided by which array index is pulled
    handSuit.push_back(cardSuit[randomNum]);        //since number and suit are parallel arrays we use the same number for suit and no need to erase the value in the actual array, if we pull from our num array correctly this will always be correct
    cardNum[randomNum] = 0;             //We set the card that was pulled to 0 to ensure it isn't pulled again
        /*This function uses the randomGen function to create a number 0-51 and use that numbe to pull a cad from the deck.
        The index in the array that was pulled from is then replaced with a zero. This ensures that every card is unique. 
        the randomGen may and will give us numbers that have already been pulled from the array which is why we only push
        the cards when our card pulled != zero.*/
}


void handMimic(vector<int>playerNum, vector<char>playerSuit, vector<int>&opponentNum, vector<char>&opponentSuit, int missing){//The first 2 vectors are read only but the second are changed so we pass a reference to vector address
    //since flop and street are community cards they need to be copied into opponent hand
    //the missing parameter is where we pass the subscript of the community cards that we need to copy
    int numFill;
    char suitFill;   //interum variables to hold hand values
    numFill = playerNum[missing-1]; 
    suitFill = playerSuit[missing-1];
    opponentNum.push_back(numFill);
    opponentSuit.push_back(suitFill);   //push values to opponent vector
    //This function takes in the parallel player hand arrays and the parallel opponent hand arrays. It also takes the index that needs to be copied. 
    //Because it works with one index at a time it needs to be called for every card that needs copied.  
}


void handReset(vector<int>& handNum, vector<char>& handSuit, int popNum){
    for (int counter = 0; counter < popNum; counter++){
        handNum.pop_back();
        handSuit.pop_back();
    }
    /*The player may deal multiple times before quitting the program. The deck array resets in the do while loop by initializing
    every time. To resetthe hand vectors we pop back by the number of cards that were dealt.*/
}





/*****************************************************************************
**************Bet and AI functions****************************************
    ******************************************************************************/
bool opponentBet(int& stake, int& pool){
    cout << "opponent checks" << endl;
    stake+=stake;
    pool+=stake;
    stake =0;
    //this is a driver for ai betting
    return false;
}

bool bet(int& stake, int& money,int& pool){ //pass stake as a reference so we can add to it. Pass player or opponent money to affect it
    int bet = 0; //This holds bet to be added to stake. It ensures proper bet amount is entered
    int userOption = 0;
    string betPrompt = "";  //This is so we can change prompt bsed on user input
    string userPrompt = ""; //changes prompt based on user user input for 
    
    if (stake == 0){
        userPrompt = "1.Check \n2.Bet \n3.Fold\n";}    //Check option is effectively the same as call since checking a 0 stake has no effect.
    //raise is effectively the same as bet, this if statment just outputs terms that make more sense in context to the player
    else{ userPrompt = "1.Call \n2.Raise \n3.Fold\n";}

    do {
        cout << userPrompt;
        cin >> userOption; //menu choice
    } while (userOption < 1 || userOption > 3);   //ensure that option is valid

    switch (userOption){
        case 1: money-=stake; //take money from player equal to stake amount
            stake += stake;   //adds doubles stake to mimic call.
            pool+=stake;
            stake =0;
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
            stake+=bet;
            break; //if this is call the math here doesn't matter as stake is 0 and nothing is + or -
        case 3: 
            return true;   //game needs to immediatley end, 3 will be used to clean up
    }
    return false;
    /*This function works like a void function in that most of what it does is displaying something and affecting variables passed to it. It will
    always reutrn false(which will do nothing in main) unless there is a fold. It is meant to be run in a do while loop. When there is a raise/bet it affects
    stake. Which will keep the loop going. if a check or call is made stake is 0 so the loop stops. */
}




/*****************************************************************************
     **************Game end/Win check functions********************************
    ******************************************************************************/
       
        /********Hand Algorithms*************/
int highCard(vector<int> handNum){
    int highCard = 0;
    for (int card = 0; card < 7; card++){
        if (highCard != 1 && handNum[card] > highCard || handNum[card] == 1){
            //this if condition is clunky but its easier for other algorithms if ace is represented by 1
            //but we still have ot make it high
            highCard = handNum[card];
        }
    }
    return highCard;
        //Function to find the highest number except in this case 1 will resolve as the highest because it represents the Ace
} 

int pairs(vector<int> handNum){
    int numberofPairs = 0;
    for (int card = 0; card < 6; card++){ //we dont need to check the lat card it will already be checked on next to last
        for (int nextCard = card + 1; nextCard < 7; nextCard++){ //keeps card to check the same but loops through every other one
            if (handNum[card] == handNum[nextCard])
                numberofPairs++;
        }
    }
    return numberofPairs;
}

bool threeKind(vector<int> handNum){
    bool threeKind = false;
    for (int card = 0; card <= 5 && threeKind == false; card++){ //loop stops at card 5 bc a three match would be impossible
        int matches = 0; //if this == 2 the we have found 3 cards of the same number, careful of 1 off error
        for (int nextCard = card + 1; nextCard < 7; nextCard++){    //compare all 7 cards to target card
            if (handNum[card] == handNum[nextCard])
                matches++;
        }
        if (matches == 2)
            threeKind = true; //after each card is checked against every other we see if we have 3 of a kind
    }
    return threeKind;
        //The first for loop is for picking every card(except last 2) to compare, the nested is for looping through every
        //other card and comparing it to the first. Matches is defined inside outer loop so it resets before actual card
        //comparison. if a match is found we must change our bool terminator before another loop starts
}

bool fourKind(vector<int> handNum){
    bool fourKind = false;
    for (int card = 0; card <= 4 && fourKind == false; card++){ //loop stops at card 4 bc a three match would be impossible
        int matches = 0; //if this == 3 the we have found 4 cards of the same number, careful of 1 off error
        for (int nextCard = card + 1; nextCard < 7; nextCard++){    //compare all 7 cards to target card
            if (handNum[card] == handNum[nextCard])
                matches++;
        }
        if (matches == 3)
            fourKind = true; //after each card is checked against every other we see if we have 3 of a kind
    }
    return fourKind;
        //The first for loop is for picking every card(except last 2) to compare, the nested is for looping through every
        //other card and comparing it to the first. Matches is defined inside outer loop so it resets before actual card
        //comparison. if a match is found we must change our bool terminator before another loop starts
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


        /********Hand Checks for main*************/

void highCheck(vector<int> playerHandNum, vector<int>opponentHandNum, int &pool, int& playerMoney){ //playerMoney needs to be passed as a reference so we can add to it
    int playerHigh = highCard(playerHandNum);
    int opponentHigh = highCard(opponentHandNum);//return highest value card
    
    if ((playerHigh > opponentHigh) || (playerHigh == 1 && opponentHigh != 1)){
        cout << "You win with a High Card!" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
        pool = 0;
        
    }else if(opponentHigh > playerHigh || (playerHigh != 1 && opponentHigh == 1)){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
        pool = 0;
    }else{
        cout << "Draw" << endl << "Split: $" << pool/2 << endl;
        playerMoney+=(pool/2);
        pool = 0;
    }
    //This function uses the highCard function to check for a winner. There are three outcomes, a win
    //Wherein the player will be rewarded the pool, a draw where they are rewarded half the pool, and a
    //lose. Where nothing happens, meaning pool is lost. 
}

void pairCheck(vector<int>playerHandNum, vector<int>opponentHandNum, int &pool, int& playerMoney){
    int playerPair = pairs(playerHandNum);
    int opponentPair = pairs(opponentHandNum);

    if(playerPair > opponentPair){
        cout << "You win with " << playerPair << " pair" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
        pool = 0;

    }else if(opponentPair > playerPair){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
        pool = 0;
    }else if(playerPair == opponentPair){
        highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
    }
}

void threeCheck(vector<int>playerHandNum, vector<int>opponentHandNum, int &pool, int& playerMoney){
    bool playerthreeKind = threeKind(playerHandNum);
    bool opponentthreeKind = threeKind(opponentHandNum);

    if(playerthreeKind && !opponentthreeKind){
        cout << "You win with a Three of a Kind!" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
        pool = 0;
    }else if(opponentthreeKind && !playerthreeKind){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
        pool = 0;
    }else if(playerthreeKind && opponentthreeKind){
        highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
    }
}

void fourCheck(vector<int>playerHandNum, vector<int>opponentHandNum, int &pool, int& playerMoney){
    bool playerfourKind = fourKind(playerHandNum);
    bool opponentfourKind = fourKind(opponentHandNum);

    if(playerfourKind && !opponentfourKind){
        cout << "You win with a Four of a Kind!" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
        pool = 0;
    }else if(opponentfourKind && !playerfourKind){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
        pool = 0;
    }else if(playerfourKind && opponentfourKind){
        highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
    }
}

void flushCheck(vector<char>playerHand, vector<char>opponentHand,vector<int>playerHandNum, vector<int>opponentHandNum, int &pool, int& playerMoney){
    bool playerFlush = flush(playerHand);
    bool opponentFlush = flush(opponentHand);

    if(playerFlush && !opponentFlush){
        cout << "You win with a Flush!" << endl << "Winnings: $"
        << pool << endl;
        playerMoney+=pool;
        pool = 0;
    }else if(opponentFlush && !playerFlush){
        cout << "You lose." << endl << "Pool: $" << pool <<endl;
        pool = 0;
    }else if(playerFlush && opponentFlush){
        highCheck(playerHandNum, opponentHandNum, pool, playerMoney);
    }
    //This function calls the flush function for both hands and will trigger a win or loss if either hand has an exlusive flush
    //If both have a flush, it calls highCard and decides the winner based on that, which is why the handNum vectors are passed.
    //If neither have a flush it should do nothing. 
}