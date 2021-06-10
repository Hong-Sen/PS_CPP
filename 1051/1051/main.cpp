#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int n,m;
int arr[50][50];
int result;

void rectangle(){
    result = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<min(n,m); k++){
                if(i+k<n && j+k<m && arr[i][j] == arr[i][j+k] && arr[i][j] == arr[i+k][j] && arr[i][j] ==  arr[i+k][j+k]){
                    result = max(k+1, result);
                }
            }
            
        }
    }
    return;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++)
            arr[i][j] = (int)(s.at(j)) - '0';
    }
    rectangle();
    cout<<result*result;
    }
