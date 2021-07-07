#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> map;
    for(string s: participant){
        map[s]++;
    }
    for(string s: completion){
        map[s]--;
    }
    for(auto it: map){
        if(it.second > 0)
            return it.first;
    }
}
