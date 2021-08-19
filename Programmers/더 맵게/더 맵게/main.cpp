#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool flag = false;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i:scoville){
        pq.push(i);
    }
    while(1){
        if(pq.top() >= K)   return answer;
        if(pq.size() <= 1) return -1;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second*2);
        answer++;
    }
    return -1;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout<<solution(v, 11);
}
