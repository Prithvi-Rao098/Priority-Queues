// all the functions for the min-heap
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "data_structures.h"
#include "main.h"
#include "util.h"

using namespace std;

void MinHeapify(HEAP* pHEAP, int index);
void bubbleSort(int index);


//BuildHeap - essentially Heapify down
void BuildHeap() {
    pHEAP->size = pHEAP->capacity; 
    for (int i = 1; i <= pHEAP->size; ++i) {
        V[i]->pos = i;
        pHEAP->H[i] = i;
    }

    for (int i = pHEAP->size / 2; i >= 1; --i) {
        MinHeapify(pHEAP,i);
    }
}

//Insert 
void Insert(int index) {
    if (index < 1 || index > pHEAP->capacity) {
        cerr << "Error: index out of bound" << endl;
        return; 
    }

    if (V[index]->pos != 0) {
        cerr << "Error: V[" << index << "] already in the heap" << endl;
        return; 
    }

    
    pHEAP->size++;
    pHEAP->H[pHEAP->size] = index;
    V[index]->pos = pHEAP->size;

    bubbleSort(pHEAP->size);

    cout << "Element V[" << index << "] inserted into the heap" << endl;
}


//ExtractMin - delete the root node, replace with last element, heapify-down
void ExtractMin (){
    if (pHEAP == NULL) {
        cerr << "Error: heap is NULL" << endl;
        return;
    }
    
    if (pHEAP->size == 0) {
        cerr << "Error: heap is empty" << endl;
        return;
    }

    V[pHEAP->H[1]]->pos = 0;

    pHEAP->H[1] = pHEAP->H[pHEAP->size];
    V[pHEAP->H[1]]->pos = 1;
    pHEAP->size--;

    MinHeapify(pHEAP, 1);

}
 
//DecreaseKey 
void DecreaseKey(int index, double newKey) {

    if (index < 1 || index > pHEAP->capacity || newKey >= V[index]->key) {
        cerr << "Error: invalid call to DecreaseKey" << endl;
        return;
    }
    if (V[index]->pos == 0) {
        cerr << "Error: V[" << index << "] not in the heap" << endl;
        return;
    }
    V[index]->key = newKey;
    bubbleSort(V[index]->pos);
}


 

void MinHeapify(HEAP* pHEAP, int index) {
    int left = 2 * index; 
    int right = 2 * index + 1; 
    int smallest = index;


    if (left <= pHEAP->size && V[pHEAP->H[left]]->key < V[pHEAP->H[smallest]]->key) {
        smallest = left;
    }


    if (right <= pHEAP->size && V[pHEAP->H[right]]->key < V[pHEAP->H[smallest]]->key) {
        smallest = right;
    }


    if (smallest != index) {
        
        swap(pHEAP->H[index], pHEAP->H[smallest]);

        V[pHEAP->H[index]]->pos = index;
        V[pHEAP->H[smallest]]->pos = smallest;

        MinHeapify(pHEAP, smallest);
    }
}


void bubbleSort(int index){
    while (index > 1 && V[pHEAP->H[index]]->key < V[pHEAP->H[index / 2]]->key) {
        int parentIndex = index / 2;
        swap(pHEAP->H[index], pHEAP->H[parentIndex]);
        V[pHEAP->H[index]]->pos = index;
        V[pHEAP->H[parentIndex]]->pos = parentIndex;
        index = parentIndex;
    }
}

