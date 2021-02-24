#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}


int dim =1;
int n = 8;

struct node{
  /* malloc size of dimension */

	int v;
	float weight;
	struct node*next;
};
;
struct node* createNode(int, float);
struct edge{
  int row;
  int col;
  float weight;
  struct edge*next;
};
struct edge* createEdge(int,int, float);
struct edge* createEdge(int r, int c, float w){
  struct edge* newEdge = malloc(sizeof(struct edge));
  newEdge->row = r;
  newEdge->col = c;
  newEdge->weight = w;
  newEdge->next = NULL;
  return newEdge;
}
struct node* createNode(int a,  float w) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->v= a;
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}
void printNode(struct node* n){
  printf("%s", "(");
  printf("%d",n->v);
  printf("%s", ",");
  printf("%f",n->weight);
  printf("%s", ")");
}
void printEdge(struct edge* e){
  printf("%s", "(");
  printf("%d",e->row);
  printf("%s", ",");
  printf("%d",e->col);
  printf("%s", ") Weight: ");
  printf("%f\n",e->weight);
}
/*****************
    UNION FIND
******************/

struct Set {
  int key;
  int rank;
  struct Set* parent;
};

struct Set* makeSet(int x) {
  struct Set* newSet = malloc(sizeof(struct Set));
  newSet->rank = 0;
  newSet->parent = newSet;
  return newSet;
};

struct Set* findSet(struct Set* set) {
  if (set != set->parent){
    set->parent = findSet(set->parent);
  }
  return set->parent;
}

struct Set* linkSet(struct Set* x, struct Set* y){
  if (x->rank > y->rank){
    y->parent = x;
    return x;
  }
  if (x->rank == y->rank){
    y->rank = y->rank + 1;
    x->parent = y;
  }
  else{
    x->parent = y;
  }
  return y;
}

struct Set* unionSet(struct Set* x, struct Set* y){
  return linkSet(findSet(x), findSet(y));
}


/***********
    SORT
************/
void swap(struct edge *a, struct edge *b) {
  struct edge t = *a;
  *a = *b;
  *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(struct edge E[], int low, int high) {

  // Select the pivot element
  float pivot = E[high].weight;
  /*printf("%f", pivot);*/
  int i = (low - 1);

  // Put the elements smaller than pivot on the left
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (E[j].weight <= pivot) {
      i++;
      swap(&E[i], &E[j]);
    }
  }

  swap(&E[i + 1], &E[high]);
  return (i + 1);
}

void quickSort(struct edge E[], int low, int high) {
  if (low < high) {

    // Select pivot position and put all the elements smaller
    // than pivot on left and greater than pivot on right
    int pi = partition(E, low, high);

    // Sort the elements on the left of pivot
    quickSort(E, low, pi - 1);

    // Sort the elements on the right of pivot
    quickSort(E, pi + 1, high);
  }
}

// Function to print eklements of an array
void printArray(struct edge E[], int size) {
  for (int i = 0; i < size; ++i) {
    printEdge(&E[i]);
  }
  printf("\n");
}

/*****************
    Kruskals
******************/

int kruskals(int V, struct edge E[], int edgeNum){
  float mstWeight = 0;
  struct Set* setArray[V];
  quickSort(E, 0, edgeNum-1);
  for (int i = 0; i < V; i++){
    setArray[i] = makeSet(i);
  }
  for (int e = 0; e < edgeNum; e++){
    int u = E[e].row;
    int v = E[e].col;
    if (findSet(setArray[u]) != findSet(setArray[v])){
      printEdge(&E[e]);
      mstWeight = mstWeight + E[e].weight;
      printf("->%f\n", mstWeight);
      unionSet(setArray[u], setArray[v]);
    }
  }
  printf("%f", mstWeight);
  return mstWeight;
}


/*****************
      Run Algs
******************/
int main() {
  int num = factorial(n);
  int denom = 2 * factorial(n-2);
  int numOfEdges = num/denom;

 struct edge edges [numOfEdges]; /* this should be n choose 2, but for now it is n^2 */
 struct node adj [n][n];
 int count = 0;
 for(int i = 0; i< n; i ++){
  for (int j = 0; j<n; j ++){
    if (i == j){
    adj[i][j].v = i; /* there are no self loops */
    adj[i][j].weight = 0.0;

  }
  else if (i < j){
    float w1 = (rand() % 100)/ 100.0f;
    adj[i][j].v=j;
    adj[i][j].weight = w1;
    edges[count].col = i;
    edges[count].row =j;
    edges[count].weight =w1;
    count++;


   /* will be to tell which edge is with  what, since i corresponds to the in vertex and j is the out vertex */

  }
  else{
    adj[i][j].v = j;
    adj[i][j].weight = 0.0;

  }
  }}
  for (int i = 0; i< n; i++){
    printf("%s\n", " ");
    for(int j =0 ; j<n; j ++){
      /*printNode(&adj[i][j]);*/
    }
  }
  printf("%s\n", " ");
  for (int i =0; i< (numOfEdges); i++){
    /*printEdge(&edges[i]);*/
  }

  printf("\n");

  /* kruskals testing*/
  kruskals(n, edges, numOfEdges);

  return 0;
}








