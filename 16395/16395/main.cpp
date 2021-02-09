#include <iostream>
using namespace std;

int arr[30][30];

int paskal(int x,int y){
    if(y==0 || x==y)    return 1;
    if(arr[x][y]==0)    return arr[x][y] = paskal(x-1,y-1) + paskal(x-1,y);
    else    return arr[x][y];
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<paskal(n-1, k-1);
}
