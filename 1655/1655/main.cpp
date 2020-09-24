#ifndef HeapNode_h
#define HeapNode_h

#include <stdio.h>

class HeapNode{
    int key;
    
public:
    HeapNode(int k=0) : key(k) { }
    void setKey(int k) {key = k;}
    int getKey() {return key;}
    void display() {printf("%d"), key;}
};

#endif


#define MAX_ELEMENT 100001
#include <stdio.h>

class MaxHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MaxHeap() : size(0) { }
    bool isEmpty() {return size == 0;}
    bool isFull() {return size ==MAX_ELEMENT -1;}
    
    HeapNode& getParent(int i){return node[i/2];}
    HeapNode& getLeft(int i){return node[i*2];}
    HeapNode& getRight(int i){return node[i*2+1];}
    int getSize() {return size;}
    
    void insert(int key) {
        if(isFull())
            return;
        int i= ++size;
        
        while(i!=1 && key>getParent(i).getKey())
        {
            node[i] = getParent(i);
            i/=2;
        }
        node[i].setKey(key);
    }
    
    HeapNode remove() {
        if(isEmpty())
            return NULL;
        HeapNode item = node[1];
        HeapNode last = node[size--];
        int parent = 1;
        int child = 2;
        while(child<=size){
            if(child<size && getLeft(parent).getKey() < getRight(parent).getKey())
                child++;
            
            if(last.getKey() >= node[child].getKey())
                break;
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return item;
    }
    HeapNode find() {return node[1];}
    
};

class MinHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MinHeap() : size(0) { }
    bool isEmpty() {return size == 0;}
    bool isFull() {return size == MAX_ELEMENT -1;}
    
    HeapNode& getParent(int i){return node[i/2];}
    HeapNode& getLeft(int i){return node[i*2];}
    HeapNode& getRight(int i){return node[i*2+1];}
    int getSize() {return size;}
    
    void insert(int key){
        if(isFull())
            return;
        int i = ++size;
        while(i!=1 && key<getParent(i).getKey())
        {
            node[i] = getParent(i);
            i/=2;
        }
        node[i].setKey(key);
    }
    
    HeapNode remove(){
        if(isEmpty())
            return NULL;
        HeapNode item = node[1];
        HeapNode last = node[size--];
        
        int parent = 1;
        int child = 2;
        while(child<=size){
            if(child<size && getLeft(parent).getKey() > getRight(parent).getKey())
                child++; //오른쪽 노드가 더 작으면 오른쪽 노드로 이동(최소힙이니까 더 작은 자식노드로 이동)
            if(last.getKey()<=node[child].getKey())
                break;
            node[parent] = node[child];
            parent = child;
            child*=2;
        }
        node[parent] = last;
        return item;
    }
    
    HeapNode find() {return node[1];}
    
};


//중간값구하기 알고리즘
//1. 최대힙의크기 >= 최소힙의크기
//2. 최대힙의 최대원소 <= 최소힙의 최소원소
//두조건이 맞지 않다면 최대힙 루트 swap 최소힙 루트
//최대힙 루트 값 = 중간값

MaxHeap maxHeap;
MinHeap minHeap;

void Swap(){
    int maxTemp = maxHeap.find().getKey();
    int minTemp = minHeap.find().getKey();
    maxHeap.remove();
    minHeap.remove();
    maxHeap.insert(minTemp);
    minHeap.insert(maxTemp);
}

int main(){
    int n,x;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        if(i == 0)
        {
            maxHeap.insert(x);
            printf("%d\n", maxHeap.find().getKey());
            continue;
        }
        
        if(maxHeap.getSize() == minHeap.getSize()){
            maxHeap.insert(x);
        }
        else{
            minHeap.insert(x);
        }
        
        if(maxHeap.find().getKey() > minHeap.find().getKey()){
            Swap();
        }
        
        
        printf("%d\n", maxHeap.find().getKey());
        
    }
    
    
}


