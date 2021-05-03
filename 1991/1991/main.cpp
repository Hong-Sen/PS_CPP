#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[27][2];

void preorder(int k){
    cout<<(char)(k+65);
    for(int i=0; i<2; i++){
        int next = arr[k][i];
        if(next != 32){
            preorder(next);
        }
    }
}

void inorder(int k){
    int nextL = arr[k][0];
    if(nextL != 32){
        inorder(nextL);
    }
    cout<<(char)(k+65);
    int nextR = arr[k][1];
    if(nextR != 32){
        inorder(nextR);
    }
}

void postorder(int k){
    int nextL = arr[k][0];
    if(nextL != 32){
        postorder(nextL);
    }
    int nextR = arr[k][1];
    if(nextR != 32){
        postorder(nextR);
    }
    cout<<(char)(k+65);
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        char a,b,c;
        cin>>a>>b>>c;
        if(b == '.')    b = 'a';
        if(c == '.')    c = 'a';
        arr[a-65][0] = b-65;
        arr[a-65][1] = c-65;
    }
    preorder(0);
    cout<<"\n";
    inorder(0);
    cout<<"\n";
    postorder(0);
    cout<<"\n";
}
