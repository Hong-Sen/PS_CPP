//
//  main.cpp
//  10610
//
//  Created by 홍세은 on 2021/12/21.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

string s;
long long sum;
bool haveZero;
vector<int> v;

int main(){
    cin>>s;
    for(int i=0; i<s.length(); i++){
        sum += (int)s[i] - '0';
        v.push_back((int)s[i] - '0');
        if(s[i] == '0') haveZero = true;
    }
    if(sum%3 !=0 || !haveZero){
        cout<<-1;
        return 0;
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i<v.size(); i++)
        cout<<v[i];
}
