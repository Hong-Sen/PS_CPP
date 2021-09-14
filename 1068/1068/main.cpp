#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
int n, root;
int removeNode;
int x;
int cnt;

//리프 노드 탐색
void findLeaf(int node){
    int nodeSize = tree[node].size();
    if(nodeSize == 0){
        cnt++;
        return;
    }
    for(int i=0; i<nodeSize; i++){
        findLeaf(tree[node][i]);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x == -1) root = i;
        else tree[x].push_back(i);
    }
    cin>>removeNode;
    if(removeNode == root){
        cout<<0;
        return 0;
    }
    //removeNode의 루트 탐색후 removeNode 지워주기
    for(int i=0; i<n; i++){
        for(int j=0; j<tree[i].size(); j++){
            if(tree[i][j] == removeNode){
                tree[i].erase(tree[i].begin()+j);
                break;
            }
        }
    }
    findLeaf(root);
    cout<<cnt;
}
