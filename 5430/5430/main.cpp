//
//  main.cpp
//  5430
//
//  Created by 홍세은 on 2022/07/10.
//

#include <iostream>
#include <deque>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int T;
string p,s;
int n;

int main(){
    cin>>T;
    while (T--) {
        cin>>p>>n>>s;

        // arr []괄호 삭제
        s.erase(0,1);
        s.erase(s.size()-1,1);
        
        deque<string> dq;
        stringstream ss(s);
        string tmp;
        while (getline(ss, tmp, ',')) {
            dq.push_back(tmp);
        }
        
        bool isError = false;
        bool isR = false;
        
        for(char c: p) {
            if(c == 'R') {
                isR = !isR;
            }
            else {
                if(dq.empty()) {
                    isError = true;
                    break;
                }
                if(isR) dq.pop_back();
                else dq.pop_front();
            }
        }
        if(isError) cout<<"error\n";
        else if(dq.empty()) cout<<"[]\n";
        else {
            cout<<"[";
            while (dq.size() > 1) {
                if(isR) {
                    cout<<dq.back()<<",";
                    dq.pop_back();
                }
                else {
                    cout<<dq.front()<<",";
                    dq.pop_front();
                }
            }
            cout<<dq.front()<<"]\n";
        }
    }
}
