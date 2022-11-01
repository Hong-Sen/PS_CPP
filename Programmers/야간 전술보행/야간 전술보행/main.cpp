//
//  main.cpp
//  야간 전술보행
//
//  Created by 홍세은 on 2022/11/01.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int possible[10000001]; // 0 = 초기화, 1 = 가능, 2 = 불가능

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int answer = 0;
 
    for(int i=0; i<scope.size(); i++) {
        sort(scope[i].begin(), scope[i].end()); // !!!
        int cur = 0;
        int minDis = scope[i][0];
        int maxDis = scope[i][1];
        int workTime = times[i][0];
        int restTime = times[i][1];
        while(cur <= maxDis) {
            for(int l=1; l<=workTime; l++) {
                cur += 1;
                if(cur >= minDis && cur <= maxDis) possible[cur] = 2;
            }
            cur += restTime;
        }
      }

    for(int i=1; i<=distance; i++) {
        answer = i;
        if(possible[i] == 2) {
            break;
        }
    }
    return answer;
}
