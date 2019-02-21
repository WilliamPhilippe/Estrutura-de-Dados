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

void printarHeap(HeapSet *heap){
	cout << "Estado Atual da Heap: " << heap->data[1];
	for(int i = 2; i <= heap->size; i++) cout << " | " << heap->data[i];
	if(heap->size > 1) cout << "\nMaior elemento neste passo: " << heap->data[1];
	cout << endl;
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
	int start[10000];
	while(cin >> x) start[count++] = x, enqueue(heap, x);

	cout << "Estado inicial: " << start[0];
	for(int i = 1; i < count; i++) cout << " | " << start[i];
	cout << endl;
	printarHeap(heap);
	heapsort(heap);

	cout << "Resultado Final: " << heap->data[1];
	for(int i = 2; i <= count; i++) cout << " | " << heap->data[i];



	return 0;
}