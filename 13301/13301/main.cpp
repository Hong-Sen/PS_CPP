#include <iostream>
using namespace std;

long long tile[81];

int main(){
    int n;
    cin>>n;
    tile[1] = 1;
    tile[2] = 1;
    tile[3] = 3;
    tile[4] = 5;
    for(int i=5; i<=n; i++){
        tile[i] = tile[i-1] + tile[i-2];
    }
    if(n==1)    cout<<4;
    else if(n==2)   cout<<6;
    else if(n==3)   cout<<10;
    else if(n==4)   cout<<16;
    else
    cout<<tile[n-1] * 2 + (tile[n-2] + tile[n-1]) * 2;
}
