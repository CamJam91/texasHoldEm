#include<iostream>
#include<ctime>
using namespace std;
void draw();
int randomGen();
int main(){
    unsigned seed = time(0);
    srand(seed);

    for (int count = 0; count < 50; count++){
        draw();
    }

}

void draw(){
    int randomNum = randomGen();    //We put the random number into a variable so we can use it in multiple instances
    cout << randomNum << endl;
}
int randomGen(){
    return (rand() % 52);
}