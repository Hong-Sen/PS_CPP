//
//  main.cpp
//  2885
//
//  Created by 홍세은 on 2022/04/29.
//

#include <iostream>
using namespace std;

int k, cnt;
int s = 1;

int main() {
    cin>>k;
    
    while (s<k) {
        s *= 2;
    }
    cout<<s<<" ";
    while (k!=s) {
        cnt++;
        s /= 2;
        if (s == k)break;
        if (k > s)k -= s;
    }
    cout<<cnt;
}
