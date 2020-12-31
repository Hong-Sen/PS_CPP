#include <iostream>
using namespace std;

int map[64][64];

bool check(int x,int y,int n){
    int tmp = map[x][y];
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(map[i][j] != tmp)
                return false;
        }
    }
    return true;
}


void divide(int x,int y,int n){
    if(check(x,y,n))    cout<<map[x][y];
    else{
        int size = n/2;
        cout<<"(";
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                
                divide(x+i*size, y+j*size, size);
                
            }
        }
        cout<<")";
    }
}



int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin>>c;
            int num = (int)c - '0';
            map[i][j] = num;
        }
    }

    divide(0, 0, n);
}
