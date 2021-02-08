#include <iostream>
using namespace std;

char star[7000][7000];

void solve(int n, int x, int y){
    if(n==1){
        star[x][y] = '*';
        return;
    }
    int d = n/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==1)    continue;
            else    solve(d, x+(d*i), y+(d*j));
        }
    }
}

int main(){
    int n;
    cin>>n;
    for (int i=0; i <7000; i++) {
        for (int j=0; j<7000; j++) {
            star[i][j] = ' ';
        }
    }
    solve(n, 0, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<star[i][j];
        }
        cout<<"\n";
    }
    
}


