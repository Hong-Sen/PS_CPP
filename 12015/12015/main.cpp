//LIS(Longest increasing Subsequence)
//n > 10만 --> O(N^2)로 해결할 수 없음, O(NlogN)으로 구현

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    int n;
    cin>>n;
    v.push_back(-1);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x>v.back()){
            v.push_back(x);
        }
        else{
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    cout<<v.size()-1;
    
    
    
    
}
