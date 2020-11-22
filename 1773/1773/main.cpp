#include <iostream>
using namespace std;

bool isvisted[2000000];

int main(){
    int n,t;
    cin>>n>>t;
    int sum = 0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        int k = x;
        while(x <= t){
            if(!isvisted[x]){
                sum ++;
                isvisted[x] = true;
            }
            x += k;
        }
    }
    cout<<sum<<"\n";
}
