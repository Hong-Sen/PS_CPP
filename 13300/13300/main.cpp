#include <iostream>

using namespace std;

int arr[7][2];

int main(){
    int n,k,s,y;
    int cnt = 0;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>s>>y;
        //year > sex 순으로 배열에 입력
        arr[y][s]++;
    }
    for(int i=1; i<=6; i++){
        for(int j=0; j<2; j++){
            if(arr[i][j] % k == 0)  cnt += arr[i][j] / k;
            else    cnt += arr[i][j] / k + 1;
        }
    }
   
    cout<<cnt;
}
