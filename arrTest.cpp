#include<iostream>
using namespace std;

int arrFun(int *arrParam[]);
int main(){
    int testArr[3] = {1,2,3};
    int *arrPoint = testArr[];
    int testOut = arrFun(*arrPoint);

}

int arrFun(int *arrParam[]){
    return arrParam[0];
}