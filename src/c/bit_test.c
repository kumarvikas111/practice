#include <stdio.h>

#define dprintf(fmt,...) do{ printf(" %s %d " fmt,__FILE__,__LINE__,__VA_ARGS__)\
	;}while(0);

/* checking the division.*/

// function to convert decimal to binary 
void decToBinary(int n) 
{ 
	// array to store binary number 
	int val = n;
	int binaryNum[32]; 

	// counter for binary array 
	int i = 0; 
	while (n > 0) { 
		// storing remainder in binary array 
		binaryNum[i] = n % 2; 
		printf("n = %d\t rem = %d\n",n,binaryNum[i]);
		n = n / 2; 
		i++; 
	} 

	// printing binary array in reverse order 
	printf("%d = ",val);
	for (int j = i - 1; j >= 0; j--) 
		printf("%d", binaryNum[j]); 

	printf("\n");
} 


void div(int n){

	int count = 0,rem = 0;
	int power = 1; 

//	printf("Count: %d\tNumber: %d\t Remaider: %d\n",count,n,rem);
	while(n){
		rem = n%2;
		printf("Count: %d\tNumber: %d\t Remaider: %d\n",count,n,rem);
		n =n/2;
		count++;
		power = 2 * power ;
	}
	printf(" power = %d\n",power );
	printf("=======================================\n");
}




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
int find_count(int val){
	unsigned int n, count = 0;
	n = val;
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
int find_count_m(int val){
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
	unsigned int n = val; int  count = 0;
	while (n){
		count++;
		n = n & (n-1);
	}
	return count;
}
// using Group Processing approch 
// complexity : worst case = O(bits/4)

int table[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
int find_counts_l(int val){
	unsigned int n = val, count = 0;
	while (n){
		count = count + table[(n & 0x0F)];
		n = n >> 4; // Group shifting
	}
	return count;
}
// if number is plaindrome or not
// 1 -> success
// 0 -> fail
int ispalindrom_int(int num) {
	char buf[100] = {0};
	sprintf(buf,"%d",num);
	int i=0,j=0,len=0;
	len = strlen(buf)-1;
	while(i<j){
		if(buf[i]!=buf[j]){
			printf("Given number is not plaindrom\n");
			return 0;
		}
	}
	return 1;
}
int ispalindrom_str(char* str) {
	int i=0,j=0,len=0;
	len = strlen(str)-1;
	while(i<j){
		if(str[i]!=str[j]){
			printf("Given string:%s is not plaindrom\n",str);
			return 0;
		}
	}
	return 1;
}

// if number is prime or not
// 1 -> success
// 0 -> fail

int isprime(int n){
	if(n < 0) n = -n;
	if(n>=0 & n<2) print("number is neither prime nor composite\n");
	int i=2;
	for(i=2;i<n/2;i++){
		if(n%i==0){
			return 1;
		}
	}
	return 0;

}
//==============================================================================
int main(){

	//	int_overflow();
	decToBinary(12);
	div(12);
	decToBinary(13);
	div(13);
	decToBinary(16);
	div(16);
	decToBinary(15);
	div(15);
	return 0;
}
