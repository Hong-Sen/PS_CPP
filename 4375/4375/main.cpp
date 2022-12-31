//
//  main.cpp
//  4375
//
//  Created by 홍세은 on 2022/12/31.
//

#include <iostream>
using namespace std;

int n;

int main(){
    while (cin>>n) { // 입력 개수가 정해지지 않았을 경우
        int idx = 0;
        int result = 0;
        while(1) {
            result = result * 10 + 1;
            idx++;
            result %= n; // !!
            if(result == 0) {
                cout<<idx<<"\n";
                break;
            }
        }
    }
}
