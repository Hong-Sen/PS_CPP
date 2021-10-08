#include <iostream>
using namespace std;

int tree[3073][6144];

void draw(int x, int y){
    // 첫째줄
    tree[y][x] = 1;
    // 둘째줄
    tree[y+1][x-1] = 1; tree[y+1][x+1] = 1;
    // 셋째줄
    for(int i=x-2; i<=x+2; i++)
    tree[y+2][i] = 1;
}

void solve(int n, int x, int y){
    if(n == 3){
        draw(x,y);
        return;
    }
    solve(n/2, x, y);
    solve(n/2, x-n/2, y+n/2);
    solve(n/2, x+n/2, y+n/2);
}

int main(){
    int n;
    cin>>n;
    
    solve(n, n-1, 0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-1; j++){
            if(tree[i][j] == 1) cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    }
}
