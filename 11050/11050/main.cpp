#include <iostream>
using namespace std;

int factorial(int num){
    if(num==1||num==0)
        return 1;
    else
        return num*factorial(num-1);
}

int main() {
    int n,k;
    cin>>n;
    cin>>k;
    cout<<factorial(n)/(factorial(k)*factorial(n-k))<<'\n';
    return 0;
    
}
