
#define SETBIT(num,k) 		(num | (1<<k))
#define CLEARBIT(num,k) 	(num & ~(1<<k))
#define TOGGLEBIT(num,k) 	(num ^ (1<<k))
#define SIZEOF(a) 			((char*)(&a+1)-(char*)&a)
//number is 2^n
#define POWER2N(num) 		(num & (num-1))
//to-do another methods of 2^n



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
