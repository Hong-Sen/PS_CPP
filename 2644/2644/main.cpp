#include <stdio.h>
#define MAX_VTXS 10000

class Node{
protected:
    int id;
    Node *link;
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
    char vertices[MAX_VTXS]; //정점 정보
    Node* adj[MAX_VTXS]; // 각 정점의 인접 리스트
public:
    AdjListGraph() : size(0) { }
    ~AdjListGraph() {reset();}
    void reset()
    {
        for(int i=0;i<size;i++)
        if(adj[i]!=NULL)
            delete adj[i];
        size = 0;
    }
    bool isEmpty() {return (size==0);}
    bool isFull() {return (size>=MAX_VTXS);}
    char getVertex(int i) {return vertices[i];}
    
    void insertVertex(char val)
    {
        if(!isFull()){
            vertices[size] = val;
            adj[size++] = NULL;
        }
    }
    
    void insertEdge(int u,int v)
    {
        //insert edge(u,v)
        if(adj[u] == NULL)
            adj[u] = new Node(v,NULL);
        else{
            Node* p = adj[u];
            while(p->getLink()!=NULL)
                p=p->getLink();
            p->setLink(new Node(v,NULL));
        }
        //insert(v,u)
        if(adj[v]==NULL)
            adj[v] = new Node(u,NULL);
        else{
            Node* p = adj[v];
            while(p->getLink() != NULL)
                p=p->getLink();
            p->setLink(new Node(u,NULL));
        }
        
    }
    
};

#define MAX_QUEUE_SIZE 10000

class CircularQueue{
    //구현하기 나름이지만, queue와 달리 Circular Queue는 rear, front를 모두 0으로 넣고 시작한다.
    int rear = 0;
    int front = 0;
    int data[MAX_QUEUE_SIZE];
public:
    CircularQueue() {front=rear=0;}
    ~CircularQueue(){ }
    
    bool isEmpty() {return front==rear;}
    bool isFull() {return (rear+1) % MAX_QUEUE_SIZE == front;}
    
    void enqueue(int val)
    {
        
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        data[rear] = val;
        
    }
    
    
    int dequeue()
    {
        front = (front + 1) % MAX_QUEUE_SIZE;
        return data[front];
        
    }
    
    int peek(){
        return data[(front + 1) % MAX_QUEUE_SIZE];
        
    }
    
    
};

class SrchALGraph : public AdjListGraph
{
    bool visited[MAX_VTXS];
public:
    void resetVisited()
    {
        for(int i=0;i<size;i++)
        visited[i] = false;
    }
    
    bool isLinked(int u,int v)
    {
        for(Node* p=adj[u]; p!=NULL; p=p->getLink())
        if(p->getId() == v )
            return true;
        return false;
    }
    
    void BFS(int x, int y)
    {
        visited[x] = true;
        
        CircularQueue que;
        que.enqueue(x);
        int cnt[101] = {0,};
        while(!que.isEmpty()){
            int v = que.peek();
            que.dequeue();
            if(v == y){
                printf("%d\n", cnt[v]);
                return;
            }
            for(Node *w=adj[v]; w!=NULL; w=w->getLink()){
                int id = w->getId();
                if(!visited[id]){
                    visited[id] = true;
                    que.enqueue(id);
                    cnt[id] = cnt[v]+1;
                }
            }
            
        }
        printf("%d\n", -1);
    }
};

int main(){
    int n,x,y,m,u,v;
    SrchALGraph g;
    scanf("%d", &n);
    scanf("%d",&x);
    scanf("%d", &y);
    scanf("%d", &m);
    
    for(int i=0;i<n;i++){
        g.insertVertex('1'+i);
    }
    
    for(int i=0;i<m;i++){
        scanf("%d", &u);
        scanf("%d", &v);
        g.insertEdge(u-1, v-1);
    }
    
    g.BFS(x-1,y-1);
    
}
