#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VTXS 1002
#define MAX_QUEUE_SIZE 10001
using namespace std;

//Matrix Graph
class AdjMatGraph{
protected:
    int size;
    int vertices[MAX_VTXS]; //정점 정보
    int adj[MAX_VTXS][MAX_VTXS]; // 각 정점의 인접 행렬
public:
    AdjMatGraph( ) { reset(); }
    int getVertex(int i) { return vertices[i]; }
    int  getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val) { adj[i-1][j-1] = val; }
    bool isEmpty()     { return size==0; }
    bool isFull()     { return size>=MAX_VTXS; }
    
    // 그래프 초기화 ==> 공백 상태의 그래프
    void reset() {
        size=0;
        for(int i=0 ; i<MAX_VTXS ; i++ )
        for(int j=0 ; j<MAX_VTXS ; j++ )
        setEdge(i,j,0);
    }
    // 정점 삽입
    void insertVertex(int name ) {
        if( !isFull() ) vertices[size++] = name;
        else printf("Error: 그래프 정점 개수 초과\n");
    }
    // 간선 삽입: 무방향 그래프의 경우임.
    void insertEdge( int u, int v ) {
        setEdge(u,v,1);
        setEdge(v,u,1);
    }
    // 그래프 정보 출력 (화면이나 파일에 출력)
    void display( FILE *fp = stdout) {
        fprintf(fp, "%d\n", size);        // 정점의 개수 출력
        for( int i=0 ; i<size ; i++ ) {        // 각 행의 정보 출력
            fprintf(fp,"%d ", getVertex(i));    // 정점의 이름 출력
            for( int j=0 ; j<size ; j++ )    // 간선 정보 출력
            fprintf(fp, " %3d", getEdge(i,j));
            fprintf(fp,"\n");
        }
    }
};

//List Graph
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

class AdjListGraph {
protected:
    int size;                // 정점의 개수
    int vertices[MAX_VTXS]; // 정점 정보
    Node* adj[MAX_VTXS];     // 각 정점의 인접 리스트
public:
    AdjListGraph() : size(0) { }
    ~AdjListGraph(){ reset(); }
    void reset(void) {
        for( int i=0 ; i<size ; i++ )
        if( adj[i] != NULL ) delete adj[i];
        size = 0;
    }
    void insertVertex( int val ) {      // 정점 삽입 연산
        if( !isFull() ) {
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else printf("Error: 그래프 정점 개수 초과\n");
    }
    
    void insertEdge( int u, int v) {    // 간선 삽입 연산
        if(adj[u] == NULL) {
            adj[u] = new Node (v, adj[u]);
        }
        else if(v < adj[u]->getId()){ //1번째 노드보다 작을 때
            adj[u] = new Node (v, adj[u]);
        }
        else{
            bool flag = false;
            Node* prev = adj[u];
            Node *newNode = new Node(v,NULL);
            for(Node *t=adj[u]; t!=NULL; t=t->getLink()){
                if(v < t->getId()){
                    newNode->setLink(t);
                    prev->setLink(newNode);
                    flag = true;
                    break;
                }
                prev = t;
            }
            if(!flag){
                Node *t = adj[u];
                Node *newNode = new Node(v,NULL);
                while (t->getLink() != NULL) {
                    t = t->getLink();
                }
                t->setLink(newNode);
            }
        }
    }
    void display( ) {
        printf("%d\n", size);                // 정점의 개수 출력
        for( int i=0 ; i<size ; i++ ) {      // 각 행의 정보 출력
            printf("%d ", getVertex(i)+1);         // 정점의 이름 출력
            for( Node *v=adj[i] ; v != NULL ; v=v->getLink() )
            printf(" %d", getVertex(v->getId()) +1 );
            printf("\n");
        }
    }
    Node* adjacent(int v) { return adj[v]; }
    bool isEmpty() { return size ==0; }
    bool isFull()  { return size >= MAX_VTXS; }
    int getVertex( int i ) {return vertices[i]; }
};

//DFS (Matrix)
class SrchAMGraph : public AdjMatGraph
{
protected:
    bool visited[MAX_VTXS];     // 정점의 방문 정보
public:
    void resetVisited() {     // 모든 정점을 방문하지 않았다고 초기화
        for( int i=0 ; i<size ; i++ )
        visited[i] = false;
    }
    bool isLinked(int u, int v) { return getEdge(u,v) != 0; }
    
    // 깊이 우선 탐색 함수
    void DFS( int v) {
        visited[v] = true;             // 현재 정점을 방문함
        printf("%d ", getVertex(v)+1);      // 정점의 이름 출력
        
        for( int w=0 ; w<size ; w++) {
            if( isLinked(v,w) && visited[w]==false ) {
                DFS( w ); // 연결 + 방문X => 순환호출
            }
        }
    }
};

//BFS
class CircularQueue{
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
        if (isFull())
        {
            printf("Queue is Full\n");
            system("pause");
        }
        else//mod 연산 사용
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    
    
    int dequeue()
    {
        if (isEmpty())
        {
            printf("Queue is Empty\n");
            system("wait");
            exit(1);
        }
        else
            //mod 연산 사용
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    
    int peek(){
        if(isEmpty()){
            printf("Queue is Empty\n");
            system("wait");
            exit(1);
        }
        else
            return data[(front + 1) % MAX_QUEUE_SIZE];
        
    }
    
    void display(){
        printf("큐 내용: ");
        int maxi = (front<rear) ? rear:rear+MAX_QUEUE_SIZE;
        for(int i=front+1; i<=maxi; i++)
        printf("[%2d]", data[i%MAX_QUEUE_SIZE]);
        printf("\n");
    }
    
};

class SrchALGraph : public AdjListGraph
{
    bool visited[MAX_VTXS];
public:
    void resetVisited()
    {
        for (int i=0; i<size; i++)
        visited[i] = false;
    }
    
    bool isLinked(int u, int v)
    {
        for ( Node *p = adj[u]; p!=NULL; p=p->getLink())
        if (p->getId() == v) return true;
        return false;
    }
    void BFS(int v) {
        visited[v] = true; // 현재 정점을 방문함
        printf("%d ", getVertex(v)+1); // 정점의 이름 출력
        
        CircularQueue que;
        que.enqueue(v); // 시작 정점을 큐에 저장
        while (!que.isEmpty()) {
            int v = que.dequeue();
            for (Node* w = adj[v]; w != NULL; w = w->getLink() )
            {
                int id = w->getId();
                if (!visited[id]) {
                    visited[id] = true;
                    printf("%d ", getVertex(id)+1);
                    que.enqueue(id);
                }
            }
        }
    }
};

int main()
{
    int n,m,v,a,b;
    SrchAMGraph g1;
    SrchALGraph g2;
    
    cin>>n>>m>>v;
    //정점 삽입
    for(int i=0; i<n; i++){
        g1.insertVertex(i);
        g2.insertVertex(i);
    }
    //간선 삽입
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g1.insertEdge(a, b);
        g2.insertEdge(a-1, b-1);
        g2.insertEdge(b-1, a-1);
    }
    
    g1.resetVisited();
    g1.DFS(v-1);
    cout<<"\n";
    g2.resetVisited();
    g2.BFS(v-1);
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//vector<int> adj[10000];
//bool visited[1000];
//
//void dfs(int start){
//    visited[start] = true;
//    cout<<start<<" ";
//    for(int i=0; i<adj[start].size(); i++){
//        int next = adj[start][i];
//        if(!visited[next])  dfs(next);
//    }
//}
//
//void bfs(int start){
//    queue<int> q;
//    q.push(start);
//    visited[start] = true;
//
//    while(!q.empty()){
//        int tmp = q.front();
//        cout<<tmp<<" ";
//        q.pop();
//        for(int i=0; i<adj[tmp].size(); i++){
//            if(!visited[adj[tmp][i]]){
//                q.push(adj[tmp][i]);
//                visited[adj[tmp][i]] = true;
//            }
//        }
//    }
//}
//
//int main(){
//    int n,m,start;
//    cin>>n>>m>>start;
//    for(int i=0; i<m; i++){
//        int v,u;
//        cin>>v>>u;
//        adj[v].push_back(u);
//        adj[u].push_back(v);
//    }
//    for(int i=0; i<n; i++){
//        sort(adj[i].begin(), adj[i].end());
//    }
//    dfs(start);
//    cout<<"\n";
//    for(int i=0; i<=n; i++){
//        visited[i] = false;
//    }
//    bfs(start);
//}
