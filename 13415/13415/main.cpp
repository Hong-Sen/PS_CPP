#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <deque>
using namespace std;

int arr[100001];
bool desc(int a, int b){
    return a > b;
}

int main(){
    int n,k;
    cin>>n;
    deque<int> dq;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>k;
    
    for(int i=0; i<2*k; i++){
        int in;
        cin>>in;
        if(i==0)    dq.push_back(in);
        else{
            if(i%2==1)    in *= -1;
            while(1){
                if(dq.size() == 0){
                    dq.push_back(in);
                    break;
                }
                else if(abs(dq.back()) > abs(in)){
                    dq.push_back(in);
                    break;
                }
                else{
                    dq.pop_back();
                }
                
            }
            
        }
        
    }
    int start = abs(dq.front());
    sort(arr, arr + start);
    deque<int> order; //start번째 까지 sort된 arr순서
    deque<int> dq2 = dq;
    for(int i=0; i<start; i++){
        order.push_back(arr[i]);
    }
    

    while (dq.size() != 0) {
        if(dq.front() > 0){
            int length = abs(dq2.front());
            dq2.pop_front();
            length -= abs(dq2.front());
            for(int i=0; i<length; i++){
                arr[--start] = order.back();
                order.pop_back();
            }
        }
        else{
            int length = abs(dq2.front());
            dq2.pop_front();
            length -= abs(dq2.front());
            for(int i=0; i<length; i++){
                arr[--start] = order.front();
                order.pop_front();
            }
        }
        dq.pop_front();
    }

    for(int i=0; i<n; i++){
        cout<<arr[i];
        if(i != n-1)    cout<<" ";
        else    cout<<"\n";
    }
}
