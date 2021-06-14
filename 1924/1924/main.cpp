#include <iostream>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int day = y;
    for(int i=0; i<x-1; i++){
        day += month[i];
    }

    day = day % 7;
    switch (day) {
        case 1:
            cout<<"MON";
            break;
        case 2:
            cout<<"TUE";
            break;
        case 3:
            cout<<"WED";
            break;
        case 4:
            cout<<"THU";
            break;
        case 5:
            cout<<"FRI";
            break;
        case 6:
            cout<<"SAT";
            break;
        case 0:
            cout<<"SUN";
            break;
            
        default:
            break;
    }
}
