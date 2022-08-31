#include <string>
#include <vector>
#include <iostream>
using namespace std;

int type[26];

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i=0; i<survey.size(); i++) {
        switch(choices[i]) {
            case 1:
                type[int(survey[i][0]-'A')] += 3;
                break;
            case 2:
                type[int(survey[i][0])-'A'] += 2;
                break;
            case 3:
                type[int(survey[i][0])-'A'] += 1;
                break;
            case 5:
                type[int(survey[i][1])-'A'] += 1;
                break;
            case 6:
                type[int(survey[i][1])-'A'] += 2;
                break;
            case 7:
                type[int(survey[i][1])-'A'] += 3;
                break;
        }
    }
    if(type[int('R') - 'A'] >= type[int('T') - 'A']) answer += 'R';
    else answer += 'T';
        
    if(type[int('C') - 'A'] >= type[int('F') - 'A']) answer += 'C';
    else answer += 'F';
        
    if(type[int('J') - 'A'] >= type[int('M') - 'A']) answer += 'J';
    else answer += 'M';
        
    if(type[int('A') - 'A'] >= type[int('N') - 'A']) answer += 'A';
    else answer += 'N';
    
    return answer;
}
