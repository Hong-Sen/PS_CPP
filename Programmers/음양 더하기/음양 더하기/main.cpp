#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int size = absolutes.size();
    for(int i=0; i<size; i++){
        if(signs[i])    answer += absolutes[i];
        else    answer -= absolutes[i];
    }
    return answer;
}

int main(){
    vector<int> absolutes;
    vector<bool> signs;
    absolutes.push_back(4);
    absolutes.push_back(7);
    absolutes.push_back(12);
    signs.push_back(true);
    signs.push_back(false);
    signs.push_back(true);
    cout<<solution(absolutes, signs);
}
