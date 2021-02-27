#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
unsigned int factorial(unsigned int n) { 
    if (n == 0) 
        return 1; 
    return n * factorial(n - 1); 
} 

int n;
int dim;
int numtrials;



struct edge{
  int row;
  int col;
  float weight;
  
};

struct edge* createEdge(int,int, float);
struct edge* createEdge(int r, int c, float w){
  struct edge* newEdge = malloc(sizeof(struct edge));
  newEdge->row = r;
  newEdge->col = c;
  newEdge->weight = w;
  
  return newEdge;
}


void printEdge(struct edge* e){
  printf("%s", "(");
  printf("%d",e->row);
  printf("%s", ",");
  printf("%d",e->col);
  printf("%s", ") Weight: ");
  printf("%f\n",e->weight);

}


float distance(float a[dim], float b[dim]){
  
  if(dim==2){
    float dist = (((a[0]-b[0])*(a[0]-b[0])) + ((a[1] - b[1])*(a[1] - b[1])));

    return sqrt(dist);
  }
  if(dim ==3){
    return sqrt( ((a[0]-b[0])*(a[0]-b[0])) + ((a[1]-b[1])*(a[1]-b[1])) + (((a[2]-b[2])) * (a[2]-b[2])));
  }
  if(dim ==4 ){
    return sqrt( ((a[0]-b[0])*(a[0]-b[0])) + ((a[1]-b[1])*(a[1]-b[1])) + (((a[2]-b[2])) * (a[2]-b[2])) + ((a[3]- b[3] )* (a[3]- b[3])));
  }
  else{
    return 0;
  }

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
void swap(struct edge *a, struct edge *b) {
  struct edge t = *a;   
  *a = *b;    
  *b = t;  
}
int partition(struct edge E[], int low, int high) {
  float pivot = E[high].weight;
  int i = (low - 1);
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
      int pi = partition(E, low, high);
      quickSort(E, low, pi - 1);
      quickSort(E, pi + 1, high);
       }
       }
  void printArray(struct edge E[], int size) {
    for (int i = 0; i < size; ++i) {
     /* printEdge(&E[i]);*/
      }
      printf("\n");
    }

/*****************
    Kruskals
******************/
float kruskals(int V, struct edge E[], int edgeNum){
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


int main(int argc, char *argv[]) {
n = atoi(argv[2]);
numtrials = atoi(argv[3]);
dim = atoi(argv[4]);
int num = factorial(n);
int denom = 2 * factorial(n-2);
int num_edges= num/denom; /* this array will be populated with n choose 2 edges, to represent a complete graph*/
struct edge edges [num_edges]; 

float arr [n][dim];
for(int k =0; k<n; k++){
   for(int l =0; l<dim; l++){
      float var = (rand() % 100)/ 100.0f; 
       arr[k][l] = var;
     
      
       }} /*populate self vertices, where the dim -1 row represents the coordinates of the vertices*/
int counter =0;
 for(int i = 0; i< n; i ++){
  for(int j =0; j<n; j++){
  if((dim ==0) && (i<j)){
        float var = (rand() % 100)/ 100.0f;
        float w1 = var;
        printf("%f\n", w1);
        edges[counter].row = i;
        edges[counter].col =j;
        edges[counter].weight = w1;
        counter ++; /* if the dimension is zero the weight of an edge is just a randomly generated number*/
  }
  else{
  if (i< j){/* indicates that an edge should be made on the complete graph*/
      float w1 = distance(arr[i], arr[j]); /* find the distance between 2 vertices*/
      edges[counter].row = i;
      edges[counter].col =j;
      edges[counter].weight = w1;/* add the two vertices to the edge */
      counter ++;
     }

}
 

  }
}
 kruskals(n,edges, num_edges);
 printf("%d",n);
 printf("%s", " ");
 printf("%d", numtrials);
 printf("%s", " ");
 printf("%d", dim);
  return 0;
  }
  

  
 