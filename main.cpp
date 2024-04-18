#include<iostream>
#include<vector>
#include<ctime>
#include<iomanip>
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
    int playerMoney = 100;  //overall wallet


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
                    handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,4);

                    handDisplay(playerHandNum, playerHandSuit,6);
                    moneyDisplay(pool, stake, playerMoney);
                    do{
                        fold = bet(stake, playerMoney, pool); //every draw is followed by a bet
                        //bet works like our other void functions but it returns true if there is a fold
                        if (!fold) //if player folds dont trigger ai bet 
                            fold = opponentBet(stake,pool);  //ai function that will call check bet or fold
                    }while(stake!=0 && !fold);
                if (fold)
                   popNumber = 6; //used to reset hand vector 

                    if (!fold){
                        //fifth street, "river"
                        draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                        handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,4);

                        handDisplay(playerHandNum, playerHandSuit,7);
                        moneyDisplay(pool, stake, playerMoney);
                        do{
                        fold = bet(stake, playerMoney, pool); //every draw is followed by a bet
                        //bet works like our other void functions but it returns true if there is a fold
                        if (!fold) //if player folds dont trigger ai bet 
                            fold = opponentBet(stake,pool);  //ai function that will call check bet or fold
                        }while(stake!=0 && !fold);
                if (fold)
                   popNumber = 7; //used to reset hand vector 
                    }
                    if (!fold){ //now hands are checked for winner  
                        handDisplay(playerHandNum, playerHandSuit,7);
                        cout << "Opponent ";
                        handDisplay(opponentHandNum, opponentHandSuit,2); //Show 2 opponent cards 
                    }
                }
            }
        } 
        handReset(playerHandNum, playerHandSuit, popNumber);//reset both hand vectors
        handReset(opponentHandNum, opponentHandSuit, popNumber);
    }while(userOption != 2);
}

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

int menu(int money){
    int userOption;
    cout << "Money: $" << money << endl;
    cout << "1.Deal \n2.Quit\n";
    cin >> userOption;
    return userOption;
    //A simple function to kick off the gameplay loop
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

void handReset(vector<int>& handNum, vector<char>& handSuit, int popNum){
    for (int counter = 0; counter < popNum; counter++){
        handNum.pop_back();
        handSuit.pop_back();
    }
    /*The player may deal multiple times before quitting the program. The deck array resets in the do while loop by initializing
    every time. To resetthe hand vectors we pop back by the number of cards that were dealt.*/
}

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