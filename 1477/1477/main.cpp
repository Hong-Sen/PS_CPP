#ifndef HeapNode_h
#define HeapNode_h

#include <iostream>
#include <cmath>
using namespace std;

class HeapNode{
    double key;
    int cnt;
public:
    HeapNode(double k=0) : key(k) { }
    void setKey(double k) {key = k;}
    double getKey() {return key;}
    void display() {cout<<key;}
    void setCnt(int cnt) {this->cnt = cnt;}
    int getCnt() {return cnt;}
};

#endif


#define MAX_ELEMENT 101
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
    
    void insert(double key, int cnt) {
        if(isFull())
            return;
        int i= ++size;
        
        while(i!=1 && key>getParent(i).getKey())
        {
            node[i] = getParent(i);
            i/=2;
        }
        node[i].setKey(key);
        node[i].setCnt(cnt);
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

void heapSort(int a[], int n){
    MaxHeap h;
    for(int i=0;i<n;i++)
    h.insert(a[i],1);
    
    for(int i=n-1;i>=0;i--)
    a[i] = h.remove().getKey();
}





int sa[101];
MaxHeap mh;

int main(){
    int n,m,l;
    cin>>n>>m>>l;
    for(int i=1;i<n+1;i++){
        cin>>sa[i];
    }
    sa[n+1] = l;
    heapSort(sa, n+2);
    
    for(int i=1;i<n+2;i++){
        mh.insert(sa[i]-sa[i-1],1);
    }
    
    while(m > 0){
        int cnt = mh.find().getCnt() + 1;
        double distance = mh.find().getKey() * mh.find().getCnt() / cnt;
        mh.remove();
        mh.insert(distance, cnt);
        m--;
    }

    cout<<ceil(mh.find().getKey())<<"\n";
    return 0;
}

