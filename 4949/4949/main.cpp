#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    while (1) {
        
        getline(cin,s); //공백(띄어쓰기)을 포함해서 한 문자열로 입력받는 방법
        if(s==".")
            break;
        int flag=0;
        stack<char>stack;
           
           for(int i=0;i<s.length();i++){
               if(s[i]=='('||s[i]=='['){
                   stack.push(s.at(i));
               }
               else if(s[i]==')'){
                   if(stack.empty()||stack.top()!='('){
                       flag = 1;
                                             break;
                   }
                   else{
                      stack.pop();
                   }
                      
               }
               else if(s[i]==']'){
                   if(stack.empty()||stack.top()!='['){
                       flag = 1;
                       break;
                   }
                   else{
                       stack.pop();
                   }
                       
               }
           }
        
        
        
        if((flag == 0)&&(stack.empty()))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        

    }
    return 0;
}
