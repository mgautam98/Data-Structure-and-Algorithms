/*
Author: Gautam Mishra
Date: 12/12/2017
File Name: binary search tree
Purpose: Implementation of binary search tree
*/

#include<stdio.h>
#include<stdlib.h>


struct node{
  int info;
  struct node *lchild;
  struct node *rchild;
};

struct node *search(struct node*, int);
struct node *Min(struct node*);
struct node *Max(struct node*);
struct node *insertNode(struct node*, int);
struct node *getnode(int);
struct node *deleteNode(struct node*, int);
struct node *delete_min_key_element(struct node *root);

int main()
{
  int x, choice;
  struct node *root=NULL, *p;
  printf("Insert root node:\t");
  scanf("%d", &x);
  root = getnode(x);
  while(1){
    printf("\n");
    printf("1.Insert a node\n");
    printf("2.Delete a node\n");
    printf("3.Search a node\n");
    printf("4.Find max of tree\n");
    printf("5.Find min of tree\n");
    printf("6.Exit\n\n");
    printf("Enter choice\n");
    scanf("%d", &choice);
    if(choice==7)
      break;
    switch(choice){
      case 1: printf("Enter the node\t");
              scanf("%d", &x);
              root=insertNode(root, x);
              break;
      case 2: printf("Enter the node\t");
              scanf("%d", &x);
              root=deleteNode(root, x);
              break;
      case 3: printf("Enter node to search\t");
              scanf("%d", &x);
              p=search(root, x);
              if(p!=NULL)
                printf("%d found\n", p->info);
              else
                printf("Not found\n");
              break;
      case 4: p=Max(root);
              if(p==NULL)
                printf("Tree is empty");
              else
                printf("Maximum key is %d\n", p->info);
              break;
      case 5: p=Min(root);
              if(p==NULL)
                printf("Tree is empty");
              else
              printf("Minimum key is %d\n", p->info);
              break;
      case 6 :
	      root=delete_min_key_element(root);
	      break;
	
      default:break;
    }
  }

  return 0;
}


struct node *getnode(int x){
  struct node *p = (struct node*)malloc(sizeof(struct node));
  p->info=x;
  p->lchild=NULL;
  p->rchild=NULL;
  return p;
}

struct node *insertNode(struct node *root, int x){
  struct node *temp, *par, *p;
  p=root;
  par=NULL;
  while(p!=NULL){
    par=p;
    if(x>p->info)
      p=p->rchild;
    else if(x<p->info)
      p=p->lchild;
    else{
      printf("%d already present in the tree", x);
      return root;
    }
    temp=getnode(x);

    if(par==NULL)
      root=temp;
    else if(x<par->info)
      par->lchild=temp;
    else if(x>par->info)
      par->rchild=temp;

    return root;
  }
}

struct node *search(struct node *p, int x){
  if(p==NULL)
    return NULL;
  if(x>p->info)
    return search(p->rchild, x);
  if(x<p->info)
    return search(p->lchild, x);
  return p;
}

struct node *Min(struct node *p){
  if(p==NULL)
    return NULL;
  while(p->lchild!=NULL)
    p=p->lchild;
  return p;
}

struct node *Max(struct node *p){
  if(p==NULL)
    return NULL;
  while(p->rchild!=NULL)
    p=p->rchild;
  return p;
}


struct node *deleteNode(struct node *root, int x){
  struct node *p, *par, *s, *ps, *ch;

  p=root;
  par=NULL;
  while(p!=NULL){
    if(x==p->info)
      break;
    par=p;
    if(x<p->info)
      p=p->lchild;
    else if(x>p->info)
      p=p->rchild;
  }

  if(p==NULL){
    printf("%d not found", x);
    return root;
  }


  if(p->lchild!=NULL && p->rchild!=NULL){
    ps=p;
    s=p->rchild;
    while(s->lchild!=NULL){
      ps=s;
      s=s->lchild;
    }
    p->info=s->info;
    p=s;
    par=ps;
  }

  if(p->lchild!=NULL)
    ch=p->lchild;
  else
    ch=p->rchild;

  if(par==NULL)
    root=ch;
  else if(p==par->lchild)
    par->lchild=ch;
  else
    par->rchild=ch;
  free(p);
  return root;
};

struct node *delete_min_key_element(struct node *root){
	struct node *temp3;
	 if(root==NULL){
       	        printf("tree is empty");
       	  	 return NULL;
        }
	if(root->lchild==NULL){
		temp3=root;
		if(root->rchild==NULL){
			free(temp3);
			return NULL;
		}
		root=root->rchild;
		free(temp3);
		return root;
	}
	struct node *temp=root,*temp2;

	while(temp->lchild!=NULL)
	{
		temp2=temp;
		temp=temp->lchild;
	}
  	temp2->lchild=NULL;
        free(temp);
        return root;
}
