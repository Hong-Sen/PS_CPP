#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<string> v;

int main(){
    cin>>s;
    int sSize = s.size();
    for(int i=0; i<sSize; i++){
        v.push_back(s);
        s.erase(0,1);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<"\n";
}
