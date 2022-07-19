//
//  main.cpp
//  20055
//
//  Created by 홍세은 on 2022/07/19.
//

#include <iostream>
#include <deque>
using namespace std;

int N,K;
int turn;
int zeroCnt;
deque<int> belt;
deque<bool> roboat;

void rotate() {
    roboat.push_front(roboat.back());
    roboat.pop_back();
    roboat[N-1] = false;
    
    belt.push_front(belt.back());
    belt.pop_back();
}

void move() {
    for(int i=N-2; i>=0; i--) {
        if(roboat[i] && !roboat[i+1] && belt[i+1] > 0) {
            roboat[i] = false;
            roboat[i+1] = true;
            belt[i+1]--;
            
            if(belt[i+1] == 0) zeroCnt++;
        }
        roboat[N-1] = false;
    }
}

int main(){
    cin>>N>>K;
    int n;
    for(int i=1; i<=N*2; i++) {
        cin>>n;
        belt.push_back(n);
        roboat.push_back(false);
    }
    
    while (true) {
        turn++;
        rotate();
        move();
        
        if(!roboat[0] && belt[0] > 0) {
            roboat[0] = true;
            belt[0]--;
            if(belt[0] == 0) zeroCnt++;
        }
        if(zeroCnt >= K) break;
    }
    
    cout<<turn;
}
