#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N,K,M,V,C;
vector<pair<int, int>> gem;
vector<int> bag;
long long value;

int main(){
    ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>M>>V;
        gem.push_back({M,V});
    }
    for(int i=0; i<K; i++){
        cin>>C;
        bag.push_back(C);
    }
    sort(gem.begin(), gem.end());
    sort(bag.begin(),bag.end());
    
    priority_queue<int> pq;
    int j = 0;
    for(int i=0; i<K; i++){
        while (j<N && gem[j].first <= bag[i]) {
            pq.push(gem[j].second);
            j++;
        }
        if(!pq.empty()){
            value += pq.top();
            pq.pop();
        }
    }
    cout<<value;
}
