//
//  main.cpp
//  3273
//
//  Created by 홍세은 on 2022/02/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,num,x;
vector<int> v;
int answer;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        v.push_back(num);
    }
    cin>>x;
    
    sort(v.begin(), v.end());
    
    int start = 0, end = n-1;
    while (start < end) {
        if(v[start] + v[end] == x){
            answer++;
        }
        if(v[start] + v[end] <= x){
            start++;
        }
        else {
            end--;
        }
    }
    cout<<answer<<"\n";
}
