#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M, R, C, K;
char direction[4] = {'d', 'l', 'r', 'u'};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string result;

bool isPossible(int x, int y, int cnt) {
    int d = abs(x - R) + abs(y - C);
    if(cnt < d || (cnt - d) % 2 != 0) return false;
    return true;
}

void dfs(int x, int y, int cnt, string s) {
    if(result != "" || cnt > K) return;
    
    if(x == R && y == C && cnt == 0) {
        result = s;
        return;
    }
    
    for(int i=0; i<4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX >= 1 && nextX <=N && nextY>=1 && nextY <=M) {
            if(!isPossible(nextX, nextY, cnt-1))  {
                continue;
            }
            dfs(nextX, nextY, cnt-1, s + direction[i]);
        }
            
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n, M = m, K = k, R = r, C = c;
    
    if(!isPossible(x,y,k)) return "impossible";
    else {
        dfs(x,y,k,"");
        return result;
    }
}
