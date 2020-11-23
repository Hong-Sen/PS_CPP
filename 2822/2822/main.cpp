#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
bool cmp2(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    vector<pair<int, int>> v; //점수,인덱스
    for(int i=0; i<8; i++){
        int score;
        cin>>score;
        v.push_back(make_pair(score, i));
    }
    sort(v.begin(), v.end(),cmp);
    int sum = 0;
    for(int i=0; i<5; i++){
        sum += v[i].first;
    }
    cout<<sum<<"\n";
    for(int i=0; i<3; i++){
        v.pop_back();
    }
       
    
    sort(v.begin(),v.end(),cmp2);
    for(int i=0; i<5; i++)
        cout<<v[i].second + 1<<" ";
    
    
}
