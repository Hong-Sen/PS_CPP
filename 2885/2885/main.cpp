//
//  main.cpp
//  2885
//
//  Created by 홍세은 on 2022/04/29.
//

#include <iostream>
using namespace std;

int k, len, cnt;

int main(){
    cin>>k;
    int chocolate = 1;
    while (1) {
        if(chocolate >= k) break;
        chocolate *= 2;
    }
    len = chocolate;
    while (k>0) {
        if(k >= chocolate) k -= chocolate;
        else {
            chocolate /= 2;
            cnt++;
        }
    }
    
    cout<<len<<" "<<cnt;
}
