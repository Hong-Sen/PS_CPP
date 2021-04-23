#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gcd(int a, int b){
    while (b!=0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int solve(vector<int> v){
    int max = 0;
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            max = (max < gcd(v[i], v[j])) ? gcd(v[i], v[j]) : max;
        }
    }
    return max;
}

int main(){
    int t;
    cin>>t;
    cin.ignore();  //getline 하고 cin>> 같이 사용시 필수!
    for(int i=0; i<t; i++){
        string str;
        getline(cin, str);
        vector<int> v;
        string tmp;
        for(int i=0; i<str.length(); i++){
            if(str[i] == ' ' ){
                v.push_back(stoi(tmp));
                tmp = "";
            }
            else if(i==str.length()-1){
                tmp += str[i];
                v.push_back(stoi(tmp));
            }
            else    tmp += str[i];
        }
        cout<<solve(v)<<"\n";
    }
}
