#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    queue<int> q[31];
    int bSize = board.size();
    for(int j=0; j<bSize; j++){
        for(int i=0; i<bSize; i++){
            if(board[j][i] != 0)
                q[i].push(board[j][i]);
        }
    }
    for(int i:moves){
        if(!q[i-1].empty()){
            if(!st.empty() && st.top() == q[i-1].front()){
                st.pop();
                q[i-1].pop();
                answer+=2;
            }
            else{
                st.push(q[i-1].front());
                q[i-1].pop();
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> board;
    vector<int> moves;
    board.push_back({0,0,0,0,0});
    board.push_back({0,0,1,0,3});
    board.push_back({0,2,5,0,1});
    board.push_back({4,2,4,4,2});
    board.push_back({3,5,1,3,1});
    
    moves.push_back(1);
    moves.push_back(5);
    moves.push_back(3);
    moves.push_back(5);
    moves.push_back(1);
    moves.push_back(2);
    moves.push_back(1);
    moves.push_back(4);
    cout<<solution(board, moves);
}
