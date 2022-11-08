#include <string>
#include <vector>
#include <iostream>
using namespace std;

int order[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill.size(); i++) {
        order[(int)skill[i] - 'A'] = i+1;
    }
    
    for(string s: skill_trees) {
        bool isPossible = true;
        int prev = 0;
        int learning = 1;
        for(char c: s) {
            int value = order[c - 'A'];
            if(value == 0) continue;
            if(value <= prev || learning != value) {
                isPossible = false;
                break;
            }
            learning++;
            prev = value;
        }
        if(isPossible) answer++;
    }
    return answer;
}
