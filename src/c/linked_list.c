#include <stdio.h>
#include <stdlib.h>
#include <utills.h>
#include <linked_list.h>

ll_node_t * ll_create(const ll_node_t * head) {
	ll_node_t * first = NULL;
	if (NULL == head) {
	ll_node_t * first = head;
		first = (ll_node_t) malloc(sizeof(ll_node_t));
		if( NULL == first){
			fprintf(stderr,"%s %d Error: Insufficient memory.\n",__FILE__,__LINE__);
			return NULL
		}
		first->data = NULL;
		first->next = NULL;
  }
	return first;
}

ll_node_t * ll_add_beg(const ll_node_t * head,const ll_node_t * data) {
	
	ll_node_t * first = head;
	if (NULL == first) {
		return ll_create(first);
	}
	ll_node_t * new = ll_create(NULL);
	new->data = data->data;
	new->next = first;

	return first;
}

static ll_node_t * ll_reverse(const ll_node_t * head) {
	return NULL;
}

ll_ops_t ll_ops = {
		.insert_beg = ll_add_beg,
		.insert_mid = ll_add_mid,
		.insert_end = ll_add_end,
		.delete_beg = ll_del_beg,
		.delete_mid = ll_del_mid,
		.delete_end = ll_del_end,
		.reverse = ll_reverse,
		.display = ll_display,
};


