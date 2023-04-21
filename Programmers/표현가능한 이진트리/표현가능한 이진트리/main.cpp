#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

string to_binary(long long n) {
    string result = "";
    while(n != 0) {
        result = to_string(n % 2) + result;
        n /= 2;
    }
    return result;
}

bool checkTree(string s, char parent) { // 부모가 0일때, 자식이 1인 경우 찾기
    int mid = s.size()/2;
    if(parent == '0') {
        if(s[mid] == '1') return false;
    }
    if(s.size() == 1) return true;
    
    if(parent == '1') parent = s[mid];
    return checkTree(s.substr(0,mid), parent) && checkTree(s.substr(mid+1, mid), parent);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(long long i: numbers) {
        string s = to_binary(i);
        // 포화이진트리의 노드 개수 = 2^높이 - 1
        int idx = 1;
        int len = s.size();
        while(1) {
            int gap = len - (pow(2,idx) - 1);
            if(gap == 0) break;
            else if(gap < 0) {
                for(int j=0; j<abs(gap); j++) // 포화이진트리로 만들어 주기
                    s = '0' + s;
                break;
            }
            idx++;
        }
        answer.push_back(checkTree(s, s[s.size()/2]));
    }
    
    return answer;
}
