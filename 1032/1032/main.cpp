#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> v;
    
    if(n == 1){
        string s;
        cin>>s;
        cout<<s<<"\n";
        return 0;
    }
    
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    
    for(int i=0; i<v[0].length(); i++){
        bool flag = true;
        char c = '0';
        for(int j=0; j<n-1; j++){
            if(v[j].at(i) != v[j+1].at(i))  flag = false;
            c = v[j].at(i);
        }
        if(flag)    cout<<c;
        else    cout<<"?";
    }
    cout<<"\n";
}
