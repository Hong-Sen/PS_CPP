// 19:22
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int len = sequence.size();
    int start = 0, end = 0, sum = 0, arrLen = len+2;
    while(end <= len) {
        if(sum < k) sum += sequence[end++];
        else sum -= sequence[start++];
        
        if(sum == k && arrLen > end - start + 1) {
            arrLen = end - start + 1;
            answer.clear();
            answer.push_back(start);
            answer.push_back(end-1);
        }
    }
    return answer;
}
