#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0) return cities.size() * 5;
    
    vector<string> cache;
    for(string s: cities) {
        string city = "";
        for(int i=0; i<s.size(); i++) {
            city += toupper(s[i]);
        }
        auto it = find(cache.begin(), cache.end(), city);
        // cache에 city가 있을 때
        if(it != cache.end()) {
            int idx = it - cache.begin();
            for(int i=idx; i<cache.size()-1; i++) {
                cache[i] = cache[i+1];
            }
            cache.pop_back();
            cache.push_back(city);
            answer += 1;
        }
        // cache에 city가 없을 때
        else {
            // cache에 자리가 남는 경우
            if(cache.size() < cacheSize) {
                cache.push_back(city);
            }
            // cache가 만석인 경우
            else {
                for(int i=1; i<cacheSize; i++) {
                    cache[i-1] = cache[i];
                }
                cache.pop_back();
                cache.push_back(city);
            }
            answer += 5;
        }
    }
    return answer;
}
