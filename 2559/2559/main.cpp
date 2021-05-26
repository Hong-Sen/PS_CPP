#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    int sum = 0, result = 0;
    vector<int> v;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    for(int j=0; j<k; j++){
        sum += v[j];
    }
    result = sum;
    int index = 0;
    for(int i=k; i<v.size(); i++){
        sum = sum - v[index] + v[i];
        index++;
        result = max(result,sum);
    }
    cout<<result;
}
