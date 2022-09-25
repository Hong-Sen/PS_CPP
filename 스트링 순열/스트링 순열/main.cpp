//
//  main.cpp
//  스트링 순열
//
//  Created by 홍세은 on 2022/09/25.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int t,result;
string s;
vector<int> values;
bool isVisited[9];

void caculate(int sum, int cnt, bool visited[9]) {
    if(cnt==s.size()) {
        if(sum>0) result++;
        return;
    }
    for(int i=0;i<values.size();i++) {
        if(visited[i]) continue;
        visited[i] = true;
        if(cnt%2==1) caculate(sum-values[i], cnt+1, visited);
        else caculate(sum + values[i], cnt+1, visited);
        visited[i] = false;
    }
}

int main(){
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>s;
        result = 0;
        values.clear();
        memset(isVisited, false, sizeof(isVisited));
        for(char c: s) {
            values.push_back(int(c) - 'a');
        }
        caculate(0, 0, isVisited);
        cout<<result<<endl;
    }
}
