#include <iostream>
using namespace std;

void swap(int a,int b){
    if(a<b){
        int temp = 0;
        a = temp;
        a = b;
        b = temp;
    }
}
int gcd(int a,int b){
    swap(a,b);
    while(b!=0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a,int b){
    swap(a,b);
    return (a*b)/gcd(a,b);
    
}
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    
    cout<<gcd(a,b)<<'\n';
    cout<<lcm(a,b)<<'\n';
    
}
