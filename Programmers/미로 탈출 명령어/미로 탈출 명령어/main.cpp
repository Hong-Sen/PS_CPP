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

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n, M = m, K = k, R = r, C = c;
    
    if(!isPossible(x,y,k)) return "impossible";
    else {
        while(k) {
            k--;
            if(x+1<=n && isPossible(x+1,y,k)) {x += 1; result += 'd';}
            else if(y-1>=1 && isPossible(x,y-1,k)) {y -= 1; result += 'l';}
            else if(y+1<=m && isPossible(x,y+1,k)) {y += 1; result += 'r';}
            else if(x-1>=1 && isPossible(x-1,y,k)) {x -= 1; result += 'u';}
        }
        return result;
    }
}
