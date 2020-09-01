#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    //산술평균
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    cout<<round(sum/n)<<'\n';
    
    //중앙값
    sort(v.begin(), v.end());
    cout<<v[n/2]<<'\n';
    
    int range = v[n-1]-v[0];
    
    //최빈값
    int arr[8001] = {0, };
    int maxarr = 0;
    int cnt = 0,result = 0;
    for(int i=0;i<n;i++){
        arr[v[i]+4000]++;
        maxarr = max(maxarr,arr[v[i]+4000]);
    }
    
    for(int i=0;i<8001;i++){
        if(maxarr==arr[i]){
            cnt++;
            result = i-4000;
        }
        if(cnt == 2){
            result = i-4000;
            break;
        }
            
    }
    
    
    
    cout<<result<<'\n';
    

    
    //최댓값-최솟값
    cout<<range<<'\n';
    return 0;
}
