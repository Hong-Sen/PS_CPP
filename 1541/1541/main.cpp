#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;
vector<bool> sign; //0 = -, 1 = +

int main(){
    string s;
    cin>>s;
    s += "+";
    sign.push_back(1);
    //배열에 숫자끼리,부호끼리 넣어주기
    string strtmp = "";
    for(int i=0; i<s.length(); i++){
        if(s.at(i) == '+'){
            if(strtmp != "")    v.push_back(stoi(strtmp));
            strtmp = "";
            sign.push_back(1);
        }
        else if(s.at(i) == '-'){
            if(strtmp != "")    v.push_back(stoi(strtmp));
            strtmp = "";
            sign.push_back(0);
            
        }
        else{
            strtmp += s.at(i);
        }
    }
    //-이면 괄호묶기
    int tmp = 0;
    int result = 0;
    bool flag = false;
    for(int i=0; i<v.size(); i++){
        if(!sign[i] && !flag){
            flag = true;
            tmp += v[i];
        }
        else if(sign[i] && flag){
            tmp += v[i];
        }
        else if(!sign[i] && flag){
            result += -tmp;
            tmp = 0;
            tmp += v[i];
        }
        else{
            result += v[i];
        }
        if(i==v.size()-1){
            result += -tmp;
        }
    }
    cout<<result<<"\n";
}
