#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string answer = "";
    int n = new_id.length();
    for(int i=0; i<n; i++){
        char c = new_id.at(i);
        if(c >= 'A' && c<= 'Z'){
            c = tolower(c);
            answer += c;
        }
        else if((c>='a'&& c<='z') || (c>='0' && c<='9') || c=='-' || c=='_' || c=='.'){
            answer += c;
        }
    }
    n = answer.length();
    string tmp = "";
    tmp += answer.at(0);
    for(int i=1; i<n; i++){
        if(!(answer.at(i) == '.' && answer.at(i-1) == '.'))
            tmp += answer.at(i);
    }
    answer = tmp;
    if(answer.at(0) == '.'){
        answer.erase(0,1);
    }
    if(answer.size() > 0 && answer.at(answer.size()-1) == '.'){
        answer.erase(answer.size()-1);
    }
    if(answer.length()==0)    answer = "a";
    if(answer.length() > 15){
        n = answer.length();
        answer.erase(15, n);
        if(answer.at(14) == '.')    answer.erase(14);
    }
    if(answer.length()<3){
        n = answer.length();
        for(int i=n; i<3; i++){
            answer += answer.at(n-1);
        }
    }
    return answer;
}

int main(){
    string s;
    cin>>s;
    cout<<solution(s)<<"\n";
}

