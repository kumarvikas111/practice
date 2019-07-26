#include <stdio.h>
//#include <utills.h>

#define SQ(X) (X)*(X)


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
#if 0
	execute_on_var();
	execute_on_ptr();
#endif
	int x = 3;
	printf("SQ=%d\n",SQ(++x));
	int y = 20;
	x = 10;
	x = !x;
	y = !y;
	printf("%d expr (x=!x)X=%d (y=!y) y=%d\n",__LINE__,x,y);
	y=!x && !y;
	printf("%d X=%d y=%d\n",__LINE__,x,y);
	char b = 0xFF;
	x=0xFFFFFFFF;
	b =b+1;
	printf("%d b=%d x=%d x+2: %d\n",__LINE__,b,x,(x+2));
	b= b+1;
	printf("%d b=%d \n",__LINE__,b);
	return 0;

}

