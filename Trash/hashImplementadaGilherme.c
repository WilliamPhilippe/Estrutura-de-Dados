#include <stdio.h>
#include <stdlib.h>

#define DEBUG(x, s) if(x)printf("%s\n", s);

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node_t;

typedef struct hash
{
	int size;
    node_t **table;
} ht;

int is_empty(node_t *head)
{
	return head == NULL;
}

void printList(node_t *head)
{
	node_t *current = head;
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
	return;
}

void printHash(ht *hash)
{
	int i, a = 0;
	DEBUG(a,"linha 32");
	for(i=0;i<hash->size;i++){
		if(!is_empty(hash->table[i])){
			printList(hash->table[i]);
		}
		DEBUG(a,"linha 34");
	}
	return;
}

ht *create_hash(int size)
{
	int i;
	ht *new_hash = (ht*)malloc(sizeof(ht));
	new_hash->table = (node_t **)malloc(size * (sizeof(node_t*)));
	new_hash->size = size;
	for(i=0;i<size;i++) {
		new_hash->table[i] = NULL;
	}
	return new_hash;
}

node_t *remove_list (node_t *head)
{
    node_t *current = head;
    while(head != NULL) {
        current = head->next;
        free(head);
        head = current;
    }
}

ht *free_hash(ht *hash)
{
	int i;
	for(i=0;i<hash->size;i++){
		if(!is_empty(hash->table[i])){
			remove_list(hash->table[i]);
			hash->table[i] = NULL;
		}
	}
}

node_t *create_node(int new_data)
{
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = new_data;
    return new_node;
}

node_t *insert_end(node_t *head, int new_data)
{
	int a = 0;
	node_t *current = head;
	node_t *new_node = create_node(new_data);
	if(head == NULL){
		return new_node;
	}
	DEBUG(a,"linha 40");
	while(current->next != NULL){
		current = current->next;
	}
	DEBUG(a,"linha 45");
	current->next = new_node;
	new_node->prev = current;
	return head;
}

node_t *insert_beggining(node_t *head, int new_data)
{
	node_t *new_node = create_node(new_data);
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
	return head;
}

int finding_key(int key, int size)
{
	return key % size;
}

ht *insert_hash(ht *hash, int new_data)
{
	int key = finding_key(new_data, hash->size);
	hash->table[key] = insert_end(hash->table[key],new_data);
	return hash;
}

ht *remove_from_hash(ht *hash, int data)
{
	int key = finding_key(data,hash->size);
	if(hash->table[key] == NULL){
		printf("No element found\n");
	} else {
		node_t *current = hash->table[key];
		while(current != NULL && current->data != data){
			current = current->next;
		}
		if(current->next == NULL && current->prev == NULL){
			hash->table[key] = NULL;
		} else if(current->next == NULL){
			current->prev->next = NULL;
		} else if(current->prev == NULL){
			hash->table[key] = current->next;
		} else{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		free(current);
	}
	return hash;
}

int main()
{
	int a = 0;
	node_t *head = NULL;
	ht *hash = create_hash(10);
	DEBUG(0,"linha 59");
	hash = insert_hash(hash,1);
	DEBUG(a,"linha 100");
	hash = insert_hash(hash,12);
	// printf("%d\n", hash->table[1]->data);
	DEBUG(a,"linha 102");
	hash = insert_hash(hash,3);
	DEBUG(a,"linha 104");
	hash = insert_hash(hash,5);
	DEBUG(a,"linha 106");
	hash = insert_hash(hash,11);
	hash = insert_hash(hash,21);
	// hash = remove_from_hash(hash,1);
	free_hash(hash);
	hash = insert_hash(hash,10);
	printHash(hash);
	return 0;
}