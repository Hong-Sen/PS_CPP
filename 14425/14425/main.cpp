#include <iostream>
#include <map>
using namespace std;

int n,m;
string str[10001];
map<string,int> strMap;
string s;
int cnt;

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        strMap.insert({s,0});
    }
    for(int i=0; i<m; i++){
        cin>>s;
        if(strMap.find(s) != strMap.end())  cnt++;
    }
    cout<<cnt;
}
