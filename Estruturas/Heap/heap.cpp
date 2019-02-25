#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10000

struct HeapSet {int size; int data[MAX_SIZE]; };

int GP(int i) { return i / 2; }
int GL(int i) { return i * 2; }
int GR(int i) { return (i * 2) + 1; }
bool IsEmpty(HeapSet *heap) { return !heap->size; }

HeapSet* CreateHeap(){
	HeapSet *heap = (HeapSet *) malloc(sizeof(HeapSet));
	heap->size = 0;
	return heap;
}

void enqueue(HeapSet *heap, int value){
	heap->size ++;
	heap->data[heap->size] = value;

	int keyID = heap->size;
	int parentID = GP(heap->size);

	while(parentID >= 1 && heap->data[keyID] > heap->data[parentID]){
		int aux = heap->data[keyID];
		heap->data[keyID] = heap->data[parentID];
		heap->data[parentID] = aux;

		keyID = parentID;
		parentID = GP(keyID);
	}
}

void MaxHeapfy(HeapSet *heap, int i){
	int largest;
	int leftID = GL(i); int rightID = GR(i);

	if(leftID <= heap->size && heap->data[leftID] > heap->data[i]) largest = leftID;
	else largest = i;

	if(rightID <= heap->size && heap->data[rightID] > heap->data[largest]) largest = rightID;

	if(heap->data[i] != heap->data[largest]){
		int aux = heap->data[i];
		heap->data[i] = heap->data[largest];
		heap->data[largest] = aux;

		MaxHeapfy(heap, largest);
	}
}

void dequeue(HeapSet *heap){
	if(IsEmpty(heap)) return;

	heap->data[1] = heap->data[heap->size];
	heap->size --;
	MaxHeapfy(heap, 1);
}

int peek(HeapSet *heap) { return heap->data[1]; }

void maxheap(HeapSet *heap){
	int l = heap->size;
	for(int i = l/2; i >= 1; i--) MaxHeapfy(heap, i);
}


void heapsort(HeapSet *heap){
	for(int i = heap->size; i >= 2; i--){
		int aux = heap->data[1];
		heap->data[1] = heap->data[i];
		heap->data[i] = aux;

		heap->size--;

		MaxHeapfy(heap, 1);
		printarHeap(heap);
	}
}

int main(){
	HeapSet *heap = CreateHeap();
	int x, count = 0;	
	while(cin >> x) heap->data[++heap->size] = x;
	maxheap(heap);
	heapsort(heap);
	return 0;
}