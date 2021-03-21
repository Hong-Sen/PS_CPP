#include <iostream>
#include <stdio.h>
#define MAX 10000001
using namespace std;

bool arr[2*MAX];

int main(){
    int n,m,x;
    scanf("%d", &n);;
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        arr[x + MAX] = true;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &x);
        printf("%d ", arr[x + MAX]);
    }
}


//#include <iostream>
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n,m;
//vector<int> v;
//
//int main(){
//    scanf("%d", &n);
//    for(int i=0; i<n; i++){
//        int x;
//        scanf("%d", &x);
//        v.push_back(x);
//    }
//    sort(v.begin(), v.end());
//
//    scanf("%d", &m);
//    for(int i=0; i<m; i++){
//        int x;
//        scanf("%d", &x);
//        int s = 0;
//        int e = n-1;
//        int mid;
//        bool flag = false;
//        while(s <= e){
//            mid = (s+e)/2;
//            if(x == v[mid]){
//                flag = true;
//                break;
//            }
//            else if(x > v[mid]){
//                s = mid + 1;
//            }
//            else {
//                e = mid - 1;
//            }
//        }
//        if(flag)    cout<<"1 ";
//        else        cout<<"0 ";
//
//
//    }
//
//}
