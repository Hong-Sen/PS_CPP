#include <iostream>
using namespace std;

char arr[51][51];
int width,height;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'X'){
                width++;
                break;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[j][i] == 'X'){
                height++;
                break;
            }
        }
    }
    cout<<max(n-width, m-height);
}
