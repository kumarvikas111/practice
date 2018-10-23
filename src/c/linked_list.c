#include <stdio.h>
#include <stdlib.h>
#include <utills.h>
#include <linked_list.h>

ll_node_t * ll_create( ll_node_t * head ) {
	ll_node_t * first = NULL;
	if (NULL == head) {
		first = (ll_node_t *) head;
		first = (ll_node_t *) malloc(sizeof(ll_node_t));
		if( NULL == first){
			fprintf(stderr,"%s %d Error: Insufficient memory.\n",__FILE__,__LINE__);
			return NULL;
		}
		first->next = NULL;
	}
	return first;
}

ll_node_t * ll_add_beg( ll_node_t * head, ll_node_t * data) {

	ll_node_t * first =(ll_node_t *) head;
	ll_node_t * new = ll_create(NULL);
	new->data = data->data;
	new->next = first;
	first = new;	
	return first;
}

ll_node_t * ll_add_mid(  ll_node_t * head, ll_node_t * data, int  pos) {

	int count = 0;
	ll_node_t * first =(ll_node_t *) head;
	ll_node_t * trail;
	if (NULL == first) {
		return NULL;
	}
	while(NULL != first) {
		//condition to break this loop.
		if ( count == pos ) {
			ll_node_t * new = ll_create(NULL);
			trail->next = new;
			new->next = first;
			new->data = data->data;
			return head;				
		}
		count++;
		trail = first;
		first = first->next;
	}
	return NULL;
}

ll_node_t * ll_add_end ( ll_node_t * head, ll_node_t * data) {

	ll_node_t * first =(ll_node_t *) head;
	if (NULL == first) {
		return NULL;
	}
	while (NULL != first) {
		if (first->next == NULL) 
			break;
		first = first->next;
	}
	ll_node_t * new = ll_create(NULL);
	new->data = data->data;
	first->next = new;
	new->next = NULL;
	return head;
}

ll_node_t * ll_del_beg( ll_node_t * head) {

	if (NULL == head ){
		return NULL;
	}
	ll_node_t * first =(ll_node_t *) head;
	ll_node_t * tmp = NULL ;

	tmp = first;
	first = first->next;
	tmp->next = NULL;
	free(tmp);
	return first;
}

ll_node_t * ll_del_mid( ll_node_t * head,int pos) {

	if (NULL == head ){
		return NULL;
	}
	ll_node_t * first =(ll_node_t *) head;
	ll_node_t * trail = NULL;
	ll_node_t * tmp = NULL ;
	int count = 0;	
	while(NULL != first) {
		//condition to break this loop.
		if ( count == pos ) {
			tmp = first;
			trail->next = first->next;
			tmp->next = NULL;
			free(tmp);
			return head;				
		}
		count++;
		trail = first;
		first = first->next;
	}

	return NULL;
}

ll_node_t * ll_del_end( ll_node_t * head) {

	ll_node_t * first =(ll_node_t *) head;
	ll_node_t * tmp;
	if (NULL == first) {
		return NULL;
	}
	while (NULL != first) {
		if (first->next != NULL && first->next->next == NULL) 
			break;
		first = first->next;
	}
	tmp = first->next;
	first->next = NULL;
	free(tmp);
	return head;
}

ll_node_t * ll_reverse( ll_node_t * head) {

	ll_node_t * prev = NULL;
	ll_node_t * curr = head;
	ll_node_t * next = NULL;

	if (NULL == head) {
		return NULL;
	}
	while (curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

	}
	head = prev;
	return head;
}

void*  ll_display( ll_node_t * head) {
	printf("\n========================\n");
	while(head!=NULL){
		printf("%d->",head->data.age);
		head = head->next;
	}
	printf("\n========================\n");
	return NULL ;
}

ll_ops_t ll_ops = {
	.insert_beg = (void *)ll_add_beg,
	.insert_mid = (void *)ll_add_mid,
	.insert_end = (void *)ll_add_end,
	.delete_beg = (void *)ll_del_beg,
	.delete_mid = (void *)ll_del_mid,
	.delete_end = (void *)ll_del_end,
	.reverse = (void *)ll_reverse,
	.display = ll_display,
};

void driver_ll_code(){
	ll_node_t * head =NULL;
	ll_node_t data;
#if 0
	int count = 0;
	data.data.age = 1;
	head = ll_add_beg(head, &data);
	if (NULL == head) PRINTF("%d Head is null\n",count++);
	data.data.age = 2;
	head = ll_add_end(head, &data);
	if (NULL == head) PRINTF("%d Head is null\n",count++);
	data.data.age = 3;
	head = ll_add_end(head, &data);
	if (NULL == head) PRINTF("%d Head is null\n",count++);
	data.data.age = 4;
	head = ll_add_end(head, &data);
	if (NULL == head) PRINTF("%d Head is null\n",count++);
	data.data.age = 5;
	head = ll_add_end(head, &data);
	if (NULL == head) printf("Head is null\n");
	ll_display(head);	
#else
	data.data.age = 1;
	head = ll_ops.insert_beg(head,&data);
	data.data.age = 2;
	head = ll_ops.insert_end(head,&data);
	data.data.age = 3;
	head = ll_ops.insert_end(head,&data);
	data.data.age = 4;
	head = ll_ops.insert_end(head,&data);
	data.data.age = 5;
	head = ll_ops.insert_end(head,&data);
	data.data.age = 6;
	head = ll_ops.insert_mid(head,&data,3);
	data.data.age = 7;
	head = ll_ops.insert_mid(head,&data,4);
	ll_display(head);	
	head = ll_ops.reverse(head);
	ll_display(head);
	head = ll_ops.delete_mid(head,4);
	ll_display(head);
	head = ll_ops.delete_beg(head);
	ll_display(head);
	head = ll_ops.delete_end(head);
	ll_display(head);
#endif
}

#if 1
int main(){

	driver_ll_code();
	return 0;
}
#endif

