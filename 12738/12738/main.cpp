//LIS
#include <iostream>
#include <vector>
#define MIN -1000000001
using namespace std;

vector<int> v;

int main(){
    int n;
    cin>>n;
    v.push_back(MIN);
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

