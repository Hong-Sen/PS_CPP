#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    //next_permutation: 다음 수열 반환
    //prev_permutation: 이전 수열 반환
    //마지막 순열이라면 next_permutation == false
    
    bool flag = next_permutation(v.begin(),v.end());
    if(!flag){
        cout<<"-1\n";
        return 0;
    }
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }

    
}
