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

int main() {
  int num = factorial(n);
  int denom = 2 * factorial(n-2);

 struct edge edges [num/denom]; /* this should be n choose 2, but for now it is n^2 */
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
  }}
  for (int i = 0; i< n; i++){
    printf("%s\n", " ");
    for(int j =0 ; j<n; j ++){
      printNode(&adj[i][j]);
    }
  }
  printf("%s\n", " ");
  for (int i =0; i< (num/denom); i++){
    printEdge(&edges[i]);
  }
 
  return 0;
  }
 




  


