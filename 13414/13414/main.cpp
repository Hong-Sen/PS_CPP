#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

string arr[500001];
map<string, int> m;

bool cmp(pair<string, int> a,pair<string, int> b){
    return a.second < b.second;
}

int main(int argc, const char * argv[]) {
    int l,k;
    cin>>k>>l;
    for(int i=0; i<l; i++){
        cin>>arr[i];
    }
    int index = l;
    for(int i=l-1; i>=0; i--){
        m.insert(make_pair(arr[i], index--));
    }
    
    vector<pair<string, int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    
    if(v.size() >= k){
        for(int i=0; i<k; i++)
           cout<<v[i].first<<"\n";
    }
    else{
        for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<"\n";
    }
   
}
