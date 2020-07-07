#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    int temp;
    int N;
    cin>>N;
    
    for(int i=N;i>0;i--){
        dq.push_front(i);
    }
    
    while (1) {
        if(dq.size()==1){
            cout<<dq[0]<<"\n";
            break;
        }
        
        dq.pop_front();
        temp = dq[0];
        dq.pop_front();
        dq.push_back(temp);
        
    }
}
