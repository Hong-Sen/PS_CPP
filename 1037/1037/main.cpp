#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,x;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    
    int index = 0;
    while(1){
        int result = v[index] * v[v.size()-1];
        for(int i=0;i<v.size();i++){
            if(result % v[i] != 0)
                break;
        }
        cout<<result<<"\n";
        return 0;
    }
}
