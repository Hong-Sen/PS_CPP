//
//  main.cpp
//  1269
//
//  Created by 홍세은 on 2022/11/04.
//

#include <iostream>
#include <map>
using namespace std;

int aSize, bSize;
map<int,int> m;

int main(){
    cin>>aSize>>bSize;
    int num;
    for(int i=0; i<aSize+bSize; i++) {
        cin>>num;
        m.insert({num,0});
    }
    cout<<m.size() * 2 - aSize - bSize;
}
