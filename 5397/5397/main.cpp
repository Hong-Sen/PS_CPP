#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s1;
stack<char> s2;

void password(string s){
    for(int i=0; i<s.length(); i++){
        char c = s.at(i);
        if(c == '<'){
            if(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        else if(c == '>'){
            if(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if(c == '-'){
            if(!s1.empty())
                s1.pop();
        }
        else    s1.push(c);
    }
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    while (!s2.empty()) {
        cout<<s2.top();
        s2.pop();
    }
    cout<<"\n";
}

int main(){
    int n;
    string s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        password(s);
    }
}
