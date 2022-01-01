#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(),cmp);
    queue<pair<int, int>> q;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int curTime = jobs[0][0] + jobs[0][1];
    vector<int> endTime;
    endTime.push_back(curTime - jobs[0][0]);
    
    int i = 1;
    while (i < jobs.size() || !pq.empty()) {
        if(i<jobs.size() && jobs[i][0] <= curTime) {
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
            continue;
        }
        if(!pq.empty()){
            curTime += pq.top().first;
            endTime.push_back({curTime - pq.top().second});
            pq.pop();
        }
        else{
            curTime = jobs[i][0];
        }
    }
    
    for(int i=0; i<endTime.size(); i++){
        answer += endTime[i];
    }
    answer /= endTime.size();
    return answer;
}

int main(){
    solution({{0, 5}, {2, 10}, {10000, 2}});
}
