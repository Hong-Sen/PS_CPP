#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue<int> readyQ;
    queue<int> bridgeQ;
    for(int i=0; i<bridge_length; i++)
        bridgeQ.push(0);
    for(int i:truck_weights)
        readyQ.push(i);
    while (!bridgeQ.empty()) {
        if(readyQ.empty()){
            answer += bridgeQ.size();
            break;
        }
        sum -= bridgeQ.front();
        bridgeQ.pop();
        if(sum + readyQ.front() <= weight){
            sum += readyQ.front();
            bridgeQ.push(readyQ.front());
            readyQ.pop();
        }
        else{
            bridgeQ.push(0);
        }
        answer++;
    }
    return answer;
}
int main(){
    vector<int> truck_weights;
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
//    truck_weights.push_back(7);
//    truck_weights.push_back(4);
//    truck_weights.push_back(5);
//    truck_weights.push_back(6);
    cout<<solution(100, 100, truck_weights);
}
