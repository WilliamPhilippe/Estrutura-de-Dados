#include <bits/stdc++.h>
using namespace std;


struct nodeTree{ int value; nodeTree *right, *left; };

int toN(char *s){
	int number = 0;;

	for(int i = 0; s[i] != '\0'; i++) number = number * 10 + s[i] - 48;

	return number;
}

int returnNumber(char *s, int *pos){
	char toNumber[10000];
	int i, number = 0;
	for(i = *pos; s[i] >= 48 && s[i] <= 57; i++) number = (number*10) + (s[i] - 48);
	*pos = i;
	return number;
}

void returnTree(char *s, int *pos, nodeTree **no){

	if(s[*pos] == '(' && s[*pos + 1] == ')'){ (*pos) += 2; *no = NULL; return; }
	else if(s[*pos] == ')'){ (*pos) ++; return; }
	else{
		(*pos) ++;
		int number = returnNumber(s, pos);	
		nodeTree *newNode = (nodeTree *) malloc(sizeof(nodeTree));
		newNode->value = number;
		*no = newNode;
		// cout << (*no)->value << " ";

		returnTree(s, pos, &((*no)->left) );
		returnTree(s, pos, &((*no)->right) );
		(*pos) ++;
	}

}

void printTree(nodeTree *no){
	
	nodeTree *current = no;

	while(1){
		if(current->value == 1 && current->right == NULL){ cout << "x"; return; }
		current = current->right;
	}

}


int main(){
	
	char s[100000]; gets(s);
	int no; cin >> no;

	nodeTree *root = (nodeTree *) malloc(sizeof(nodeTree));
	int pos = 1;
	root->value = returnNumber(s, &pos);

	returnTree(s, &pos, &(root->left) );
	returnTree(s, &pos, &(root->right) );
	
	printTree(root);

	return 0;
}
