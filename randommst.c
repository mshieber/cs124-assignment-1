#include <stdio.h>
#include <stdlib.h>


int dim =0; 
int n = 2;
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
  int weight;
  struct edge*next;
};
struct edge* createEdge(int,int, int);
struct edge* createEdge(int r, int c, int w){
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
int main() {
 struct edge edges [n*n]; /* this should be n choose 2, but for now it is n^2 */
 struct node adj [n][n];
 int count = 0;
 for(int i = 0; i< n; i ++){
  for (int j = 0; j<n; j ++){
    if (i == j){
    adj[i][j].v = i; /* there are no self loops */
    adj[i][j].weight = 0.0;
    
  }
  else if (i< j){
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
  }
  for (int i = 0; i< n; i++){
    printf("%s\n", " ");
    for(int j =0 ; j<n; j ++){
      printNode(&adj[i][j]);
    }
  }
 }


}

  


