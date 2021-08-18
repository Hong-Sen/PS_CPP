#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> v;
    int size = number.size();
    for(int i=0; i<size; i++){
        v.push_back(number[i]);
    }
    sort(v.begin(), v.end());
    int line = v[k-1];
    for(int i=0; i<size; i++){
        int cnt = 0;
        string str = "";
        for(int j=i; j<size; j++){
            if(number[j] <= line){
                if(cnt<k)
                cnt++;
                else
                    str+=number[i];
            }
            else    str += number[j];

        }
        cout<<str<<"\n";
    }
    return answer;
}
int main(){
    cout<<solution("1231234", 3);
}
