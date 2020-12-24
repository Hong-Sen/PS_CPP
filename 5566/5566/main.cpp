#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    vector<int> v;
    v.push_back(0); //0번칸은 0
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    int start = 1; // 현재있는 칸
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        start += x; //주사위 눈만큼 이동한 칸
        start += v[start];
        if(start >= n){
            cout<<i+1<<"\n";
            return 0;
        }
    }
}
