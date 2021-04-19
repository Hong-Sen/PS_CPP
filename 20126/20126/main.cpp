#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m,s;
    vector<pair<int, int>> v;
    cin>>n>>m>>s;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    int time = -1;

    if(m <= v[0].first)   cout<<0;
    else{
        for(int i=0; i<v.size()-1; i++){
                if(v[i+1].first - v[i].first - v[i].second >= m){
                    time = v[i].first + v[i].second;
                    if(time + m <= s)   break;
                    else   time = -1;
                }
            }
        if(time == -1 && v[v.size()-1].first + v[v.size()-1].second + m <= s)
            time = v[v.size()-1].first + v[v.size()-1].second;
        cout<<time;
    }
    
}
