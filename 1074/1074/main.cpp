#include <iostream>
#include <cmath>
using namespace std;

int N,r,c;
int num;

void visited(int n, int x, int y){
    if(x<=c && c<x+n && y<=r && r<y+n){
        if(n == 2){
            if((y==r || y+1==r) && (x==c || x+1==c)){
                if(y==r){
                    if(x==c) cout<<num;
                    if(x+1==c) cout<<num+1;
                }
                if(y+1==r){
                    if(x==c) cout<<num+2;
                    if(x+1==c) cout<<num+3;
                }
            }
            else{
                num += 4;
            }
            return;
        }
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
