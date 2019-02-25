#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 2500

int matrix[MAXSIZE][MAXSIZE];
int distancia[MAXSIZE];
int ant[MAXSIZE];
int process[MAXSIZE];
int v, a, t;

struct node{ int value; node *next, *previous; };
struct SetQueue{ node *head; node *back; int size; };

SetQueue *CreateQueue(){
	SetQueue *newpointer = (SetQueue *) malloc(sizeof(SetQueue));
	newpointer->head = NULL;
	newpointer->back = NULL;
	newpointer->size = 0;
	return newpointer;
}

void enqueueQ(SetQueue *fila, int x){
	node *newpointer = (node *) malloc(sizeof(node));
	newpointer->value = x;

	if(fila->head == NULL){
		newpointer->next == NULL;
		newpointer->previous = NULL;
		fila->head = newpointer;
		fila->back = newpointer;
	}
	else{
		newpointer->next = NULL;
		newpointer->previous = fila->back;
		fila->back->next = newpointer;
		fila->back = newpointer;
	}

	fila->size ++;
}

int getQ(SetQueue *fila){ return fila->head->value; }

void dequeueQ(SetQueue *fila){
	node *current;

	if(fila->back == fila->head){
		current == fila->head;
		fila->head = NULL;
		fila->back = NULL;
		free(current);
	}
	else{
		current = fila->head;
		fila->head = current->next;
		fila->head->previous = NULL;
		free(current);
	}

	fila->size --;
}

int sizeQ(SetQueue *fila){ return fila->size; }

void printQueue(SetQueue *fila){
	node *current = fila->head;
	cout << endl;
	
	while(current != NULL){
		cout << current->value << endl;
		current = current->next;
	}
}

// ^^ ---------- QUEUE ---------- ^^ 
// vv ---------- GRAPH ---------- vv 

void iniciar(){	for(int i = 0; i < MAXSIZE; i++){ distancia[i] = -1; ant[i] = -1; process[i] = 0; } }

void bfs(int no, int final){

	SetQueue *fila = CreateQueue();
	enqueueQ(fila, no);
	distancia[no] = 0;

	while(true){
		int emp = 0; int next = 0;

		while(sizeQ(fila)){
			next = getQ(fila);
			dequeueQ(fila);

			if(!process[next]){
				process[next] = 1;
				emp = 1;
				break;
			}
		}

		if(!emp) break;
		cout << "Iniciando busca em largura a partir de " << next << endl;
		for(int i = 0; i < v; i++){

			if(matrix[next][i] && !process[i] && distancia[i] < 1){
				distancia[i] = distancia[next] + 1;
				ant[i] = next;
				enqueueQ(fila, i);
			}
		}
	}
}

void ImprimirDist(int x){
	for(int i = 0; i < v; i++){
		cout << i << " | ";
		if(distancia[i] >= 0 && i != x) cout << distancia[i] << " | " << ant[i] << endl;
		else if(i == x) cout << "0 | -\n";
		else cout << "- | -\n";
	}
}

void PrintCaminho(int x, int y){
	if(ant[y] == -1) cout << y;
	else{
		PrintCaminho(x, ant[y]);
		cout << " => " << y;
	}


}

int main(){

	cin >> v >> a >> t;
	int x, y;

	for(int i = 0; i < v + 1; i++) for(int j = 0; j < v + 1; j++) matrix[i][j] = 0;

	for(int i = 0; i < a; i++){
		cin >> x >> y;
		matrix[x][y] = 1;
	}

	cout << "--------";
	for(int i = 1; i <= t; i++){
		iniciar();
		cin >> x >> y;
		cout << "\n\n" << "Caso de Teste #" << i << " - BFS(" << x << ")\n\n";

		bfs(x, y);
		cout << endl;
		ImprimirDist(x);
		cout << endl;

		if(distancia[y] >= 0){
				cout << "Caminho entre " << x << " e " << y << ": ";
				PrintCaminho(x, y);
		}
		else cout << "Sem caminho entre " << x << " e " << y;

		cout << endl << endl;
		cout << "--------";
	}

	


	return 0;
}