//
//  main.cpp
//  3085
//
//  Created by 홍세은 on 2023/01/26.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
char initMap[51][51];
int result;

void pickLongestLine(char map[51][51]) {
    int maxCnt = 0;
    for(int i=0; i<n; i++) {
        int cnt = 1;
        for(int j=1; j<n; j++) {
            if(map[i][j-1] == map[i][j]) cnt++;
            else {
                maxCnt = max(maxCnt, cnt);
                cnt = 1;
            }
        }
        maxCnt = max(maxCnt, cnt);
    }
    
    for(int j=0; j<n; j++) {
        int cnt = 1;
        for(int i=1; i<n; i++) {
            if(map[i][j] == map[i-1][j]) cnt++;
            else {
                maxCnt = max(maxCnt, cnt);
                cnt = 1;
            }
        }
        maxCnt = max(maxCnt, cnt);
    }
    
    result = max(maxCnt, result);
}

int main(){
    cin>>n;
    char c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>initMap[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i+1 < n && initMap[i][j] != initMap[i+1][j]) {
                swap(initMap[i][j], initMap[i+1][j]);
                pickLongestLine(initMap);
                swap(initMap[i][j], initMap[i+1][j]);
            }
            if(j+1 < n && initMap[i][j] != initMap[i][j+1]) {
                swap(initMap[i][j], initMap[i][j+1]);
                pickLongestLine(initMap);
                swap(initMap[i][j], initMap[i][j+1]);
            }
        }
    }
    cout<<result;
}

