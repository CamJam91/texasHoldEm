#include<iostream>
using namespace std;

void plusOne(int&);
int main(){
    int plusMe = 0;
    plusOne(plusMe);
    cout << plusMe << endl;
}

void plusOne(int&plusThis){
    plusThis += 1;
}