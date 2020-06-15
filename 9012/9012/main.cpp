#include <iostream>
#include <stack>
using namespace std;

bool check(string c){
    stack<char> stack;
    
    for(int i=0;i<c.length();i++){
        if(c.at(i)=='('){
            stack.push(c.at(i));
        }
        else if(c.at(i)==')'){
            if(!stack.empty())
            stack.pop();
            else
                return false;
        }
    }

        if(stack.empty())
            return true;
        else
            return false;
    
    while(!stack.empty())
        stack.pop();
}

int main(){
    
    int T;
    cin>>T;
    
    string c;
    for(int i=0;i<T;i++){
        cin>>c;
        check(c);
        if(check(c))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
}
