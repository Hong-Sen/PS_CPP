#include <iostream>
using namespace std;

int x,y,z;
int result;

int main(){
    cin>>x>>y;
    z = (long double)y/x*100;
    cout<<z<<"   ";
    if(z>=99){
        cout<<"-1";
        return 0;
    }
    int start = 0;
    int end = x;
    
    while (start <= end) {
        int mid = (start+end)/2;
        int tmp = (long double)(y+mid)/(x+mid)*100;
        cout<<mid<<" "<<tmp<<"\n";
        if(tmp > z){
            result = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    cout<<result;
}

