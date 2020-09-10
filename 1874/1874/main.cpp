#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> v;
    vector<int> pv; //pop vector
    vector<char> result;
    stack<int> st;
    st.push(0);
    int num = 1;
    
    cin>>n;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        v.push_back(input);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<pv.size();j++){
            if(v[i]==pv[j]){
                cout<<"NO\n";
                return 0;
            }
        }
        while(1){
            if(v[i] > st.top()){
                st.push(num++);
                result.push_back('+');
            }
            
            else if(v[i] < st.top()){
                pv.push_back(st.top());
                st.pop();
                result.push_back('-');
            }
            
            else{
                pv.push_back(st.top());
                st.pop();
                result.push_back('-');
                break;
            }
        }
    }
    
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"\n";
    }
}
