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


		returnTree(s, pos, &((*no)->left) );
		returnTree(s, pos, &((*no)->right) );
		(*pos) ++;
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
	

	cout << root->left->right->value;



	return 0;
}
