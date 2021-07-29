#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> map;
    vector<pair<string, string>> name;
    vector<pair<string, string>> tmp;
    for(string s:record){
        string str[3] = {"", "", ""};
        int index = 0;
        for(char c:s){
            if(c == ' '){
                index++;
            }
            else{
                str[index] += c;
            }
        }
        if(s[0] == 'E'){
            name.push_back({str[1], str[2]});
            tmp.push_back({"E", str[1]});
        }
        else if(s[0] == 'C'){
            name.push_back({str[1], str[2]});
        }
        else{
            tmp.push_back({"L", str[1]});
        }
    }
    int nSize = name.size();
    for(int i=nSize-1; i>=0; i--){
        map.insert({name[i].first, name[i].second});
    }
    int tSize = tmp.size();
    for(int i=0; i<tSize; i++){
        if(tmp[i].first == "E"){
            string s = map.find(tmp[i].second)->second;
            s += "님이 들어왔습니다.";
            answer.push_back(s);
        }
        else{
            string s = map.find(tmp[i].second)->second;
            s += "님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    return answer;
}

    int main(){
        vector<string> v;
        v.push_back("Enter uid1234 Muzi");
        v.push_back("Enter uid4567 Prodo");
        v.push_back("Leave uid1234");
        v.push_back("Enter uid1234 Prodo");
        v.push_back("Change uid4567 Ryan");
        solution(v);
    }
