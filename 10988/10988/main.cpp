#include <iostream>
#include <string>
using namespace std;

bool isPalindrom(string s){
    int left = 0;
    int right = s.length()-1;
    while (left < right) {
        if(s.at(left) == s.at(right)){
            left++;
            right--;
        }
        else    return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<isPalindrom(s);
}
