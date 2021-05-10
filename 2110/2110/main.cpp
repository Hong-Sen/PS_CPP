#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,c;
vector<int> v;
int result;

int binarySearch(int mid, int cnt){
    int std = v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i] - std >= mid){
            cnt++;
            std = v[i];
        }
    }
    return cnt;
}
int main(){
    cin>>n>>c;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int start = 1;
    int end = v[n-1];
    while (start <= end) {
        int mid = (start+end)/2;
        int cnt = binarySearch(mid, 1);
        if(cnt >= c){
            result = max(result,mid);
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<result;
}
