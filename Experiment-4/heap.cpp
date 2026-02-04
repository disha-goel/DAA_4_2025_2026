//UID:24BCS10773

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int heap[MAX];
int heapSize = 0;

void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if(right < heapSize && heap[right] < heap[smallest])
        smallest = right;
    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}
void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}
void insert(int val) {
    if(heapSize == MAX) {
        cout << "Heap Overflow\n";
        return;
    }
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}
//Searching a heap
void search(int val) {
    for(int i = 0; i < heapSize; i++) {
        if(heap[i] == val) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found\n";
}
// Delete any element
void deleteElement(int val) {
    int index = -1;
    for(int i = 0; i < heapSize; i++) {
        if(heap[i] == val) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "Element not found\n";
        return;
    }
    heap[index] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(index);
    heapifyUp(index);
    cout << "Element deleted\n";
}
void display() {
    for(int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}
int main() {
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    display();
    search(3);
    deleteElement(3);
    display();
  
    return 0;
}
