#include <iostream>
using namespace std;

int main(){
    int n,sum=0;
    cin>>n;
    n = 1000-n;
    while(n!=0){
        sum += n/500;
        n %= 500;
        sum += n/100;
        n %= 100;
        sum += n/50;
        n %= 50;
        sum += n/10;
        n %= 10;
        sum += n/5;
        n %= 5;
        sum += n/1;
        n %= 1;
    }
    cout<<sum<<"\n";
        
}
