//
//  main.cpp
//  17219
//
//  Created by 홍세은 on 2021/12/12.
//

#include <iostream>
#include <map>
using namespace std;

int N,M;
string site,password;
map<string, string> m;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>site>>password;
        m.insert({site, password});
    }
    for(int i=0; i<M; i++){
        cin>>site;
        if(m.find(site) != m.end()) cout<<m.find(site)->second<<"\n";
    }
}
