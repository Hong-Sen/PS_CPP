//
//  main.cpp
//  1107
//
//  Created by 홍세은 on 2023/01/27.
// 1:17:58

#include <iostream>
#include <cmath>
using namespace std;

int N, M;
bool noKeypad[10];
int result;

bool isValidKey(int now) {
    string strNow = to_string(now);
    for(int i=0; i<strNow.size(); i++) {
        if(noKeypad[int(strNow[i] - '0')]) return false;
    }
    return true;
}

int main(){
    cin>>N>>M;
    int brokenNum;
    for(int i=0; i<M; i++) {
        cin>>brokenNum;
        noKeypad[brokenNum] = true;
    }
    
    if(N == 100 || N == 99 || N == 98 || N == 101 || N == 102 || N == 103) {
        cout<<abs(100 - N);
        return 0;
    }
    
    result = abs(N - 100);
    
    for(int i=0; i<=1000000; i++) {
        if(isValidKey(i)) {
            int tmp = abs(N - i) + to_string(i).size();
            result = min(result, tmp);
        }
    }
    
    cout<<result;
   
}
