#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i:numbers){
        v.push_back(to_string(i));
    }
    sort(v.begin(), v.end(), cmp);
    int sizeV = v.size();
    for(int i=0; i<sizeV; i++){
        if(answer.empty() && v[i] == "0")   continue;
        answer += i;
    }
    if(answer.empty())  answer = "0";
    return answer;
}

int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(30);
    v.push_back(34);
    v.push_back(5);
    v.push_back(9);

    cout<<solution(v);
}
