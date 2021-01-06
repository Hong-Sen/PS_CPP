#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int sum = 0;
    do {
        int temp = 0;
        for(int i=0; i<v.size()-1; i++)
            temp += abs(v[i] - v[i+1]);
        if(temp > sum) sum = temp;
        
    } while (next_permutation(v.begin(), v.end()));
    cout<<sum;
}
