#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    map<string, int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string bookname;
        cin>>bookname;
        m[bookname]++;
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    cout<<v[0].first<<"\n";
}
