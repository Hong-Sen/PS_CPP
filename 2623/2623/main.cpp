#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>
#define MAX_VTXS 10001
using namespace std;
const int MAX_STACK_SIZE = 10001;
//스택의 최대 크기 설정
class ArrayStack {
    int top;                            //요소의 개수
    int data[MAX_STACK_SIZE];            //요소의 배열
public:
    ArrayStack() { top = -1; }            //스택 생성자(ADT의 create()역할)
    ~ArrayStack() {}                    //스택 소멸자
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE-1; }

    void push(int e) {                    //맨 위에 항목 삽입
       
        data[++top] = e;
    }

    int pop() {                            //맨 위의 요소를 삭제하고 반환
        
        return data[top--];
    }

    int peek() {                        //삭제하지 않고 요소 반환
        
        return data[top];
    }

    void display() {                    //스택 내용을 화면에 출력
        printf("[스택 항목 수 = %2d] ==> ", top + 1);
        for (int i = 0; i <= top; i++)
            printf("<2%d>", data[i]);
        printf("\n");
    }
};


class Node{
protected:
    int id; //정점의id
    Node *link; //다음노드의 포인터
public:
    Node(int i,Node *l=NULL) : id(i),link(l){ }
    ~Node() {
        if(link != NULL) delete link;
    }
    int getId() {return id;}
    Node* getLink() {return link;}
    void setLink(Node* l) {link = l;}
};

class AdjListGraph{
protected:
    int size;
    int vertices[MAX_VTXS]; //정점 정보
    Node* adj[MAX_VTXS]; // 각 정점의 인접 리스트
public:
    AdjListGraph() : size(0) { }
    ~AdjListGraph() {reset();}
    void reset()
    {
        size = 0;
        for(int i=0;i<size;i++)
            if(adj[i]!=NULL)
                delete adj[i];
    }
    
    bool isEmpty() {return (size==0);}
    bool isFull() {return (size>=MAX_VTXS);}
    int getVertex(int i) {return vertices[i];}
    
    void insertVertex(int val)
    {
        if(!isFull()){
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else
            printf("Error: 그래프 정점 개수 초과\n");
    }
    
    void insertEdge(int u,int v)
    {
        adj[u] = new Node (v,adj[u]);
        adj[v] = new Node (u,adj[v]); //방향그래프이면 이건 주석처리해야함!
    }
    
    void display()
    {
        printf("%d\n",size);
        for(int i=0; i<size ;i++){
            printf("%d  ", getVertex(i));
            for(Node *v=adj[i]; v!=NULL; v=v->getLink() )
                printf("  %d",getVertex(v->getId()));
            printf("\n");
        }
    }
    Node* adjacent(int v) {return adj[v];}
};

class TopoSortGraph: public AdjListGraph
{
public:
    TopoSortGraph(void){ }
    ~TopoSortGraph(void){ }
    
    void insertDirEdge(int u, int v){
        adj[u] = new Node(v, adj[u]);
    }
    
   vector<int> TopoSort(){
        vector<int> result;
        ArrayStack s;
        int *inDeg = new int[size]; //진입차수
        for(int i=0; i<size; i++)
            inDeg[i] = 0;
        for(int i=0; i<size; i++){
            Node *node = adj[i];
            while(node!=NULL){
                inDeg[node->getId()]++;
                node = node->getLink();
            }
        }
        for(int i=0; i<size; i++)
            if(inDeg[i] == 0) s.push(i); //진입차수가0인 정점 스택에 삽입
        
        while(!s.isEmpty()){
            int w = s.pop();
            result.push_back(getVertex(w));
            Node *node = adj[w];
            while(node!=NULL){
                int u = node->getId();
                inDeg[u]--;
                if(inDeg[u] == 0) s.push(u);
                node = node->getLink();
            }
        }
        if(!s.isEmpty()) result.clear();
        delete [] inDeg;
        return result;
    }
};

int main(){
    int n,m;
    TopoSortGraph g;
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
        g.insertVertex(1 + i);
    
    for(int i=0; i<m; i++){
        int singerSum;
        vector<int> v;
        cin>>singerSum;
        for(int j=0; j<singerSum; j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
       
        for(int l=0; l<v.size()-1; l++){
            for(int k=l+1; k<v.size(); k++)
                g.insertDirEdge(v[l]-1, v[k]-1);
        }
              
    }
    vector<int> finalResult = g.TopoSort();
   
    if(finalResult.size() == n){
        for(int i=0;i<finalResult.size();i++)
            cout<<finalResult[i]<<"\n";
    }
    else
        cout<<"0\n";
}

