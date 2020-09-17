#ifndef HeapNode_h
#define HeapNode_h
#include <stdio.h>

class HeapNode {
    int key;
public:
    HeapNode(int k = 0) : key(k) { }
    void setKey(int k) { key = k; }
    int getKey() { return key; }
    void display() { printf("%4d", key); }
};
#endif

//#include "HeapNode.h"
//#include <stdio.h>
#define MAX_ELEMENT 100001
class MinHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MinHeap() : size(0) { }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT - 1; }
    
    HeapNode& getParent(int i) { return node[i / 2]; }
    HeapNode& getLeft(int i) { return node[i * 2]; }
    HeapNode& getRight(int i) { return node[i * 2 + 1]; }
    
    void insert(int key) {
        if (isFull())
            return;
        int i = ++size;
        while (i != 1 && key < getParent(i).getKey())
        {
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setKey(key);
    }
    
    HeapNode remove() {
        if (isEmpty())
            return NULL;
        HeapNode item = node[1];
        HeapNode last = node[size--];
        
        int parent = 1;
        int child = 2;
        while (child <= size) {
            if (child<size && getLeft(parent).getKey() > getRight(parent).getKey())
                child++; //오른쪽 노드가 더 작으면 오른쪽 노드로 이동(최소힙이니까 더 작은 자식노드로 이동)
            if (last.getKey() <= node[child].getKey())
                break;
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return item;
    }
    
    HeapNode find(){
        return node[1];
    }
    
};

//#include "MinHeap.cpp"
int main(){
    int n;
    scanf("%d", &n);
    
    MinHeap heap;
    
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        if(x!=0)
            heap.insert(x);
        else{
            if(!heap.isEmpty()){
                printf("%d\n", heap.remove().getKey());
            }
            else{
                printf("0\n");
            }
            
        }
    }
}
