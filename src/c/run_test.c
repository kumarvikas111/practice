#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_array(int a[],int n){
	int i = 0;
	for(i=0;i<n;i++){
		printf("%c",a[i]);
	}
	printf("\n");
}

static int add(int a, int b){
	return (a+b);
}

int main(){

//code is for dynamic array.
	int n; 
	scanf("%d",&n);
	int A[n];
	A[9] = 45;
	int *iptr = (int *) malloc(sizeof(int)*n);
	if(iptr == NULL){
		printf("Error: memory has not been allocated\n");
		return -1 ;
	}
	printf("%d\n",A[9]);

	
// code is for plaindrom	
/*	int a = 1221;
	char buf[100];
	sprintf(buf,"%d",a);
	int len = strlen(buf);
	printf("%s length:%d\n",buf,len);
	int i = 0,j = len-1;
	while(i<j){
		printf("buf[%d]=%c\tbuf[%d]=%c\n",i,buf[i],j,buf[j]);
		if(buf[i++]!=buf[j--]){
			printf("not equal\n");
			
		}
	}*/
	printf("done.\n");
	return 0;
}
// 1 -> success
// 0 -> fail
int ispalindrom(int num) {
	char buf[100] = {0};
	sprintf(buf,"%d",num);
	int i=0,j=0,len=0;
	len = strlen(buf)-1;
	while(i<j){
		if(buf[i++]!=buf[j++]){
			printf("Given number is not plaindrom\n");
			return 0;
		}
	}
	return 1;
}
