#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int result[1000001];
stack<int> s;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        result[i] = -1;
    }
    
    for(int i=0; i<n; i++){
        while(!s.empty()){
            if(arr[s.top()] < arr[i]){
                result[s.top()] = arr[i];
                s.pop();
            }
            else    break;
        }
        s.push(i);
    }
      
    
    for(int i=0; i<n; i++){
        cout<<result[i]<<" ";
    }
}
