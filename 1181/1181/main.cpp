#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const string &s1,const string &s2){
    if(s1.size()==s2.size())
        return s1<s2;
    return s1.size()<s2.size();
}
int main(){
    vector<string> v;
    int n;
    cin>>n;
    string str;
    
    for(int i=0;i<n;i++){
        cin>>str;
        v.push_back(str);
    }
    
    sort(v.begin(), v.end(),comp);//사전순으로 정렬
    cout<<v[0]<<'\n';
    for(int i=1;i<v.size();i++){
        if(v[i-1]!=v[i]){
            cout<<v[i]<<'\n';
    }
}
}
