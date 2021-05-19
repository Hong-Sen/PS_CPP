#include <iostream>
using namespace std;

int paper[128][128];
int whiteCnt, blueCnt;

void cutting(int x, int y, int n){
    int whiteTmp = 0;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(paper[i][j] == 0){
                whiteTmp++;
            }
        }
    }
    if(whiteTmp == 0)   blueCnt++;
    else if(whiteTmp == n*n)    whiteCnt++;
    else{
        cutting(x,y,n/2);
        cutting(x, y+n/2, n/2);
        cutting(x+n/2, y, n/2);
        cutting(x+n/2, y+n/2, n/2);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>paper[i][j];
        }
    }
    cutting(0, 0, n);
    cout<<whiteCnt<<"\n"<<blueCnt<<"\n";
}
