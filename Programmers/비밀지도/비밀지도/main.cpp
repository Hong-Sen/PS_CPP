#include <string>
#include <vector>
#include <iostream>
using namespace std;

string toBinary(int n) {
    string s = "";
    while(n != 0) {
        s = (n % 2 == 0 ? "0" : "1") + s;
        n /= 2;
    }
    
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++) {
        string s1 = toBinary(arr1[i]);
        string s2 = toBinary(arr2[i]);
        
        while(s1.size() < n) {
            s1 = "0" + s1;
        }
        
        while(s2.size() < n) {
            s2 = "0" + s2;
        }
        
        string result = "";
        
        for(int j=0; j<n; j++) {
            if(s1[j] == '0' && s2[j] == '0') result += " ";
            else result += "#";
        }
        
        answer.push_back(result);
    }
    return answer;
}
