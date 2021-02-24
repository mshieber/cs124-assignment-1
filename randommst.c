#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int n) 
{ 
    if (n == 0) 
        return 1; 
    return n * factorial(n - 1); 
} 


int dim = 4; 
int n = 5;


struct node{
  /* malloc size of dimension */
  
	float v[4][4];
	float weight;
	struct node*next;
};
;
/* struct node* createNode(float [4][4], float);*/
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
/*struct node* createNode(float a [4][4],  float w) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->v[0][0]= a[0][0];
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}*/
void printNode(struct node* n){
  printf("%s", "(");
  if(dim <= 1){
    printf("%f",n->v[0][0]); 
  }
  else{
  int count =0;
  for(int i =0; i< dim; i++)
  {
 printf("%f",n->v[dim-1][count]);
 printf("%s", ",");
 count = count +1;
 
  }}
  printf("%s", ")W:");
  printf("%f\n",n->weight);
  
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
 
 for(int i = 0; i< n; i ++){
  for (int j = 0; j<n; j ++){
    if (i == j){
    if(dim <=1){
    adj[i][j].v[0][0] = i; /* there are no self loops */
    adj[i][j].weight = 0.0;
  }
  else{
    int count =0;
    for(int i=0; i<dim; i++){
      float var = (rand() % 100)/ 100.0f;
      adj[i][j].v[dim-1][count] = var;
      count = count +1;

    }
   
  }
    
  }
  else if (i< j){
    float w1 = (rand() % 100)/ 100.0f;
    adj[i][j].weight = w1;
    /*edges[count].col = i;
    edges[count].row =j;
    edges[count].weight =w1; here is where you want to add the distance between the two edges 
    count++;*/
    if(dim <=1)
    {
    adj[i][j].v[0][0]=j;
    }
    else{
       int count1 = 0;
    for(int i=0; i<dim; i++){
      float var = (rand() % 100)/ 100.0f; /* why is this not a new random variable everytime?*/
      adj[i][j].v[dim-1][count1] = var;
      count1 = count1 +1;
      }
      
  }

   /* will be to tell which edge is with  what, since i corresponds to the in vertex and j is the out vertex */

  } 
  else{
    adj[i][j].weight = 0.0; 
    if(dim <=1){
      adj[i][j].v[0][0]= j;

    }
    else{
      int count1 = 0;
    for(int i=0; i<dim; i++)
    {
      float var = (rand() % 100)/ 100.0f; /* why is this not a new random variable everytime?*/
      adj[i][j].v[dim-1][count1] = var;
      count1 = count1 + 1;

    }
    
    
  }
  }
}}
  for (int i = 0; i< n; i++)
  {
    printf("%s\n", " ");
    for(int j =0 ; j<n; j ++)
    {
      printNode(&adj[i][j]);
    }
  }
  /*printf("%s\n", " ");
  for (int i =0; i< (num/denom); i++){
    printEdge(&edges[i]);
  }*/

 
  return 0;
  }
 




  


