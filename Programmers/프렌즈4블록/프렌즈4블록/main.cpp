#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool flag;

int getCnt(int m, int n, vector<string> board) {
    int cnt = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == '0') cnt++;
        }
    }
    return cnt;
}

vector<string> remove(int m, int n, vector<string> board) {
    vector<string> map = board;
    bool isRemoved = false;
    for(int i=0; i<m-1; i++) {
        for(int j=0; j<n-1; j++) {
            char c = board[i][j];
            if(c == '0') continue;
            if(c == board[i][j+1] && c == board[i+1][j] && c == board[i+1][j+1]) {
                map[i][j] = '0';
                map[i][j+1] = '0';
                map[i+1][j] = '0';
                map[i+1][j+1] = '0';
                isRemoved = true;
            }
        }
    }
    flag = isRemoved;
    return map;
}

vector<string> drop(int m, int n, vector<string> board) {
    for(int i=0; i<n; i++) {
        queue<char> q;
        for(int j=m-1; j>=0; j--) {
            if(board[j][i] != '0') q.push(board[j][i]);
        }
        for(int j=m-1; j>=0; j--) {
            if(q.empty()) board[j][i] = '0';
            else {
                board[j][i] = q.front();
                q.pop();
            }
        }
    }
    return board;
}

int solution(int m, int n, vector<string> board) {
    flag = true;
    
    while(1) {
        if(!flag) break;
        board = remove(m,n,board);
        board = drop(m,n,board);
    }
    
    return getCnt(m,n,board);
}
