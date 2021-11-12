#include <iostream>
#include <string>
using namespace std;

string str,bomb;
string result;

int main(){
    cin>>str>>bomb;
    int bombIdx = bomb.size()-1;
    for(int i=0; i<str.size(); i++){
        result += str[i];
        if(result[result.size()-1] == bomb[bombIdx] && result.size() >= bomb.size()){
            bool flag = true;
            int k = result.size()-1;
            for(int j=bombIdx; j>=0; j--){
                if(result[k] != bomb[j]){
                    flag = false;
                    break;
                }
                k--;
            }
            if(flag){
                result.erase(result.size()-bombIdx-1, bomb.size());
            }
        }
    }
    result == "" ? cout<<"FRULA" : cout<<result;
}
