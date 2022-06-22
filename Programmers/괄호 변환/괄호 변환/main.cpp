#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// 3
bool isRightStr(string s) {
    stack<char> st;
    int i = 0;
    while(i < s.size()) {
        if(s[i] == '(') st.push('(');
        else {
            if(st.empty()) {
                return false;
            }
            st.pop();
        }
        i++;
    }
    return true;
}


string solution(string p) {
    string answer = "";
    
    // 1
    if(p == "") return p;
    
    // 2
    string u = "";
    string v = "";
    int r = 0, l = 0;
    for(int i=0; i<p.size(); i++) {
        u += p[i];
        if(p[i] == '(') r++;
        else l++;
        if(r == l) {
            v = p.substr(i+1);
            break;
        }
    }
    // 3
    if(isRightStr(u)) {
        // 3-1
        u += solution(v);
        answer = u;
        return answer;
       }
    else {
        // 4
        string s = "(";
        s += solution(v);
        s += ')';
        for(int j=1; j<u.size()-1; j++) {
            s += u[j] == '(' ? ')' : '(';
        }
        answer = s;
    }
    
    return answer;
}
