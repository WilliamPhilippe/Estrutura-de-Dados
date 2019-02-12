#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
//Insira o código aqui

STACK* Create_stack(){
    STACK *stack = (STACK *) malloc(sizeof(STACK));
    stack->head = NULL;
    return stack;
}

NODE* create_node(int element){
    NODE *newNode = (NODE *) malloc(sizeof(NODE));
    newNode->element = element;
    return newNode;
}

int IS_EMPTY(STACK *stack){
    return (stack->head == NULL);
}

int POP(STACK *stack){
    
    NODE *current = stack->head;
    stack->head = stack->head->next;
    int x = current->element;
    free(current);
    return x;
}

void PUSH(STACK *stack, int element){

    NODE *newNode = create_node(element);

    if(stack->head == NULL){
        stack->head = newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = stack->head;
        stack->head = newNode;
    }
}

void result(STACK *stack, char operation){

    switch(operation){
        case '0': PUSH(stack, 0); return;
        case '1': PUSH(stack, 1); return;
        case '2': PUSH(stack, 2); return;
        case '3': PUSH(stack, 3); return;
        case '4': PUSH(stack, 4); return;
        case '5': PUSH(stack, 5); return;
        case '6': PUSH(stack, 6); return;
        case '7': PUSH(stack, 7); return;
        case '8': PUSH(stack, 8); return;
        case '9': PUSH(stack, 9); return;
    }

    int a = POP(stack);
    int b = POP(stack);
    int awser;

    switch(operation){
        case '+': awser = a+b; break;
        case '*': awser = a*b; break;
        case '/': awser = b/a; break;
        case '-': awser = b-a; break;
    }

    PUSH(stack, awser);
}

void Calculadora(STACK* calculadora, int size){
    int x; char c, h;
    scanf("%c", &c);
    int i;
    for(i = 0; i < size; i++){
        scanf("%c%c", &c, &h);
        result(calculadora, c);
    }
}