#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1024][1024];
int n;

void pulling(){
    while (n != 1) {
        vector<vector<int>> tmp(n/2, vector<int>(n/2,0));
        for(int i=0; i<n; i+=2){
            for(int j=0; j<n; j+=2){
                vector<int> v;
                v.push_back(arr[i][j]);
                v.push_back(arr[i][j+1]);
                v.push_back(arr[i+1][j]);
                v.push_back(arr[i+1][j+1]);
                sort(v.begin(), v.end());
                tmp[i/2][j/2] = v[2];
            }
        }
        n /= 2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = tmp[i][j];
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    pulling();
    cout<<arr[0][0];
}
