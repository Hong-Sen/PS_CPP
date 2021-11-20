#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr1[4] = {2,3,5,7};

bool isPrime(int num){
    for(int i=2; i<=sqrt(num) ; i++){
        if(num % i == 0)    return false;
    }
    return true;
}

void makePrimeNum(int length, int num){
    if(length == 0){
        for(int i=0; i<4; i++){
            makePrimeNum(1, arr1[i]);
        }
        return;
    }
    if(length == n){
        cout<<num<<"\n";
        return;
    }
    for(int i=1; i<=9; i++){
        int next = num*10 + i;
        if(isPrime(next)){
            makePrimeNum(length+1, next);
        }
    }
}
int main(){
    cin>>n;
    makePrimeNum(0, 0);
}
