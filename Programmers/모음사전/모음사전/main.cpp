#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

char alphabet[5] = {'A','E','I','O','U'};
vector<string> v;

void makeWord(string s, int len) {
    if(s.size() == len) {
        v.push_back(s);
        return;
    }
    
    for(int i=0; i<5; i++) {
        makeWord(s + alphabet[i], len);
    }
}

int solution(string word) {
    for(int i=1; i<=5; i++)
        makeWord("", i);
    sort(v.begin(), v.end());
    return find(v.begin(),v.end(), word) - v.begin() + 1;
}
