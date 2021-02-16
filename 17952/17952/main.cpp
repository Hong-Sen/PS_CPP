#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    int result = 0;
    stack<pair<int, int>> st;
    cin>>n;
    for(int i=0; i<n; i++){
        int hw,score,time;
        cin>>hw;
        if(hw == 1){
            cin>>score>>time;
            if(time == 1){
                result += score;
            }
            else{
                st.push(make_pair(score, time-1));
            }
        }
        else if(hw==0 && st.size()>0){
            int tmpTime = st.top().second;
            int tmpScore = st.top().first;
            st.pop();
            if(tmpTime == 1){
                result += tmpScore;
            }
            else{
                st.push(make_pair(tmpScore, tmpTime-1));
            }
        }
    }
    cout<<result;
}
