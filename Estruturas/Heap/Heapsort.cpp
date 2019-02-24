#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

typedef struct heap_adt heap;

struct heap_adt{
  int size;
  int data[MAX];
};

void swap(int * a, int * b){
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

heap * createHeap(){

  heap * new = (heap*)malloc(sizeof(heap));
  new->size = 0;
  return new;
}

int parentIndex(heap * h, int i){
  return (i>>1);
}

int leftIndex(heap * h, int i){
  return (i<<1);
}

int rightIndex(heap * h, int i){
  return ((i<<1)+1);
}

void enqHeap(heap * h, int item){

  if(h->size>=MAX){
    printf("overflow\n");
    return;
  }
  else{
    h->data[++h->size] = item;

    int keyIndex = h->size;
    int parent = parentIndex(h,h->size);

    while(parent >= 1 && h->data[keyIndex] > h->data[parent]){
      swap(&h->data[keyIndex],&h->data[parent]);
      keyIndex = parent;
      parent = parentIndex(h,keyIndex);
    }
  }
}

void maxHeapify(heap * h, int i){
  int largest;
  int left = leftIndex(h,i);
  int right = rightIndex(h,i);

  if(left <= h->size && h->data[left] > h->data[i]){
    largest = left;
  }
  else{
    largest = i;
  }
  if(right <= h->size && h->data[right] > h->data[largest] ){
    largest = right;
  }

  if(h->data[i] != h->data[largest]){
    swap(&h->data[i],&h->data[largest]);
    maxHeapify(h,largest);
  }
}

int deqHeap(heap * h){

  if(!h->size){
    printf("underflow\n");
    return -1;
  }
  else{
    int item = h->data[1];
    h->data[1] = h->data[h->size];
    h->size --;
    maxHeapify(h,1);
    return item;
  }
}

void printHeap(heap * h, int size){

  int i;

  for(i=1;i<=size;i++){
    if(i<size){
      printf(" %d |", h->data[i]);
    }
    else{
      printf(" %d\n", h->data[i]);
    }
  }

}

void maxHeap(heap * h){
  int l = h->size;
  int i;
  for(i=l/2;i>=1;i--){
    maxHeapify(h,i);
  }
}

void heapSort(heap * h){
  int i;
  for(i=h->size;i>=2;i--){
    //maxHeap(h);
    printf("Estado Atual da Heap:");
    printHeap(h,i);
    printf("Maior elemento neste passo: %d\n", h->data[1]);
    swap(&h->data[1],&h->data[i]);
    h->size--;
    maxHeapify(h,1);
  }
  printf("Estado Atual da Heap:");
  printHeap(h,i);
}

void main(){

  int n;
  heap * h = createHeap();

  while(scanf("%d", &n)!=EOF){
    h->data[++h->size] = n;
  }

  printf("Estado inicial:");
  printHeap(h,h->size);

  maxHeap(h);

  int final_size = h->size;

  heapSort(h);

  printf("Resultado Final:");
  printHeap(h,final_size);
  
  free(h);
}