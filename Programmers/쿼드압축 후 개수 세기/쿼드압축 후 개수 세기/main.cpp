#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> isUsed;
int usedCnt;

bool isAllSame(int r, int c, int size) {
    int n = map[r][c];
    for(int i=r; i<r+size; i++) {
        for(int j=c; j<c+size; j++) {
            if(map[i][j] != n) return false;
        }
    }
    return true;
}

void pressure(int r, int c, int size) {
    for(int i=r; i<r+size; i++) {
        for(int j=c; j<c+size; j++) {
            isUsed[i][j] = true;
            usedCnt++;
            if(i == r && j == c) continue;
            map[i][j] = 2;
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    map = arr;
    vector<int> answer;

    for(int i=0; i<arr.size(); i++) {
        vector<bool> v;
        for(int j=0; j<arr[i].size(); j++) {
            v.push_back(false);
        }
        isUsed.push_back(v);
    }

    int size = arr.size();

    while(size != 1) {
        if(usedCnt == arr.size() * arr.size()) break;

        for(int i=0; i<arr.size(); i+=size) {
            for(int j=0; j<arr[i].size(); j+=size) {
                if(!isUsed[i][j] && isAllSame(i,j,size)) {
                    pressure(i,j,size);
                }
            }
        }
        size /= 2;
    }

    answer.push_back(0);
    answer.push_back(0);

    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            if(map[i][j] == 0) answer[0]++;
            else if(map[i][j] == 1) answer[1]++;
        }
    }

    return answer;
}
