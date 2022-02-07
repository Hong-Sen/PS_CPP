#include <iostream>
#include <cmath>
using namespace std;

int N,r,c;
int num;

void visited(int n, int x, int y){
    if(x == c && y == r){
        cout<<num;
        return;
    }
    if(n == 1){
        num++;
        return;
    }
    if(x<=c && c<x+n && y<=r && r<y+n){
        int d = n/2;
        visited(d, x, y);
        visited(d, n/2+x, y);
        visited(d, x, n/2+y);
        visited(d, n/2+x, n/2+y);
    }
    else{
        num += n*n;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>r>>c;
    visited(pow(2, N), 0, 0);
}
