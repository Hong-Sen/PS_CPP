#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int arr[26] = {0,};
    for(int i=0; i<s.length(); i++){
        int x = s.at(i) - 97;
        arr[x]++;
    }
    for(int i=0; i<26; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
