#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value, p;
	node *next, *previous;
};

struct PriorityQueue
{
	node *head, *back;
	int min, max, size;
};

int InsertItem(PriorityQueue *pq, int item, int p){

	node *newPointer = (node *) malloc(sizeof(node));
	if(newPointer == NULL) return 0;

	newPointer->value = item; newPointer->p = p;

	if(pq->head == NULL){
		pq->head = newPointer;
		pq->back = newPointer;
		newPointer->next = NULL;
		newPointer->previous = NULL;
		pq->max = pq->min = p;
	}
	else if(newPointer->p >= pq->max){
			newPointer->next = NULL;
			newPointer->previous = pq->back;
			newPointer->previous->next = newPointer;
			pq->back = newPointer;
			pq->max = p;
	}
	else if(newPointer->p <= pq->min){
			newPointer->previous = NULL;
			newPointer->next = pq->head;
			newPointer->next->previous = newPointer;
			pq->head = newPointer;
			pq->min = p;
	}
	else{
		node *current = pq->head;
		while(current->p < newPointer->p){
			current = current->next;
		}

		newPointer->previous = current->previous;
		newPointer->previous->next = newPointer;
		newPointer->next = current;
		current->previous = newPointer;
	}

	return 1;
}



int menu(PriorityQueue *pq){

	int command, x, p;
	cout << "1 - Push item.\n2 - Get item\n3 - Remove item\n4 - Current Priority.\n5 - Print Queue\n6 - Size.\n0 - Exit\n";
	cout << "Command: "; cin >> command;

	if(command == 0) return 0;
	else if(command == 1){
		cout << "Item: "; cin >> x;
		cout << "Priority: "; cin >> p;
		if( InsertItem(pq, x, p) ) cout << "Sucess.\n\n";
		else cout << "No memory.\n\n";
	}
	else if(command == 2);
	else if(command == 3);
	else if(command == 4);
	else if(command == 5);
	else if(command == 6);
	else cout << "Invalid Command.\n\n";

	return 1;

}

int main(){

	PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
	pq->head = NULL; pq->back = NULL;
	pq->min = INT_MAX; pq->max = INT_MIN;

	while(menu(pq));

	return 0;
}