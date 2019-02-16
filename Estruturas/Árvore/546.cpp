#include <bits/stdc++.h>
using namespace std;

struct nodeTree{ int value; nodeTree *right, *left; };

int returnNumber(char *s, int *pos){
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

		returnTree(s, pos, &((*no)->left) );
		returnTree(s, pos, &((*no)->right) );
		(*pos) ++;
	}

}

nodeTree *returnTree(char *s){
	nodeTree *root = (nodeTree *) malloc(sizeof(nodeTree));
	int pos = 1;
	root->value = returnNumber(s, &pos);

	returnTree(s, &pos, &(root->left) );
	returnTree(s, &pos, &(root->right) );

	return root;
}

void dfs(nodeTree *node, int v, int *p, int pTemp){
	if(node == NULL) return;
	else if(node->value == v) { *p = pTemp; return; }
	else{
		dfs(node->left, v, p, pTemp + 1);
		dfs(node->right, v, p, pTemp + 1);
	}
}

void ler(char *s){
	char x;
	int i = 0;
	while(cin >> x) if(x != ' ') s[i++] = x;
	s[i] = '\0';
}

void printTree(nodeTree *no){
	if(no != NULL){
		printTree(no->left);
		cout << no->value << " ";
		printTree(no->right);
	}
}

void verify(nodeTree *no, int *flag, int *vetor, int pos){
	if(no == NULL || flag == 0) return;
	else{

		if(no->left != NULL && no->left->value > no->value){ *flag = 0; return; }
		else if(no->right != NULL && no->right->value < no->value){ *flag = 0; return; }
		else{
			verify(no->left, flag, vetor, pos + 1);
			verify(no->right, flag, vetor, pos + 1);
		}

	}
}

int main(){
	
	char *s = (char *) malloc(sizeof(char) * 10000);
	ler(s);
	int no; cin >> no;

	nodeTree *root = returnTree(s);
	
	int flag = 1;
	int vetor[1000];
	vetor[0] = root->value;
	verify(root, &flag, vetor, 1);

	flag ? cout << "VERDADEIRO" << endl : cout << "FALSO" << endl;

	return 0;
}
