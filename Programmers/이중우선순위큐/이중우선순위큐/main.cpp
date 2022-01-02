#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for(string s:operations){
        if(s[0] == 'I'){
            string tmp = "";
            for(int i=2; i<=s.size(); i++){
                tmp += s[i];
            }
            int num = 0;
            if(tmp[0] == '-'){
                tmp.erase(0,1);
                num = -1*stoi(tmp);
            }
            else num = stoi(tmp);
            dq.push_back(num);
        }
        else{
            if(!dq.empty()){
                sort(dq.begin(), dq.end());
                if(s[2] == '1'){
                    dq.pop_back();
                }
                else{
                    dq.pop_front();
                }
            }
            
        }
    }
    if(!dq.empty()){
        sort(dq.begin(), dq.end());
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }

    
    return answer;
}
