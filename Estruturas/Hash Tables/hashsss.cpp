#include <bits/stdc++.h>
using namespace std;

struct node{ int key; node *next; };
struct HashSet{ int count; node *head; };
struct infoSet{ int size, elemment, rehash; };
infoSet* info = NULL;

void insertHash(HashSet *hash, int key);
void deleteHash(HashSet *hash, int key);

HashSet *CreateHash(int x){
	HashSet *newNode = (HashSet *) calloc(x, sizeof(HashSet));
	newNode->head = NULL;
	return newNode;
}

node *CreateNode(int key){
	node *newNode = (node *) malloc(sizeof(node));
	newNode->key = key;
	newNode->next = NULL;
	return newNode;
}

HashSet *ReHash(HashSet *hash){
	int oldSize = info->size;
	info->size = (info->size * 2) - 1;

	HashSet *newHash = (HashSet *) calloc(info->size, sizeof(HashSet));
	for(int i = 0; i < oldSize; i++){
		while(hash[i].head != NULL){
			node *aux = hash[i].head;
			insertHash(newHash, aux->key);
			hash[i].head = hash[i].head->next;

			free(aux);
		}

		hash[i].count = 0;
	}

	free(hash);
	return newHash;
}

void search(HashSet *hash, int key){
	int shut = 0;
	int hashID = key % info->size;
	int flag = 0;
	node *myNode = hash[hashID].head;

	if(!myNode){
		cout << "0 " << shut << endl;
		return;
	}

	while(myNode != NULL){
		shut++;
		if(myNode->key == key){
			cout << "1 " << shut << endl;
			flag = 1;
			break;
		}
		myNode = myNode->next;
	}

	if(!flag) cout << "0 " << shut << endl;
}

int main(){

	float a = 0.0, key = 0;
	char op[4] = {0};
	info = (infoSet *) calloc(1, sizeof(infoSet));
	info->size = 7;
	HashSet *hash = CreateHash(info->size);

	for(int i = 0; scanf("%s",op) != EOF; i++ ){

		if(op[0] == 'A'){
			cin >> key;
			cout << i << " ";
			insertHash(hash, key);
			a = (float)info->elemment/info->size;
			if(a >= 0.75){
				info->rehash = 1;
				hash = ReHash(hash);
				info->rehash = 0;
			}
		}
		else if(op[0] == 'D'){
			cin >> key;
			cout << i << " ";
			deleteHash(hash, key);
		}
		else if(op[0] == 'H'){
			cin >> key;
			cout << i << " ";
			search(hash, key);
		}
		else{
			cout << i << " " << info->size << " " << info->elemment << " ";
			int max = 0;
			for(int j = 0; j < info->size; j++){
				if(hash[j].count > max) max = hash[j].count;
			}
			cout << max << endl;
		}

	}

	return 0;
}

void insertHash(HashSet *hash, int key){
	int shut = 0;
	int hashID = key % info->size;

	if(hash[hashID].head == NULL){
		hash[hashID].head = CreateNode(key);
		hash[hashID].count = 1;

		if(!info->rehash){
			info->elemment ++;
			cout << "1 " << shut << endl;
		}
		return;
	}

	node *aux = hash[hashID].head;
	while(aux != NULL){
		shut++;
		if(key == aux->key){
			if(!info->rehash){
				cout << "0 " << shut << endl;
				return;
			}
		}

		aux = aux->next;
	}

	node *newNode = CreateNode(key);
	newNode->next = hash[hashID].head;

	hash[hashID].head = newNode;
	hash[hashID].count ++;

	if(!info->rehash){
		info->elemment ++;
		cout << "1 " << shut << endl;
	}
}

void deleteHash(HashSet *hash, int key){

	int hashID = key % info->size, shut = 0, flag = 0;
	node *myNode = hash[hashID].head;
	node *temp = myNode;

	if(!myNode){ cout << "0 " << shut << endl; return; }

	while(myNode != NULL){
		shut ++;

		if(myNode->key == key){
			flag = 1;
			if(myNode == hash[hashID].head) hash[hashID].head = myNode->next;
			else temp->next = myNode->next;

			hash[hashID].count --;
			free(myNode);
			break;
		}

		temp = myNode;
		myNode = myNode->next;
	}

	if(flag){
		info->elemment --;
		cout << "1 " << shut << endl;
	}	
	else cout << "0 " << shut << endl;
}