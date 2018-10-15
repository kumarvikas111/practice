#include <stdio.h>
#include <utills.h>


int add_int(int a, int b) {
	return a+b;
}

int sub_int(int a, int b) {
	return a-b;
}

typedef struct arops{
	int (* add)(int,int);
	int (* sub)(int,int);
}arops;

void execute_on_var() {
	arops ops ={
							 .add = add_int,
							 .sub = sub_int,
						};

	int a = ops.add(3,4);
	int b = ops.sub(4,3);
	printf("add:%d sub:%d\n",a,b);

}

/*On ponter it will not execute.*/
void execute_on_ptr() {

	arops * pops;
	pops->add = add_int;
	pops->sub = sub_int;

	int a = pops->add(3,4);
	int b = pops->sub(4,3);
	printf("add:%d sub:%d\n",a,b);
}

int main() {
	printf("Hello\n");
	execute_on_var();
	execute_on_ptr();

return 0;

}
