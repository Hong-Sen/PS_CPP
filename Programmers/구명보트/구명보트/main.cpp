#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

/* 맨 앞사람 + 맨 뒷사람 > limit 인 경우
   맨 뒷사람은 어느 누구와 같이 탈 수 없음
   맨 뒷사람은 바로 보내기 */

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    sort(people.begin(), people.end());
    for(int i: people) dq.push_back(i);
    
    while(!dq.empty()) {
        if(dq.size() == 1) {
            answer++;
            break;
        }
        if(dq.front() + dq.back() > limit) {
            dq.pop_back();
            answer++;
        }
        else {
            dq.pop_front();
            dq.pop_back();
            answer++;
        }
    }
    return answer;
}

int main(){
   cout<<solution({70, 50, 80, 50} ,100);
}
