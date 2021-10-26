#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long n,x,y;
long long sum1,sum2;
vector<pair<long long, long long>> v;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    v.push_back({v[0].first, v[0].second});
    for(int i=0; i<n; i++){
        sum1 += v[i].first*v[i+1].second;
        sum2 += v[i].second*v[i+1].first;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<(double(abs(sum1-sum2))/2);
    
}
