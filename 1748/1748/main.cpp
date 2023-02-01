//
//  main.cpp
//  1748
//
//  Created by 홍세은 on 2023/02/01.
//

#include <iostream>
#include <cmath>
using namespace std;

int N;
long long result;

int main() {
    cin>>N;
    int NSize = to_string(N).size() - 1;
    int idx = 0;
    while (pow(10, idx+1) <= N) {
        result += 9 * pow(10, idx) * (idx+1);
        idx++;
    }
    result += (NSize + 1) * (N - pow(10, NSize) + 1);
    cout<<result<<"\n";
}
