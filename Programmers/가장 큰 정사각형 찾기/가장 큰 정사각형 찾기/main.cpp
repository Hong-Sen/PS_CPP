#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    for(int i=0; i<board.size(); i++) {
        if(board[0][i] == 1) {
            answer = 1;
            break;
        }
    }
    
    for(int i=0; i<board[0].size(); i++) {
        if(board[i][0] == 1) {
            answer = 1;
            break;
        }
    }
    
    for(int i=1; i<board.size(); i++) {
        for(int j=1; j<board[i].size(); j++) {
            if(board[i][j] != 1)  continue;
            board[i][j] = min(min(board[i][j-1], board[i-1][j-1]), board[i-1][j]) + 1;
            answer = max(answer, board[i][j] * board[i][j]);
        }
    }

    return answer;
}
