#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.size();
    string result = "";
    string tmp = "";
    for(int i=0; i<size; i++){
        char c = s.at(i);
        if(c >= '0' && c <= '9'){
            result += c;
            continue;
        }
        tmp += c;
        if(tmp == "zero"){
            result += "0";
            tmp = "";
        }
        else if(tmp == "one"){
            result += "1";
            tmp = "";
        }
        else if(tmp == "two"){
            result += "2";
            tmp = "";
        }
        else if(tmp == "three"){
            result += "3";
            tmp = "";
        }
        else if(tmp == "four") {
            result += "4";
            tmp = "";
        }
        else if(tmp == "five") {
            result += "5";
            tmp = "";
        }
        else if(tmp == "six") {
            result += "6";
            tmp = "";
        }
        else if(tmp == "seven"){
            result += "7";
            tmp = "";
        }
        else if(tmp == "eight"){
            result += "8";
            tmp = "";
        }
        else  if(tmp == "nine"){
            result += "9";
            tmp = "";
        }
    }
    answer = stoi(result);
    return answer;
}

int main(){
    string s =  "one4seveneight";
    cout<<solution(s);
}
