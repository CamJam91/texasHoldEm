#include<iostream>
#include<vector>
using namespace std;

//Test to see if a do while loop resets arrays and if vector popbacks have any unforseen consequences
int main(){
    int endLoop = 0;
    vector<int> testVect = {1,2};
    testVect.pop_back();
    testVect.pop_back();
    testVect.pop_back();
    testVect.pop_back();
    testVect.pop_back();
    testVect.pop_back();
    /*do {
        int testArray[5] = {1,2,3,4,5};
        testArray[0] = 12;
        testVect.push_back(1);
        endLoop = 1;
        if (endLoop == 1){
            testVect.pop_back();

    }while(true);
*/
}