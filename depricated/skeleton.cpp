#include<iostream>
#include<vector>
#include<ctime>
#include<iomanip>
using namespace std;

    //function prototypes
void draw(int (&cardNum)[52], char (&cardSuit)[52], vector<int>&handNum, vector<char>&handSuit);
bool bet(int&, int&);
int menu (int);
void display(vector<int> , vector<char>, int, int, int, int);
void handMimic(vector<int>, vector<char>, vector<int>&, vector<char>&, int);
int randomGen();



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
    int playerMoney = 100,  //overall wallet
    pool = 0,               //winning for eacah hand
    stake = 0;              //money added to pool
    bool fold = false;      //if this is true, hand ends
    



    do {    //while loopo for menu
        //deck arrays
        char DECK_SUIT[52] = {'H','H','H','H','H','H','H','H','H','H','H','H','H','C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','S','S','S','S','S','S','S','S','S','S','S','S','S'};//Suits. H = hearts and so on
        int DECK_NUM[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};   //the 1 represents Ace and the 11, 12, 13 represent jack, queen, king respectively
        userOption = menu(playerMoney); //cout prompt and fills userOption
        if (userOption == 1){    //if player doeesn't quit start play
                //draw 2 cards for player hand
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                //draw 2 cards for opponent hand
            draw(DECK_NUM, DECK_SUIT, opponentHandNum, opponentHandSuit);
            draw(DECK_NUM, DECK_SUIT, opponentHandNum, opponentHandSuit);

                //player options after draw
            display (playerHandNum, playerHandSuit, pool, stake, 2, playerMoney);   //show player pertinent info
            fold = bet(stake, playerMoney); //every draw is followed by a bet
            //bet works like our other void functions but it returns true if there is a fold
            pool+=stake;    //we add stake to the pool
            stake = 0;      //reset stake for next bet


            if (fold == false){  //If a fold has occured the rest of the modules are skipped
                //Flop call draw function for 3 cards. Since they are community cards we only call draw for player hand
                //and copy them to opponent hand
                draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,3);//copy community cards to opponent hand
                handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,4);
                handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit,5);
                
                display (playerHandNum, playerHandSuit, pool, stake, 5, playerMoney);   //show player pertinent info
                fold = bet(stake, playerMoney);
                pool+=stake;    //we add stake to the pool
                stake = 0;      //reset stake for next bet


                    if (fold == false){  //If a fold has occured the rest of the modules are skipped
                    //fourth street
                    draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                    handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit, 6);//copy community cards to opponent hand
                    
                    display (playerHandNum, playerHandSuit, pool, stake, 6, playerMoney);   //show player pertinent info
                    fold = bet(stake, playerMoney);
                    pool+=stake;    //we add stake to the pool
                    stake = 0;      //reset stake for next bet
                        
                        
                        if (fold == false){  //If a fold has occured the rest of the modules are skipped
                        //fifth street, "river"
                        draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                        handMimic(playerHandNum, playerHandSuit, opponentHandNum, opponentHandSuit, 7);//copy community cards to opponent hand
                        
                        display (playerHandNum, playerHandSuit, pool, stake, 7, playerMoney);   //show player pertinent info
                        fold = bet(stake, playerMoney);
                        pool+=stake;    //we add stake to the pool
                        stake = 0;      //reset stake for next bet
                        
                        display (opponentHandNum, opponentHandSuit, pool, stake, 7, playerMoney);   //show player pertinent info
                        }
                        
                        if (fold == false){
                            //Now we decide the winner. We need to loop through each poker funciton, starting with highest until we find a winner
                            display (playerHandNum, playerHandSuit, pool, stake, 7, playerMoney);
                            cout << "Opponents cards: " << opponentHandNum[0] << opponentHandSuit[0] << " "<< opponentHandNum[1] << opponentHandSuit[1] << endl;
                            //*****put end game functions here******//
                        }

                }
            }  
        }

    }while(userOption != 2);

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
        cout << endl;
    if (handSize > 2){
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
}

int menu(int money){
    int userOption;
    cout << "Money: $" << money << endl;
    cout << "1.Deal \n2.Quit\n";
    cin >> userOption;
    return userOption;
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
}

bool bet(int& stake, int& playerMoney){ //pass stake as a reference so we can add to it. Pass player or opponent money to affect it
    int bet = 0; //This holds bet to be added to stake. It ensures proper bet amount is entered
    int userOption = 0;
    string betPrompt = "";  //This is so we can change prompt based on user input
    string userPrompt = ""; //changes prompt based on user user input for 
    
    if (stake == 0){
        userPrompt = "1.Check \n2.Bet \n3.Fold";}    //Check option is effectively the same as call since checking a 0 stake has no effect.
    //raise is effectively the same as bet, this if statment just outputs terms that make more sense in context to the player
    else{ userPrompt = "1.Call \n2.Raise \n3.Fold";}

    do {
        cout << userPrompt;
        cin >> userOption; //menu choice
    } while (userOption < 1 || userOption > 3);   //ensure that option is valid

    switch (userOption){
        case 1: playerMoney-=stake; //take money from player equal to stake amount
            stake += stake;   //adds doubles stake to mimic call.
            break;            //If this is a check then stake == 0 and expressoins don't change anything
        case 2: if (stake == 0){
            betPrompt = "How much would you like to bet?";
            }else{                //if stake != 0 then it is called raise not bet
                betPrompt = "How much would you like to raise?";
            }
            do {
                cout << betPrompt << "$1 - $" << playerMoney << endl;
                cin >> bet;
            }while(bet < 1 || bet > playerMoney); //0 or less bets arent allowed, neither is more than players money
            playerMoney-=bet; //player "pays" money
            stake+=bet; //player "money" is put into stake
            break; //if this is call the math here doesn't matter as stake is 0 and nothing is + or -
        case 3: return true;   //game needs to immediatley end, 3 will be used to clean up
    }
    return false;
}

int randomGen(){
    return (rand() % 52);
}