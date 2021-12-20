//
//  main.cpp
//  10799
//
//  Created by 홍세은 on 2021/12/20.
//

#include <iostream>
#include <stack>
using namespace std;

string s;
int cnt;
stack<char> st;
bool flag;

int main(){
    cin>>s;
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(flag){
            flag = false;
            continue;
        }
        if(c == '(' && s[i+1] == ')'){
            cnt += st.size();
            flag = true;
            continue;
        }
        if(c == '(') st.push(c);
        if(c == ')'){
            cnt += 1;
            st.pop();
        }
    }
    cout<<cnt;
}
