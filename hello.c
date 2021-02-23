#include <stdio.h>
#include <stdlib.h>


/*************************
  Graph by Adjacency List
**************************/

struct node {
  int vertex;
  float weight;
  struct node* next;
};
/*struct node_tuple{
	int [] vertex;
	float weight;
	struct node*next;
}*/

struct node* createNode(int,float);

struct Graph {
  int numVertices;
  struct node** adjLists;
};

struct node* createNode(int v, float w) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}
void addEdge(struct Graph* graph, int s, int d, float w) {

  struct node* newNode = createNode(d,w);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;


  newNode = createNode(s,w);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d , %f-> ", temp->vertex, temp->weight);
      temp = temp->next;
    }
    printf("\n");
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
  struct set* newSet = malloc(sizeof(struct set));
  newSet->key = x;
  newSet->rank = 0;
  newSet->parent = x;
  return newSet;
};

struct Set* findSet(struct Set* set) {
  if (set->key != set->parent->key){
    set->parent = findSet(set->parent)
  }
  return set->parent
}

struct Set* linkSet(struct Set* x, struct Set* y){
  if (x->rank > y->rank){
    y->parent = x
    return x
  }
  if (x->rank == y->rank){
    y->rank = y->rank + 1
    x->parent = y
  }
  else{
    x->parent = y
  }
  return y
}

struct Set* unionSet(struct Set* x, struct Set* y){
  linkSet(findSet(x), findSet(y))
}



/*****************
      Run Algs
******************/
int  main() {

  int n = 4;
  float G [n][n]; /* empty undirected graph */
  for (int i = 0; i < n; i++){
  	for (int j = 0; j< n ; j++)
  		if (i == j){
  			G[i][j] = 0; /* there are no self loops */
  			printf("%f ", G[i][j]);
  		}
  		else if (i < j ){
  			G[i][j] = (rand() % 100)/ 100.0f;
  			printf("%f ", G[i][j]); /* first instance of an edge, give it a weight */
  			 ;
  		}
  		else {
  			G[i][j]= 0;
  			printf("%f ", G[i][j]); /* do not add the weight of the repeated edge */
  		}
  	}


  	struct Graph* graph = createAGraph(n);
  	for (int i = 0; i<n; i ++){
  		for (int j=(n); j >i; j --){
  			printf("%d",i);
  			printf("%d ",j);
  			float w = (rand() % 100)/ 100.0f;
  			addEdge(graph,i,j,w);
  		}
  	}


    printGraph(graph);
  return 0;
}
/*
struct node_tuple{
	int key;
	int x;
	int y;
	int z;
	int a;
	float weight;
	struct node*next;
};
struct node_tuple* createNode(int, int, int, int, int, float);
struct Graph {
  int numVertices;
  struct node_tuple** adjLists;
};
struct node_tuple* createNode(int key, int x, int y, int z, int a, float w) {
  struct node_tuple* newNode = malloc(sizeof(struct node_tuple));

  newNode->key = key;
  newNode->x = x;
  newNode->y = y;
  newNode->z = z;
  newNode->a = a;
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node_tuple*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}
int main() {}



void addEdge(struct Graph* graph, int key, int x, int y, int z, int a, int key1, int x1, int y1, int z1, int a1, float w) {

  struct node_tuple* newNode = createNode(key, x, y, z, a, w);
  newNode->next = graph->adjLists[key1];
  graph->adjLists[key1] = newNode;


  newNode = createNode(key1, x1, y1, z1, a1, w);
  newNode->next = graph->adjLists[key];
  graph->adjLists[key] = newNode;
}
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node_tuple* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d, %d, %d, %d, %d, %f-> ", temp->key, temp->x, temp->y, temp->z, temp->a, temp->weight);
      temp = temp->next;
    }
    printf("\n");
  }


}*/
