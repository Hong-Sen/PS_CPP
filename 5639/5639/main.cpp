#include <iostream>
#include <vector>
using namespace std;

int cnt;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* root;

void insert(int n){
    Node* newNode = new Node[1];
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    if(cnt == 0)    root = newNode;
    else{
        Node* tmp = root;
        while (1) {
            if(tmp->data < n){
                if(tmp->right == NULL){
                    tmp->right = newNode;
                    break;
                }
                tmp = tmp->right;
            }
            else{
                if(tmp->left == NULL){
                    tmp->left = newNode;
                    break;
                }
                tmp = tmp->left;
            }
        }
    }
    cnt++;
    return;
}

void postorder(Node* tmp){
    if(tmp != NULL){
        postorder(tmp->left);
        postorder(tmp->right);
        cout<<tmp->data<<"\n";
    }
}


int main(){
    int n;
    while (cin>>n) {
        insert(n);
    }
    postorder(root);
}
