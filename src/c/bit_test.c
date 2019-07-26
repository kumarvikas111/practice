#include <stdio.h>

#define dprintf(fmt,...) do{ printf(" %s %d " fmt,__FILE__,__LINE__,__VA_ARGS__)\
														;}while(0);

// now Check interger overflow.
void int_overflow(){
	unsigned int a;
	signed int b;
	char c;
	dprintf("size of int: %d byte:size of char %d byte\n", sizeof(int),sizeof(char));
	a = 0x7FFFFFFF;
	c = 0x7F;
	dprintf("a=%d c=%d\n",a,c);
	c = 130;
	dprintf("a=%d c=%d\n",a,c);
	if (a == c){
		printf("true\n");
	}else{
		printf("flase\n");
	}
	a =0;
	while(a<(8*sizeof(int))){
		printf("%d\n",a++);
	}
}

//==============================================================================
// using bit wise operator.
// Worst case: O(no of bits)
int find_count(int n){
	unsigned int n, count = 0;
	while (n){
		if(n & 1){
			count++;
			n = n>>1;
		}
	}
	return count;
}

// using modulo oprator 
// complexity : worst case = O( no of bits)
int find_count(int val){
	unsigned int n = val, count = 0;
	while (n) {
		if (n/2 ==1){
			count++;
			n = n>>1;
		}
	}
	return count;	
}
// using toggling approch 
// complexity : worst case = O( no of set bits)
int find_counts(int val){
	unsigned int n = val, count = 0;
	while (n){
		count++;
		n = n & (n-1);
	}
	return count;
}
// using Group Processing approch 
// complexity : worst case = O(bits/4)
int table[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4}
int find_counts(int val){
	unsigned int n = val, count = 0;
	while (n){
		count = count + table[(n & 0x0F)];
		n = n >> 4; // Group shifting
	}
	return count;
}


//==============================================================================
int main(){
	
 int_overflow();
	return 0;
}
