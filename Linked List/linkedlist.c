#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *link;
};


void Display(struct node*);
struct node *InsertAtBeginning(struct node*, int);
void InsertAtEnd(struct node*, int);
struct node *createList(struct node*);
void InsertAfter(struct node*, int, int);
struct node *InsertBefore(struct node*, int, int);
struct node *InsertAtIndex(struct node*, int, int);
struct node *DeletefromBeginning(struct node*);
struct node *DeletefromEnd(struct node*);
struct node *Delete(struct node*, int);
struct node *Reverse(struct node*);
struct node *concatinate(struct node*, struct node*);





void main(){
int n, i;
struct node *start=NULL;
struct node *start1=NULL;
printf("\t********Implementation of Linked List********\n\n");
int choice, data, x, k;

start = createList(start);
while(1){
    printf("\tEnter the choice :\n\n");
    printf("\t1.Display the linked list\n");
    printf("\t2.Insert a new node in the beginning\n");
    printf("\t3.Insert a new node at the end\n");
    printf("\t4.Inset after a certain node\n");
    printf("\t5.Insert before a certain node\n");
    printf("\t6.Insert at a given Index\n");
    printf("\t7.Delete from the beginning\n");
    printf("\t8.Delete from the end\n");
    printf("\t9.Delete a given node n\n");
    printf("\t10.Reverse the list\n");
    printf("\t11.Create another list and contatinate\n");
    printf("\t12.Exit\n");
    scanf("%d", &choice);
    if(choice==12)
        break;
    switch(choice){
        case 1: Display(start);
                break;
        case 2: printf("Enter the node element:\n");
                scanf("%d", &data);
                start=InsertAtBeginning(start, data);
                break;
        case 3: printf("Enter the node element:\n");
                scanf("%d", &data);
                InsertAtEnd(start, data);
                break;
        case 4: printf("Enter the node element to be inserted:\n");
                scanf("%d", &data);
                printf("Enter node after which you want to Insert\n");
                scanf("%d", &x);
                InsertAfter(start, data, x);
                break;
        case 5: printf("Enter the node element to be inserted:\n");
                scanf("%d", &data);
                printf("Enter node after which you want to Insert\n");
                scanf("%d", &x);
                start=InsertBefore(start, data, x);
                break;
        case 6: printf("Enter the node element to be inserted:\n");
                scanf("%d", &data);
                printf("Enter the index\n");
                scanf("%d", &k);
                start=InsertAtIndex(start, data, k);
                break;
        case 7: printf("Deleted form beginnign\n\n");
                start=DeletefromBeginning(start);
                break;
        case 8: printf("Deleted form the end\n\n");
                start=DeletefromEnd(start);
                break;
        case 9: printf("Enter the node element to be deleted:\n");
                scanf("%d", &data);
                start=Delete(start, data);
                break;
        case 10:printf("Reversed the linked list\n\n");
                start=Reverse(start);
                break;
        case 11:start1=createList(start1);
                start=concatinate(start, start1);
                break;
        default:printf("\tEnter a valid choice\n");
                break;
    }
}


}



struct node *createList(struct node *start){

int n, data, i;

printf("\tEnter the number of nodes:\n");
scanf("%d", &n);

if(n==0)
return start;

printf("Enter the first node:\t");
scanf("%d", &data);
start=InsertAtBeginning(start, data);

for(i=2; i<=n; i++){
printf("Enter the next element to be Inserted\t");
scanf("%d", &data);
InsertAtEnd(start, data);
 }
 printf("\n\n");
return start;
} // end of createList()




struct node *InsertAtBeginning(struct node* start, int data){
struct node *temp;

temp= (struct node*)malloc(sizeof(struct node));
temp->info=data;
temp->link=start;
start=temp;
return start;
}


void InsertAtEnd(struct node* start, int data){

struct node *temp, *ptr;
temp= (struct node*)malloc(sizeof(struct node));
temp->info=data;
ptr=start;

while(ptr->link!=NULL)
ptr=ptr->link;

ptr->link=temp;
temp->link=NULL;
}


void Display(struct node *start){
int i;

struct node *ptr;
if(start==NULL){
printf("\tList is empty\n\n");
return;
}
printf("Displaying the linked list\n\n");
ptr=start;
while(ptr!=NULL){
printf("%d  ", ptr->info);
ptr=ptr->link;
 }
printf("\n\n");
}


void InsertAfter(struct node *start, int data, int x){

   struct node *p, *temp;
   p=start;

   while(p!=NULL){
    if(p->info==x)
        break;
    p=p->link;
   }

   if(p==NULL)
    printf("Not present in the list\n\n");
   else{
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=p->link;
    p->link=temp;
   }
}



struct node *InsertBefore(struct node *start, int data, int x){
    struct node *p, *temp;
    temp->info=data;
    p=start;
    if(start==NULL){
        printf("List is empty\n");
        return start;
    }

    if(x==start->info){
        temp= (struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=start;
        start=temp;
        return start;
    }

    while(p->link!=NULL){
            if(p->link->info==x)
            break;
    p=p->link;
    }

    if(p==NULL){
        printf("Item not present in the list\n");
    }
    else{
        temp= (struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=p->link;
        p->link=temp;
    }

    return start;

}


struct node *InsertAtIndex(struct node *start, int data, int k){
    struct node *p=start, *temp=start;
    int i;

    if(k==1){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=start;
        start=temp;
        return start;
    }

    for(i=1 ; i<k-1 && p!=NULL; i++){
        p=p->link;
    }

    if(p==NULL){
        printf("You can only enter upto %dth node\n", i);
        return start;
    }
    else{
        temp = (struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=p->link;
        p->link=temp;
    }
    return start;

};


struct node *DeletefromBeginning(struct node* start){
    struct node *temp;
    if(start==NULL){
        printf("List is empty");
        return start;
    }
    temp=start;
    start=start->link;
    free(temp);
    return start;
};

//Run time error: Aborted(core dumped)
//fixed at 11:07PM 07/10/17
struct node *DeletefromEnd(struct node* start){
    struct node *temp, *p;
    if(start==NULL){
        printf("List is empty");
        return start;
    }
    p=start;
    while(p->link->link!=NULL)
        p=p->link;
    temp=p->link;
    p->link=NULL;
    free(temp);
    return start;
}


struct node *Delete(struct node* start, int x){

    struct node *temp, *p;
    if(start==NULL){
        printf("List is empty");
        return start;
    }
    if(start->info==x){
        temp=start;
        start=start->link;
        free(temp);
        return start;
    }
    p=start;
    while(p->link!=NULL){
        if(p->link->info==x)
            break;
        p=p->link;
    }

    if(p->link==NULL){
        printf("node not found\n\n");
    }
    else{
        temp=p->link;
        p->link=temp->link;
        free(temp);
    }
    return start;
}



struct node *Reverse(struct node* start){
    struct node *ptr, *prev, *next;
    ptr=start;
    prev=NULL;

    while(ptr!=NULL){
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
};



struct node *concatinate(struct node *start, struct node *start1){
    struct node *p;
    p=start;
    if(start==NULL){
       start=start1;
 	return start;
	}
	if(start1==NULL)
		return start;

    while(p->link!=NULL){
        p=p->link;
    }
    p->link=start1;
    return start;
};




