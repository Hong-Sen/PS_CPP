#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    string s;
    bool flag = true;
    vector<int> arr; //숫자만
    vector<char> bracket; //괄호만
    vector<int> num;
    cin>>s;
    bracket.push_back('+');
    
    for(int i=0; i<s.length(); i++){
        if(s.at(i) != '-' && s.at(i) != '+'){
            int n = (int)(s.at(i)) - 48;
            num.push_back(n);
        }
        else if(s.at(i) == '-' || s.at(i) == '+' ){
            bracket.push_back(s.at(i));
            int realNum = 0;
            int numSize = num.size()-1;
            for(int j=0; j<num.size(); j++){
                realNum += num[j]*(pow(10, numSize));
                numSize--;
            }
            arr.push_back(realNum);
            num.clear();
        }
        if(i==s.length()-1){
            int realNum = 0;
            int numSize = num.size()-1;
            for(int j=0; j<num.size(); j++){
                realNum += num[j]*(pow(10, numSize));
                numSize--;
            }
            arr.push_back(realNum);
        }
    }
    
    int tmp=0,sum=arr[0],index=1;
    while(index != arr.size()){
        if(bracket[index] == '-'){
            if(flag){
                flag = false;
                tmp += arr[index];
            }
            else{
                sum -= tmp;
                tmp = 0;
                tmp += arr[index];
            }
        }
        else {
            if(!flag)   tmp += arr[index];
            else    sum += arr[index];
        }
        if(index == arr.size()-1){
            sum -= tmp;
        }
//        cout<<"sum: "<<sum<<"\n";
//        cout<<"tmp: "<<tmp<<"\n";
        index++;
    }
    cout<<sum<<"\n";
}
