#include <iostream>
using namespace std;

int r,c,n;
char arr[201][201][201];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void displayArr(int cur){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[cur][i][j];
        }
        cout<<"\n";
    }
}

bool isInside(int x, int y){
    if(x>=0 && x<c && y>=0 && y<r)  return true;
    else    return false;
}

void bfs(int cur, int next){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(arr[cur][i][j] == 'O'){
                arr[next][i][j] = '.';
                for(int k=0; k<4; k++){
                    int nx = j + dx[k];
                    int ny = i+ dy[k];
                    if(isInside(nx, ny)){
                        arr[next][ny][nx] = '.';
                    }
                }
            }
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(arr[next][i][j] != '.'){
                arr[next][i][j] = 'O';
            }
        }
    }
}

int main(){
    cin>>r>>c>>n;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[0][i][j];
        }
    }

    if(n%2 == 0){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout<<'O';
            }
            cout<<"\n";
        }
    }
    else{
        for(int i=0; i<n/2; i++){
            bfs(i, i+1);
        }
        displayArr(n/2);
    }
}
