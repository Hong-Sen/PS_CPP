#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<long long, long> card;

bool cmp(pair<long long, long> a,pair<long long, long> b){
    if(a.second == b.second)    return a.first < b.first;
    else    return a.second > b.second;
}

int main(){
    long n;
    cin>>n;
    for(int i=0; i<n; i++){
        long long x;
        cin>>x;
        if(card.find(x) == card.end())  card.insert(pair<long long, long>(x,1));
        else    card[x]++;
    }
    vector<pair<long long, long>> v(card.begin(),card.end());
    sort(v.begin(),v.end(), cmp);
    cout<<v[0].first;
}
