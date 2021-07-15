#include <iostream>
#include <iostream>
#include<string>
#include <cstring>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int size = s.size();
    if(size%2 == 1)    return answer;
    int i=0;
    stack<char> st;
    st.push(s[i++]);
    while (i < size) {
        if(!st.empty() && s[i] == st.top()){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
        i++;
    }
    
    if(st.empty())   answer = 1;
    return answer;
}

int main(){
    cout<<solution("baabaa");
}
