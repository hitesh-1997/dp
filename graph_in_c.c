#include <stdio.h>
#include <malloc.h>

struct Node{
      int dest;
      struct Node *next;
};

struct Graph{
   int V;
   struct Node **head;
};

struct Graph *createGraph(int V){
   struct Graph *g;
   g->V = V;
   g->head = (struct Node **)malloc(V*sizeof(struct Node*));
   int i;
   for(i=0;i<V;i++){
      *((g->head)+i) = NULL;
   }
   return g;
}

struct Node *Insert(struct Node *head,int data){
    struct Node *ptr = head;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->dest = data;
    temp->next = head;
    head = temp;
   return head;
}

struct Graph *addEdge(struct Graph* graph, int src, int dest){
   struct Node *ptr1 = Insert(*((graph->head)+src),dest);
   *((graph->head)+src) = ptr1;
   printf("*******************");
   struct Node *ptr2 = Insert(*((graph->head)+dest),src);
   *((graph->head)+dest) = ptr2;
   printf("--------------------------------\n");

   return graph;
}

void Print(struct Node *head){
  struct Node *ptr;
  ptr = head;
  while(ptr != NULL){
      printf("-> %d ",ptr->dest);
      ptr = ptr->next;
  }
  free(ptr);
}

void printGraph(struct Graph *graph){
   int i;
   for(i=0;i<graph->V;i++){
      printf("for the vertex i= %d, the values are: \n",i);
      printf("head");
      Print((graph->head[i]));
      printf("\n");
   }
}

int main(void){
   int V = 5;
   struct Graph* graph = createGraph(V);
   graph = addEdge(graph, 0, 1);
   graph = addEdge(graph, 0, 4);
   graph = addEdge(graph, 1, 2);
   graph = addEdge(graph, 1, 3);
   graph = addEdge(graph, 1, 4);
   graph = addEdge(graph, 2, 3);
   graph = addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
   printGraph(graph);
   free(graph);
   return 0;
}

