#include <iostream>
using namespace std;

char chess[50][50];
int m,n;
int result = 2501;
char board1[8][8] = {'W','B','W','B','W','B','W','B',
                    'B','W','B','W','B','W','B','W',
                    'W','B','W','B','W','B','W','B',
                    'B','W','B','W','B','W','B','W',
                    'W','B','W','B','W','B','W','B',
                    'B','W','B','W','B','W','B','W',
                    'W','B','W','B','W','B','W','B',
                    'B','W','B','W','B','W','B','W'};

char board2[8][8] = {'B','W','B','W','B','W','B','W',
                    'W','B','W','B','W','B','W','B',
                    'B','W','B','W','B','W','B','W',
                    'W','B','W','B','W','B','W','B',
                    'B','W','B','W','B','W','B','W',
                    'W','B','W','B','W','B','W','B',
                    'B','W','B','W','B','W','B','W',
                    'W','B','W','B','W','B','W','B'};

int paint(int cal, int row){
    int cnt1 = 0, cnt2 = 0;
    int a = 0, b = 0;
    for(int i=cal; i<cal+8; i++){
        b = 0;
        for(int j=row; j<row+8; j++){
            if(board1[a][b] != chess[i][j])  cnt1++;
            if(board2[a][b] != chess[i][j])   cnt2++;
            b++;
        }
               a++;
    }
    cnt1 = min(cnt1, cnt2);
    return cnt1;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>chess[i][j];
        }
    }
    for(int i=0; i<=n-8; i++){
        for(int j=0; j<=m-8; j++){
            result = min(result,paint(i, j));
        }
    }
    cout<<result<<"\n";
}
