#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if(0)
#define DEBUG1 if(0)

typedef struct Node {
    int key;
    struct Node *next;
}Node;

typedef struct hash {
    Node *head;
    int count;
}hash;

typedef struct info {
    int size;
    int elements;
    int rehash;
}Info;
Info *info = NULL;


hash *createHash(int size);
Node *createNode(int key);
hash *rehash(hash *ht);
void search(hash *ht,int key);
void insertToHash(hash *ht,int key);
void deleteFromHash(hash *ht, int key);


void main()
{
    float alpha     = 0;
    int key         = 0;
    char op[4]      = {0};
    info            = calloc(1,sizeof(Info));
    info->size      = 7;
    hash *ht        = createHash(info->size);

    DEBUG1{
        printf("%d\n",ht->count);
        insertToHash(ht,10);
        display(ht);
        deleteFromHash(ht,10);
        display(ht);

        insertToHash(ht,10);
        insertToHash(ht,20);
        insertToHash(ht,59);
        display(ht);
        search(ht, 11);
        search(ht, 20);
    }

    DEBUG {
        insertToHash(ht,61);
        insertToHash(ht,51);
        insertToHash(ht,90);
        insertToHash(ht,94);
        insertToHash(ht,51);
        insertToHash(ht,70);
        insertToHash(ht,59);
        deleteFromHash(ht,61);
        search(ht, 70);
        display(ht);    
        printf("%d %d \n",info->size, info->elements);
    }
    
    int i;
    for(i = 0;scanf("%s",op) != EOF;i++)
    {
        if(strcmp(op,"ADD") == 0)
        {
            
            scanf("%d",&key);
            printf("%d ", i);
            insertToHash(ht, key);
            alpha = (float)info->elements/info->size;
            if(alpha >= 0.75)
            {
                info->rehash = 1;
                ht = rehash(ht);
                info->rehash = 0;
            }
        }
        else if(strcmp(op,"DEL") == 0)
        {
            scanf("%d",&key);
            printf("%d ",i);
            deleteFromHash(ht,key);
        }
        else if(strcmp(op,"HAS") == 0)
        {
            scanf("%d",&key);
            printf("%d ", i);
            search(ht, key);
        }
        else 
        {
            printf("%d ", i);
            printf("%d ", info->size);
            printf("%d ", info->elements);
            int j = 0, max = 0;
            for(;j < info->size; j++)
                if(ht[j].count > max)
                    max = ht[j].count;
            printf("%d\n", max);
        }
    }
}

hash *createHash(int size)
{
    hash *newHash = calloc(size, sizeof(hash));
    newHash->head = NULL;

    return newHash; 
}

Node *createNode(int key) 
{
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

hash *rehash(hash *ht)
{
    int oldSize = info->size;
    int newSize = (info->size * 2) - 1;
    info->size = newSize;
    hash *newHash = calloc(newSize, sizeof(hash));
    int i;
    for(i = 0; i < oldSize; i++)
    {
        while(ht[i].head != NULL)
        {
            Node *aux = ht[i].head;
            insertToHash(newHash,aux->key);
            ht[i].head = ht[i].head->next;
            free(aux);
        }
        ht[i].count = 0;
    }
    free(ht);
    return newHash;
}

void search(hash *ht,int key) 
{
    int actions = 0;
    int hashIndex = key % info->size, flag = 0;
    Node *myNode;
    myNode = ht[hashIndex].head;
    if (!myNode) {  // empty node
        printf("%d %d\n",0,actions);
        return;
    }
    while (myNode != NULL) {
        actions++;
        if (myNode->key == key) {
            printf("%d %d\n",1,actions);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
    {
        printf("%d %d\n",0,actions);
    }
    return;
}

void deleteFromHash(hash *ht, int key) 
{
    int hashIndex = key % info->size;
    int flag = 0;
    int actions = 0;
    Node *temp, *myNode;
    myNode = ht[hashIndex].head;
    if (!myNode) { //empty node
        printf("%d %d\n",0,actions);
        return;
    }
    temp = myNode;
    while (myNode != NULL) {
        actions++;
        if (myNode->key == key) {
            flag = 1;
            if (myNode == ht[hashIndex].head)
                ht[hashIndex].head = myNode->next;
            else
                temp->next = myNode->next;
            ht[hashIndex].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;

    }
    if (flag)
    {
        info->elements--;
        printf("%d %d\n",1,actions);
    }
    else
    {
        printf("%d %d\n",0,actions);
    }
    return;
}

void insertToHash(hash *ht, int key) 
{
    int actions = 0;
    int hashIndex = key % info->size;

    if(!ht[hashIndex].head)
    {
        ht[hashIndex].head = createNode(key);
        ht[hashIndex].count = 1;
        
        if(!info->rehash)
        {
            info->elements++;
            printf("%d %d\n",1,actions);
        }
        return;
    }

    Node *aux = ht[hashIndex].head;
    while(aux != NULL)
    {
        actions++;
        if(aux->key == key)
        {
            if(!info->rehash)
            printf("%d %d\n", 0, actions);
            return;
        }
        aux = aux->next;
    }

    Node *newNode = createNode(key);
    newNode->next = (ht[hashIndex].head);

    ht[hashIndex].head = newNode;
    ht[hashIndex].count++;
    
    if(!info->rehash)
    {
        info->elements++;
        printf("%d %d\n",1,actions);    
    }
     
    return;
}