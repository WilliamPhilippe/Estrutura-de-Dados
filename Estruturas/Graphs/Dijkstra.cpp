#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 15000

struct HeapNode { int first, second; };
struct HeapSet {int size; HeapNode data[MAX_SIZE]; };
struct VNode {int first, second; VNode *next, *previous; };
struct SetList { VNode *back, *head; };

int *distancia = (int *) malloc(sizeof(MAX_SIZE));
int *processado = (int *) malloc(sizeof(MAX_SIZE));
SetList vizinhos[MAX_SIZE];

int GP(int i) { return i / 2; }
int GL(int i) { return i * 2; }
int GR(int i) { return (i * 2) + 1; }
bool IsEmpty(HeapSet *heap) { return !heap->size; }

HeapSet* CreateHeap(){
	HeapSet *heap = (HeapSet *) malloc(sizeof(HeapSet));
	heap->size = 0;
	return heap;
}

void enqueue(HeapSet *heap, int dist, int no){
	heap->size ++;
	heap->data[heap->size].first = dist;
	heap->data[heap->size].second = no;

	int keyID = heap->size;
	int parentID = GP(heap->size);

	while(parentID >= 1 && heap->data[keyID].first > heap->data[parentID].first){
		HeapNode aux = heap->data[keyID];
		heap->data[keyID] = heap->data[parentID];
		heap->data[parentID] = aux;

		keyID = parentID;
		parentID = GP(keyID);
	}
}

void MaxHeapfy(HeapSet *heap, int i){
	int largest;
	int leftID = GL(i); int rightID = GR(i);

	if(leftID <= heap->size && heap->data[leftID].first > heap->data[i].first) largest = leftID;
	else largest = i;

	if(rightID <= heap->size && heap->data[rightID].first > heap->data[largest].first) largest = rightID;

	if(heap->data[i].first != heap->data[largest].first){
		HeapNode aux = heap->data[i];
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

HeapNode peek(HeapSet *heap) { return heap->data[1]; }

void PushItem(SetList *lista, int first, int second){

	VNode *newPointer = (VNode *) malloc(sizeof(VNode));
	newPointer->first = first; newPointer->second = second;

	if(lista->head == NULL){
		lista->head = newPointer;
		lista->back = newPointer;
		newPointer->previous = NULL;
		newPointer->next = NULL;
	}
	else{
		newPointer->next = NULL;
		newPointer->previous = lista->back;
		lista->back->next = newPointer;
		lista->back = newPointer;
	}
}

VNode *GetItem(SetList *lista) { return lista->head; }

void SETAR(int n){
	 for(int i = 0; i <= n + 5; i++){ distancia[i] = INT_MAX; processado[i] = 0; }
	 for(int i = 0; i <= n + 5; i++) { vizinhos[i].head = vizinhos[i].back = NULL; }
}

int main(){

	int n, m, u, v, d;
	cin >> n >> m;
	SETAR(n);

	for(int i = 0; i < m; i++){
		cin >> u >> v >> d;

		PushItem(&vizinhos[u], d, v);
		PushItem(&vizinhos[v], d, u);
	}

	cout << "ok";

	return 0;
}