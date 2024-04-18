#include<iostream>
#include<vector>
using namespace std;

void handReset(vector<int>&, vector<char>&, int);
int main(){
    vector <int>handNum = {1,2,4};
    vector<char>handSuit = {'H','D','H'};
    int popNumber = 3;
    handReset(handNum, handSuit, popNumber);
    return 0;
}

void handReset(vector<int>& handNum, vector<char>& handSuit, int popNum){
    for (int counter = 0; counter < popNum; counter++){
        handNum.pop_back();
        handSuit.pop_back();
    }
}
