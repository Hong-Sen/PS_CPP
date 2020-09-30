#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    string name;
    vector<string> v; //듣지못한 사람 명단
    vector<string> v2; //듣보잡명단
    
    for(int i=0;i<n;i++){
        cin>>name;
        v.push_back(name);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<m;i++){
        cin>>name;
        if(binary_search(v.begin(), v.end(), name))
            v2.push_back(name);
    }
    sort(v2.begin(), v2.end());
    cout<<v2.size()<<"\n";
    for(int i=0;i<v2.size();i++)
        cout<<v2[i]<<"\n";
    
}
