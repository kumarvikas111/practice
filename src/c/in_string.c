#include <stdio.h>

char * str_revese(char * src){

	if(NULL == src) return NULL;
	char * start = src;
	char * left = src;
	char  ch;
	while(*src++){
		src -=2;
	}

	while(left < src){
		ch = *left;
		*left = *src;
		*src = ch;
		src--;
		left++;
	}
	return start
}
