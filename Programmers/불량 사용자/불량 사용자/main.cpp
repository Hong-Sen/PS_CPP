#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

set<string> st;
string arr[9];

void dfs(vector<string> user_id, vector<string> banned_id, int idx, string num){
    if(idx == banned_id.size()){
        if(num.size() < banned_id.size())   return;
        for(int i=0; i<idx; i++){
            arr[i] = num[i];
        }
        sort(arr, arr+banned_id.size());
        string s;
        for(int i=0; i<banned_id.size(); i++){
            s += arr[i];
        }
//        cout<<"s: "<<s<<"\n";
        st.insert(s);
        return;
    }
    for(int i=0; i<user_id.size(); i++){
        if(banned_id[idx].size() != user_id[i].size()) continue;
        if(num.find(to_string(i)) < idx+1){
            continue;
        }
        bool flag = true;
        for(int j=0; j<user_id[i].size(); j++){
            if(banned_id[idx][j] == '*') continue;
            if(banned_id[idx][j] != user_id[i][j]){
                flag = false;
                break;
            }
        }
        if(flag){
            dfs(user_id, banned_id, idx+1, num + to_string(i));
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0, "");
    return st.size();
}

int main(){
//    cout<<solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},{"*rodo", "*rodo", "******"});
//    int i = 5;
//    string s = "--- ";
//    cout<<s + to_string(i);
    cout<<solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},{"fr*d*", "*rodo", "******", "******"});
}
