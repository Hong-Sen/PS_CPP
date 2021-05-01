#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v; //{index, num}

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back({i,x});
    }
    sort(v.begin(), v.end(),cmp);
 
    int cnt = 0;
    int tmp = v[0].second;
    v[0].second = 0;
    for(int i=1; i<n; i++){
        if(v[i].second == tmp){
            v[i].second = cnt;
        }
        else{
            tmp = v[i].second;
            v[i].second = ++cnt;
        }
    }

    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++)
        cout<<v[i].second<<" ";
    
}
