#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int arr[51]; //뽑아내고자 하는 수
deque<int> dq;
int cnt;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
        cin>>arr[i];
    
    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }
    
    for(int i=0; i<m; i++){
        deque<int> tmp = dq;
        int index = 0;
        while (!tmp.empty()) {
            if(tmp.front() == arr[i])    break;
            tmp.pop_front();
            index++;
        }
        
        if(index == 0){
            dq.pop_front();
        }
        
        else if(index <= dq.size()/2){
            for(int j=0; j<index; j++){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }
        else{
            for(int j=index; j<dq.size(); j++){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }
    cout<<cnt;
    
}
