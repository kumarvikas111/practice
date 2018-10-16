#pragma once
#include <stdio.h>

typedef struct data_s {
	int age;
	int date_of_birth;
}data_t;

typedef struct linked_list {
	int ll_length;
	data_t data;
	struct linked_list *next;
}ll_node_t;

typedef struct linked_list_ops {
	void * (* insert_beg) (void *,void *);
	void * (* insert_mid) (void *,void *,int);
	void * (* insert_end) (void *,void * );
	void * (* delete_beg) (void *);
	void * (* delete_mid) (void *,void *,int );
	void * (* delete_end) (void *);
	void * (* reverse) (void *);
	void (*display)(void *);
}ll_ops_t;
