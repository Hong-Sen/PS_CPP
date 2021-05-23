#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int d,h,w;
    cin>>d>>h>>w;
    cout<< (int)(h*(d / sqrt(pow(h, 2) + pow(w, 2)))) <<" "<<(int)(w *(d / sqrt(pow(h, 2) + pow(w, 2))));
}
