#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int n1, int n2){
    return n1 > n2;
}

int main(){
    long n;
    cin>>n;
    vector<int> v;
 
    while(n>0){
        v.push_back(n%10);
        n /= 10;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0;i<v.size();i++)
    cout<<v[i];
    
    cout<<"\n";
}
