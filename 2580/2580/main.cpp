#include <iostream>
using namespace std;

int sdoku[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

void dfs(int cnt){
    int x = cnt/9; //col
    int y = cnt%9; //row
    if(cnt == 81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<sdoku[i][j]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }
    if(sdoku[x][y] == 0){
        for(int i=1; i<=9; i++){
            if(!row[x][i] && !col[y][i] && !square[(x/3)*3 + (y/3)][i]){
                row[x][i] = true;
                col[y][i] = true;
                square[(x/3)*3 + (y/3)][i] = true;
                sdoku[x][y] = i;
                dfs(cnt+1);
                //다른값이 들어올 수도 있으니 다시 초기화
                sdoku[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x/3)*3 + (y/3)][i] = false;
            }
        }
    }
    else    dfs(cnt+1);
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>sdoku[i][j];
            if(sdoku[i][j] != 0){
                row[i][sdoku[i][j]] = true;
                col[j][sdoku[i][j]] = true;
                square[(i/3)*3 + (j/3)][sdoku[i][j]] = true;
            }
        }
    }
    dfs(0);
    
}
