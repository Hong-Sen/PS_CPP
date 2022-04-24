//
//  main.cpp
//  1459
//
//  Created by 홍세은 on 2022/04/23.
//

#include <iostream>
#include <cmath>
using namespace std;

long long x,y,w,s;

int main(){
    cin>>x>>y>>w>>s;
    long long way1 = (x + y) * w;
    long long way2 = min(x,y) * s;
    if(abs(x-y) % 2 == 0)
        way2 += min(abs(x - y) * w, abs(x-y) * s);
    else  way2 += min(abs(x - y) * w, (abs(x-y)-1) * s + w);
    cout<<min(way1, way2);
}
