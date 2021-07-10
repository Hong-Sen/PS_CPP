#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<double> q;
    for(int i=0; i<progresses.size(); i++){
        q.push(ceil(double(100 - progresses[i]) / double(speeds[i])));
    }
    int cnt = 1;
    while (!q.empty()) {
        double cur = q.front();
        q.pop();
        while (cur >= q.front() && !q.empty()) {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
        cnt = 1;
    }
    return answer;
}

int main(){
    vector<int> progresses;
    vector<int> speeds;
    progresses.push_back(95);
    progresses.push_back(90);
    progresses.push_back(99);
    progresses.push_back(99);
    progresses.push_back(80);
    progresses.push_back(99);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    
    solution(progresses, speeds);
}
