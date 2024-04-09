#include <iostream>
#include <vector>
using namespace std;

void draw(int (&cardNum)[52], char (&cardSuit)[52], vector<int>&handNum, vector<char>&handSuit); //2 vectors are referenced: the number of the card and the suit, an int will hold number,
//and char will hold suit
int randomGen(); //calls and returns nrandom number
bool bet(int&, int&);

int main(){
    //for the random number generator
    unsigned seed = time(0);
    srand(seed);

        //deck arrays
    char DECK_SUIT[52] = {'H','H','H','H','H','H','H','H','H','H','H','H','H','C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','S','S','S','S','S','S','S','S','S','S','S','S','S'};//Suits. H = hearts and so on
    int DECK_NUM[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};   //the 1 represents Ace and the 11, 12, 13 represent jack, queen, king respectively

        //hand vectors
    //These vectors are parallel and should always be the same size, their initial size is 0 and will only need to be expanded to 7
        //player hand vectors
    vector<int> playerHandNum; 
    vector<char> playerHandSuit;
        //oponent hand vectors
    vector<int> opponentHandNum; 
    vector<char> opponentHandSuit;
    int numFill = -1,
    suitFill = -1;  //for assigning proper values to hands
    int userOption = 0; //used for menu
    //money
    int playerMoney = 100,  //overall wallet
    pool = 0,               //winnings for each hand
    stake = 0;              //to be added to the pool
    bool fold = false;      //if this returns true hand ends
    do {
        cout << "Money: $" << playerMoney << endl;  //display playerMoney
        cout << "1.Deal \n2.Quit\n";
        cin >> userOption;
        if (userOption == 1){ 
                //player hand
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                //opponent hand
            draw(DECK_NUM, DECK_SUIT, opponentHandNum, opponentHandSuit);
            draw(DECK_NUM, DECK_SUIT, opponentHandNum, opponentHandSuit);

            cout << "Money: $" << playerMoney << endl;  //display playerMoney
            cout << "Pool: $" << pool << endl;          //display pool

                //shows player their hand
            for (int count = 0; count < 2; count++){
                cout << playerHandNum[count] << playerHandSuit[count] << " ";
            }
            cout << endl;

            //bet() function here;
            fold = bet(stake, playerMoney); //stake and money ints are passed as ref and we assign bet to fold 
            //bc it will return a true if a fold has happened
            //AI bet will go here
            pool+=stake;    //we add stake to the pool
            stake = 0;      //reset stake for next bet
            if (fold == true){  //this is a quick fix, we need to figure a way to not exit program
                break;
            }   //ends hand if a fold has happened
            
            //flop
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);
                //since these cards are community we assign the values to opponent array
            for (int hand = 2; hand < 5; hand++){
                numFill = playerHandNum[hand]; //fill variable with player card num value
                suitFill = playerHandSuit[hand]; //fill variable with player card suit value
                opponentHandNum.push_back(numFill);
                opponentHandSuit.push_back(suitFill);   //share values with opponent hand
            }

            cout << "Money: $" << playerMoney << endl;  //display playerMoney
            cout << "Pool: $" << pool << endl;          //display pool

            //show player their hand and community cards
            for (int count = 0; count < 5; count++){
                cout << playerHandNum[count] << playerHandSuit[count] << " ";
            }
            cout << endl;
            //bet() function here;
            fold = bet(stake, playerMoney);
            pool+=stake;
            stake = 0;
            if (fold == true){
                break;
            }
            //fourth street
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);   //draw another community card
                numFill = playerHandNum[5]; //fill variable with player card num value
                suitFill = playerHandSuit[5]; //fill variable with player card suit value
                opponentHandNum.push_back(numFill);
                opponentHandSuit.push_back(suitFill);   //share values with opponent hand

            cout << "Money: $" << playerMoney << endl;  //display playerMoney
            cout << "Pool: $" << pool << endl;          //display pool

             //show player their hand and community cards
            for (int count = 0; count < 6; count++){
                cout << playerHandNum[count] << playerHandSuit[count] << " ";
            }
            //bet() function here;
            fold = bet(stake, playerMoney);
            pool+=stake;
            stake = 0;
            if (fold == true){
                break;
            }
            //river
            draw(DECK_NUM, DECK_SUIT, playerHandNum, playerHandSuit);   //draw another community card
                numFill = playerHandNum[6]; //fill variable with player card num value
                suitFill = playerHandSuit[6]; //fill variable with player card suit value
                opponentHandNum.push_back(numFill);
                opponentHandSuit.push_back(suitFill);   //share values with opponent hand
            
            cout << "Money: $" << playerMoney << endl;  //display playerMoney
            cout << "Pool: $" << pool << endl;          //display pool

                 //show player their hand and community cards
            for (int count = 0; count < 7; count++){
                cout << playerHandNum[count] << playerHandSuit[count] << " ";
            }
            cout << endl;
            //bet() function here;
            fold = bet(stake, playerMoney);
            pool+=stake;
            stake = 0;
            if (fold == true){
                break;
            }
            /*//test
            cout << "player hand: " << endl;
            for (int count = 0; count < 7; count++){
                cout << playerHandNum[count] << playerHandSuit[count] << " ";
            }
            cout << endl;
            cout << "opponent hand: " << endl;
            for (int count = 0; count < 7; count++){
                cout << opponentHandNum[count] << opponentHandSuit[count] << " ";
            }
            cout << endl;*/
        }
    }while(userOption != 2);

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

bool bet(int& stake, int& money){ //pass stake as a reference so we can add to it. Pass player or opponent money to affect it
    int bet = 0; //This holds bet to be added to stake. It ensures proper bet amount is entered
    int userOption = 0;
    string betPrompt = "";  //This is so we can change prompt bsed on user input
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
        case 1: money-=stake; //take money from player equal to stake amount
            stake += stake;   //adds doubles stake to mimic call.
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
            stake+=bet; //player "money" is put into stake
            break; //if this is call the math here doesn't matter as stake is 0 and nothing is + or -
        case 3: return true;   //game needs to immediatley end, 3 will be used to clean up
    }
    return false;
}


int randomGen(){
    return (rand() % 52);
}




/* Problem: When I run my test for assigning hands 0's are being pulled. 
Test: 
    1. Since we are able to affect arrays in functions by referencing the address in our parameters we can delete the pull variables but for now we will use them for testing
    2. call draw function and assign the cout pull values 50 times
    3. if 2 doesnt work try deleting the while loop and and moving the while loop into main\
    fixed: while loop had incorrect parameters

    simplifying:
    1. erase pull variables and replace with hand vects
    fixed: moved pullNum to inside function
    */
    
