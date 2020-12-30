#include <iostream>
#include <vector>
using namespace std;

int sum[3];
int paper[2188][2188];

bool check(int row, int col,int n){
    int tmp = paper[row][col];
    for(int i=row; i<row+n; i++){
        for(int j=col; j<col+n; j++){
            if(tmp != paper[i][j]){
                return false;
            }
        }
    }
        return true;
}

void devide(int row,int col,int n){
    if(check(row, col,n))    sum[paper[row][col]+1]++;
    else{
        int size = n/3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                devide(row+i*size, col+j*size, size);
            }
        }
    }
}

int main(){
    int n;
    cin>> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>paper[i][j];
        }
    }

    devide(0, 0, n);
    cout<<sum[0]<<"\n"<<sum[1]<<"\n"<<sum[2]<<"\n";
}
