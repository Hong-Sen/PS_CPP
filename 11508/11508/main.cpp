#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int i = v.size()-1;
    int sum = 0;
    while(1){
        if(i==0){
            sum += v[i];
            break;
        }
        else if(i<0){
            break;
        }
        else{
            sum += v[i]+v[i-1];
            i -= 3;
        }
        
    }
    cout<<sum;
}
