#include <iostream>

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, bool>> q;
    priority_queue<int> pq;
    for(int i=0; i<priorities.size(); i++){
        int n = priorities[i];
        pq.push(n);
        if(i == location)   q.push({n,true});
        else     q.push({n,false});
    }
    while (!q.empty()) {
        if(pq.top() == q.front().first){
            answer++;
            if(q.front().second)    return answer;
            else{
                q.pop();
                pq.pop();
            }
        }
        else{
            q.push({q.front().first, q.front().second});
            q.pop();
        }
    }
    return answer;
}

int main(){
    vector<int> priorities;
    int location = 0;
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(9);
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(1);
    cout<<solution(priorities, location);
}
