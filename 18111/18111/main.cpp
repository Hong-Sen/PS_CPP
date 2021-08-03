#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,b;
vector<int> v;
int resultT = 999999999;
int resultH;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    cin>>n>>m>>b;
    int minB = 256, maxB = -1;
    for(int i=0; i<n*m; i++){
        int x;
        cin>>x;
        v.push_back(x);
        minB = min(minB, x);
        maxB = max(maxB, x);
    }
    
    if(maxB > 256)  maxB = 256;
    if(minB < 0)    minB = 0;
    
    sort(v.begin(), v.end(), cmp);
    
    for(int k=minB; k<=maxB; k++){
        int tmpT = 0;
        int tmpB = b;
        for(int i=0; i<n*m; i++){
            if(v[i] == k)  continue;
            else if(v[i] < k){
                tmpT += k-v[i];
                tmpB -= k-v[i];
                if(tmpB < 0)    tmpT = 999999999;
            }
            else{
                tmpT += (v[i]-k) * 2;
                tmpB += v[i]-k;
            }
        }
        if(tmpT <= resultT){
            resultT = tmpT;
            resultH = k;
        }
    }
    cout<<resultT<<" "<<resultH<<"\n";
    
}
