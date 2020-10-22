#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int alphbet[27];

int main(){
    string s;
    vector<char> v;
    cin>>s;
    int flag = 0;
    int mid = -1;
    for(int i=0; i<s.size(); i++){
        alphbet[s.at(i) - 65]++;
    }
    
    for(int i=0;i<26;i++){
        if(alphbet[i] % 2 == 1){
            flag++;
            mid = i;
            alphbet[i]--;
        }
    }
    
    for(int i=0;i<26;i++){
        if(flag > 1){
            cout<<"I'm Sorry Hansoo"<<"\n";
            return 0;
        }
    }

    for(int i=0;i<26;i++){
        if(alphbet[i] != 0){
            for(int j=0;j<alphbet[i]/2;j++){
                char letter = static_cast<char>(i+65);
                v.push_back(letter);
            }
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }

    if(mid != -1)   cout<<static_cast<char>(mid+65);
        
    reverse(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<"\n";

}
