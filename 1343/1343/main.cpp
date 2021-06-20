#include <iostream>
#include <string>
using namespace std;

string result;

void addResult(int cnt){
    if(cnt%4 == 0){
        for(int i=0; i<cnt/4; i++)
        result += "AAAA";
    }
    else{
        for(int i=0; i<cnt/4; i++)
        result += "AAAA";
        for(int i=0; i<cnt%4/2; i++)
        result += "BB";
    }
}

int main(){
    string s;
    cin>>s;
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(s.at(i) == 'X')  cnt++;
        else{
            if(cnt%2 == 1){
                cout<<-1;
                return 0;
            }
            else{
                addResult(cnt);
                result+='.';
                cnt = 0;
            }
        }
        if(i == s.length()-1){
            if(cnt%2 == 1){
                cout<<-1;
                return 0;
            }
            else{
                addResult(cnt);
            }
        }
    }
    
    cout<<result;
}
