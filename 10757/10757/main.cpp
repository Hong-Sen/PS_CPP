#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> result;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length() > s2.length()){
        swap(s1, s2);
    }
    int size = s2.length();
    string tmp;
    for(int i=0; i<s2.length() - s1.length(); i++){
        tmp += "0";
    }
    s1 = "0" + tmp + s1;
    s2 = "0" + s2;
    
    int flag = 0;
    for(int i=s2.length()-1; i>0; i--){
        int sum = (int)(s1.at(i)) + (int)(s2.at(i)) - 96;
        if(sum + flag >= 10){
            result.push_back((sum+flag)%10);
            flag = 1;
        }
        else{
            result.push_back(sum + flag);
            flag = 0;
        }
    }
    if(flag == 1)    cout<<1;
    for(int i=result.size()-1; i>=0; i--)
    cout<<result[i];
}
