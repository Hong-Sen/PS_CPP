//
//  main.cpp
//  6064
//
//  Created by 홍세은 on 2023/01/30.
//

#include <iostream>
using namespace std;

int tc, M, N, x, y;

int main() {
    cin>>tc;
    while (tc--) {
        cin>>M>>N>>x>>y;
        int idx = 0;
        while (1) {
            long long year = N * idx + y;
            if(year > N * M) {
                cout<<"-1\n";
                break;
            }
            if((year % M == x) || (year % M == 0 && M == x)) {
                cout<<year<<"\n";
                break;
            }
            idx++;
        }
    }
}
