#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

string friendsList = "ACFJMNRT";
int answer = 0;
vector<string> dataList;

bool check(string s) {
    for(int i=0; i<dataList.size(); i++){
        int idx1 = s.find(dataList[i][0]);
        int idx2 = s.find(dataList[i][2]);
        int gap = dataList[i][4] - '0';
        char range = dataList[i][3];
        if(range == '=' && abs(idx1 - idx2) - 1 != gap)
            return false;
        else if(range == '<' && abs(idx1 - idx2) - 1 >= gap)
            return false;
        else if(range == '>' && abs(idx1 - idx2) - 1 <= gap)
            return false;
    }
    answer++;
    return true;
}

void dfs(string s){
    if(s.size() == 8) {
        check(s);
        return;
    }
    
    for(int i=0; i<friendsList.size(); i++){
        if(s.find(friendsList[i]) < s.size()) continue;
        dfs(s + friendsList[i]);
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    dataList.clear();
    dataList = data;
    dfs("");
    return answer;
}
