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