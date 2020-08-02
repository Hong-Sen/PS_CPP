#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int un[5];
    int sum = 0;
    
    for(int i=0;i<5;i++){
        cin>>un[i];
        sum+=pow(un[i],2);
    }
    cout<<sum%10<<'\n';
}
