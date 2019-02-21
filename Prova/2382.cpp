#include <bits/stdc++.h>
using namespace std;

int nofnodes = 0;
int altura;
int NosComUmFilho = 0; int filhos[1000];
int IsComplet = 1;

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
		nofnodes++;
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

	nofnodes++;
	returnTree(s, &pos, &(root->left) );
	returnTree(s, &pos, &(root->right) );

	return root;
}

void dfs(nodeTree *node, int H){

	if(node == NULL){
		if( (H - 1) != altura ) IsComplet = 0;
		return;
	}
	else{

		if( (node->left == NULL || node->right == NULL) && node->left != node->right ){
			IsComplet = 0;
			filhos[NosComUmFilho++] = node->value;
		}

		dfs(node->left, H + 1);
		dfs(node->right, H + 1);

	}

}

void printTree(nodeTree *no){
	if(no != NULL){
		printTree(no->left);
		cout << no->value << " ";
		printTree(no->right);
	}
}

int main(){

	char s[10000];
	gets(s);
	nodeTree *root = returnTree(s);
	altura = (int) log( (double) nofnodes ) + 1;

	dfs(root, 0);
	
	if(nofnodes == 1) cout << "completa\ntotal de nos: 1\n";
	else if(IsComplet) cout << "completa\ntotal de nos: " << nofnodes << endl;
	else{
		cout << "nao completa\n";
		cout << "nos com um filho:";
		for(int i = 0; i < NosComUmFilho; i++){
			cout << " " << filhos[i];
		}
		cout << endl;
	}

	



	//execção ara 1 no
	return 0;
}