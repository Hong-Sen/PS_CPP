#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0, sum2 = 0, maxIdx = queue1.size() * 2;
    int idx1 = 0, idx2 = 0;
    queue<int> q1, q2;
    
    for(int i: queue1) {
        q1.push(i);
        sum1 += i;
    }
    for(int i: queue2) {
        q2.push(i);
        sum2 += i;
    }
    
    // 작업이 queue의 크기의 2번이상 하게 되면 합을 같게 만들 수 없음(원상복귀 되므로)
    while(idx1 <= maxIdx && idx2 <= maxIdx) {
        if(sum1 == sum2) {
            return answer;
        }
        
        if(sum1 > sum2) {
            int top = q1.front();
            sum1 -= top;
            sum2 += top;
            q1.pop();
            q2.push(top);
            idx1++;
        }
        else {
            int top = q2.front();
            sum2 -= top;
            sum1 += top;
            q2.pop();
            q1.push(top);
            idx2++;
        }
        
        answer++;
    }
    
    return -1;
}
