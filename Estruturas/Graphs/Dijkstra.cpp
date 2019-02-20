#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10000

struct HeapNode { int first, second; };
struct HeapSet {int size; HeapNode data[MAX_SIZE]; };

int *distancia = (int *) malloc(sizeof(int) * MAX_SIZE);
int *processado = (int *) malloc(sizeof(int) * MAX_SIZE);

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

// ^ --------- HEAP ---------- ^
// v --------- LIST ---------- v

struct nodeV {int first, second; nodeV *next, *previous; };
struct SetList { nodeV *back, *head; };

void SETAR(int n, SetList *vizinhos){
	 for(int i = 0; i <= n + 5; i++){ distancia[i] = INT_MAX; processado[i] = 0; }
	 for(int i = 0; i < n + 3; i++) { vizinhos[i].head = NULL; vizinhos[i].back = NULL; }
}

nodeV *GetItem(SetList *lista) { return lista->head; }

void PushItem(SetList *lista, int first, int second){
	nodeV *newPointer = (nodeV *) malloc(sizeof(nodeV));
	newPointer->first = first; newPointer->second = second;

	if(lista->head == NULL){
		lista->head = newPointer;
		lista->back = newPointer;
		newPointer->next = newPointer->previous = NULL;
	}
	else{
		newPointer->next = NULL;
		newPointer->previous = lista->back;
		lista->back->next = newPointer;
		lista->back = newPointer;
	}
}

void dijkstra(SetList *vizinhos, int x){
	distancia[x] = 0;

	HeapSet *fila = CreateHeap();
	enqueue(fila, distancia[x], x);

	while(true){
		int davez = -1;

		while(!IsEmpty(fila)){
			int atual = (peek(fila)).second;
			dequeue(fila);
			davez = atual;
		}

		if(davez == -1) return;

		nodeV *currrent = vizinhos[davez].head;

		while(currrent != NULL){
			int dist = currrent->first;
			int atual = currrent->second;

			if( distancia[atual] > distancia[davez] + dist ){
				distancia[atual] = distancia[davez] + dist;
				enqueue(fila, distancia[atual], atual);
			}

			currrent = currrent->next;
		}
	}
}

int PrintList(SetList *lista){
	nodeV *currrent = lista->head;
	if(lista->head == NULL || lista->back == NULL) return 0;

	while(currrent != NULL){
		cout << currrent->first << " | " << currrent->second << endl;
		currrent = currrent->next;
	}

	return 1;
}

int main(){

	int n, m, u, v, d;
	cin >> n >> m;
	SetList vizinhos[n + 5];
	SETAR(n, vizinhos);

	for(int i = 0; i < m; i++){
		cin >> u >> v >> d;
		PushItem( &vizinhos[u], d, v);
		PushItem( &vizinhos[v], d, u);
	}

	dijkstra(vizinhos, 1);
	cout << distancia[n] << endl;

	cout << "ok";

	return 0;
}