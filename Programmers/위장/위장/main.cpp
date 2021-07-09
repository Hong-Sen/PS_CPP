#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    for(int i=0; i<clothes.size(); i++){
        map[clothes[i][1]]++;
    }
    if(map.size() > 1){
        for(auto it:map){
            answer *= it.second+1;
        }
        answer -= 1;
    }
    else    answer = clothes.size();
    return answer;
}
int main(){
    vector<vector<string>> v;
    v.push_back({"crowm1ask", "face"});
    v.push_back({"crowmask", "face"});
    v.push_back({"crowm12ask", "face"});
    cout<<solution(v)<<"\n";
}
