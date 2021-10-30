#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string input;
string s;
stack<char> st;

int main(){
    cin>>input;
    for(int i=0; i<input.size(); i++){
        char c = input[i];
        if(c == '+' || c == '-'){
            while (!st.empty() && st.top() != '(') {
                s += st.top();
                st.pop();
            }
            st.push(c);
        }
        else if(c == '*' || c == '/'){
            while (!st.empty()&& (st.top() == '*' || st.top() == '/')) {
                s += st.top();
                st.pop();
            }
            st.push(c);
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while (!st.empty()) {
                if(st.top() == '('){
                    st.pop();
                    break;
                }
                s += st.top();
                st.pop();
            }
        }
        else{
            s += c;
        }
    }
    while (!st.empty()) {
        s += st.top();
        st.pop();
    }
    cout<<s<<"\n";
}
