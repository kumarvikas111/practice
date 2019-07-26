#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node * next;
}node;
//find middle node in linked list.
void find_middle_node(node * head){

	if(head == NULL) return;
	if(head->next == NULL) return;

	node *slow_ptr = head;
	node *fast_ptr = head;

	if(fast_ptr !=NULL && fast_ptr->next != NULL){
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;// this is the middle node.
	}

}
// insert node at begning
void add_beg(node ** head, int val) {
	node * new = (node *) malloc(sizeof(node));
	new->data = val;
	new->next = *head;
	*head = new;
}
//delete a node linked list.

void delete_node(node ** head,int val){
	node * tmp,prev;
	tmp = *head;
	// first node is the deleting node.
	if(tmp != NULL && tmp->data==val){
		*head = tmp->next;
		free(tmp);
		return;
	}
	
	while(tmp!=NULL && tmp->data==val){
		prev = tmp;
		tmp = tmp->next;
	}
	
	if(tmp == NULL) return;
	prev->next = tmp->next;
	free(tmp);
	return;
}
//Allocate dynamic 2D array 
// using single pointer

void alloc_single_pointer(int row, int col){
	int * arr = (int *)malloc(row*col*sizeof(int));
	//Access code:
	int i,j,count=0;
	for(i=0i<row;i++)
		for(j=0;j<col;j++)
			*(arr+i*col+j) = ++count;
	return;
}
//using an array pointer.
void alloc(int row,int col){

	int *arr[row];
	int i;
	for(i=0;i<row;i++)
		arr[i] = (int*)malloc(col*sizeof(int));
		
	//access code:
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			arr[i][j] = ++count;	
}
//using pointer to pointer
void alloc_doubleptr(int row,int col){
 int **arr = (int **)malloc(row * sizeof(int *)); 
    for (i=0; i<row; i++) 
         arr[i] = (int *)malloc(col * sizeof(int)); 
         //access code:
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			arr[i][j] = ++count;
}
// one malloc call:
void alloc_dbptr(int row,inr col){

	len = sizeof(int *) * r + sizeof(int) * c * r; 
    arr = (int **)malloc(len); 
     for (i = 0; i < r; i++) 
        for (j = 0; j < c; j++) 
            arr[i][j] = ++count;
}

//reverse linked list
node * reverse_linked_list(node *head){
	node * prev,*curr,next;
	prev = NULL;
	next = NULL;
	if (NULL == head) { return NULL }
	curr = head;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}	
	head = prev;
	return head;
}
//recursive reverse

void recursiveReverse(node ** head){
	node * curr;
	node * next;
	if ( NULL == head){
		return ;
	}
	curr = *head;
	next = *head->next;
	if (next == NULL){
		return;
	}
	recursiveReverse(&next);
	curr->next->next = curr;
	curr->next = NULL;
	*head = next;
}
