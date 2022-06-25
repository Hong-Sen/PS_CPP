#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isRight(string s) {
    stack<char> st;
    
    for(char c: s){
        if(c == ')') {
            if(st.top() != '(') return false;
            st.pop();
        }
        else if(c == ']') {
            if(st.top() != '[') return false;
            st.pop();
        }
        else if(c == '}') {
            if(st.top() != '{') return false;
            st.pop();
        }
        else {
            st.push(c);
        }
    }
    
    if(!st.empty()) return false;
    
    return true;
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.size(); i++) {
        s += s[0];
        s.erase(0,1);
        if(isRight(s)) answer++;
    }
    return answer;
}
