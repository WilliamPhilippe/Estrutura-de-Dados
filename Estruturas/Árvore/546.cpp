#include <bits/stdc++.h>
using namespace std;

struct nodeTree{ int value; nodeTree *right, *left; };

int returnNumber(char *s, int *pos){
	char toNumber[10000];
	int i;
	for(i = *pos; s[i] >= 48 && s[i] <= 57; i++){
		toNumber[i - *pos] = s[i];
	}

	toNumber[i] = '\0';
	*pos = i;
	return atoi(toNumber);
}

void returnTree(char *s, int *pos, nodeTree **no){

	if(s[*pos] == '(' && s[*pos + 1] == ')'){ (*pos) += 2; no = NULL; return; }
	else if(s[*pos] == ')'){ (*pos) ++; return; }
	else{
		(*pos) ++;
		int number = returnNumber(s, pos);	
		nodeTree *newNode = (nodeTree *) malloc(sizeof(nodeTree));
		newNode->value = number;
		*no = newNode;

		cout << number << " ";


		returnTree(s, pos, &((*no)->left) );
		returnTree(s, pos, &((*no)->right) );
		(*pos) ++;
	}

}

void printInOrder(nodeTree *root){

	if(root != NULL){
		printInOrder(root->left);
		cout << root->value << " ";
		printInOrder(root->right);
	}
}

int main(){
	
	char s[100000]; gets(s);
	int no; cin >> no;

	nodeTree *root = (nodeTree *) malloc(sizeof(nodeTree));
	int pos = 1;
	root->value = returnNumber(s, &pos);
	cout << root->value << " ";	
	returnTree(s, &pos, &(root->left) );
	returnTree(s, &pos, &(root->right) );
	cout << endl;
	printInOrder(root);


	return 0;
}
