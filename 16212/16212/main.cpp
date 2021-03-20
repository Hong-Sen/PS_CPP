#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
    cout<<v[i]<<" ";
}
