#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s){
    if(s.length() % 2 == 0){
        string temp1 = s;
        string temp2 = s;
        int center = temp1.length()/2;
        string left = temp1.erase(center,center);
        string right = temp2.erase(0,center);
        reverse(right.begin(), right.end());
        if(left != right)   return false;
    }
    else{
        string temp1 = s;
        string temp2 = s;
        int center = temp1.length()/2;
        string left = temp1.erase(center,center+1);
        string right = temp2.erase(0, center+1);
        reverse(right.begin(), right.end());
        if(left != right)  return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    if(!isPalindrome(s)){
        cout<<s.length();
    }
    else{
        if(!isPalindrome(s.erase(s.length()-1)))    cout<<s.length();
        else    cout<<-1;
    }
}
