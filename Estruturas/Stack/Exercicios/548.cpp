#include <bits/stdc++.h>
using namespace std;

struct nodeList
{
	int value;
	nodeList *next;
};

struct nodeStack
{
	nodeList *headList;
	nodeStack *next;
};

struct setStack
{
	nodeStack *headStack;
};

void pushStack(setStack *stack, nodeStack *nodeNewStack){

}

void pushList(nodeList *lista, int x){

}

void popStack(setStack *stack){

}


int main(){

	char trash, command[1000];
	int x;

	setStack *stack = (setStack *) malloc(sizeof(setStack));
	stack->headStack = NULL;

	while(gets(command)){
		cout << command << endl;

		if(command == "PUSH"){
			nodeStack *nodeNewStack = (nodeStack *) malloc(sizeof(nodeStack));
			nodeNewStack->headList = NULL;

			while(1){
				cin >> x >> trash;
				pushList(nodeNewStack->headList, x);

				if(trash == '\n') break;
			}

			pushStack(stack, nodeNewStack); 
		}
		else if(command == "POP"){

		}
		else{ cout << "error";  }
	}



	return 0;
}
