#include <iostream>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        int max = 0;
        string result;
        for(int i=0; i<n; i++){
            string s;
            int x;
            cin>>s>>x;
            if(x > max){
                max = x;
                result = s;
            }
        }
        cout<<result<<"\n";
    }
}
