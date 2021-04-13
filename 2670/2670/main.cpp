#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

vector<double> v;

double findMax(){
    double MAX = 0;
    for(int i=0; i<v.size(); i++){
        double tmp = v[i];
        MAX = max(tmp, MAX);
        for(int j=i+1; j<v.size(); j++){
            tmp *= v[j];
            MAX = max(tmp, MAX);
        }
    }
    return MAX;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        double d;
        cin>>d;
        v.push_back(d);
    }
    printf("%.3lf", findMax());

}
