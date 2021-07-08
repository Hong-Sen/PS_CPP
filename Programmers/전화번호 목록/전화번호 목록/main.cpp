#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
 
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    int n = phone_book.size();
    for(int i=0; i<n-1; i++){
            if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].size())){
                return false;
            }
    }
    return true;
}


int main(){
    vector<string> v;
    v.push_back("12");
//    v.push_back("123");
//    v.push_back("1235");
    v.push_back("567");
    v.push_back("88");
    cout<<solution(v);
}
