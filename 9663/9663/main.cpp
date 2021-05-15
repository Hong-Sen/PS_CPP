#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt;
int chess[16];

bool isValid(int i){
    int k=1;
    bool flag = true;
    while (k<i && flag) {
        //같은 열이거나 대각선 일때
        if(chess[i] == chess[k] || abs(chess[i] - chess[k]) == i-k)
            flag = false;
        k++;
    }
    return flag;
}

void nqueens(int i){
    if(isValid(i)){
        if(i==n)    cnt++;
        else{
            for(int j=1; j<=n; j++){
                chess[i+1] = j;
                nqueens(i+1);
            }
        }
    }
}

int main(){
    cin>>n;
    nqueens(0);
    cout<<cnt;
}
