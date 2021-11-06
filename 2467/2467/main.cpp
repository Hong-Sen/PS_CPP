#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
long long arr[100001];
vector<int> result;
long long sum = 2000000000;

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int start = 0, end = n-1;
    while (start < end) {
        if(abs(arr[start] + arr[end]) < sum){
            sum = abs(arr[start] + arr[end]);
            result.clear();
            result.push_back(arr[start]);
            result.push_back(arr[end]);
        }
        if(arr[start] + arr[end] < 0)   start++;
        else    end--;
        
    }
    cout<<result[0]<<" "<<result[1]<<"\n";
}
