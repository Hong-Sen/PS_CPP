#include <iostream>
#include <vector>
using namespace std;

int n,k,l,cnt;
vector<int> v;

int main(){
    cin>>n>>k>>l;
    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if((a+b+c) >= k ){
            if(a>=l && b>=l && c>=l){
                cnt++;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
            }
        }
    }
    
    cout<<cnt<<"\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}
