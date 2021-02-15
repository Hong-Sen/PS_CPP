#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    int result = 0;
    stack<pair<int, int>> st;
    pair<int, int> cur = make_pair(-1, -1);
    cin>>n;
    for(int i=0; i<n; i++){
        int hw;
        cin>>hw;
        if(hw==1){
            int score,time;
            cin>>score>>time;
            if(cur.first != -1)   st.push(cur);
            cur = make_pair(score, time-1);
        }
        else{
            if(cur.first != -1) cur.second--;
        }
        
        if(cur.second == 0){
            result += cur.first;
            if(st.size()){
                cur = st.top();
                st.pop();
            }
            else{
                cur = make_pair(-1, -1);
            }
        }
    }
    cout<<result;
}
