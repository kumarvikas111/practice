#include <stdio.h>

int max_four(int a,int b, int c, int d){
	int arr[2];
	arr[0]=a;
	arr[1]=b;
	bool f = (arr[0] -arr[1] + abs(arr[0] - arr[1]));
	swap(arr[0],arr[!f])

	arr[1] = c;
	bool f = (arr[0] -arr[1] + abs(arr[0] - arr[1]));
	swap(arr[0],arr[!f])

	arr[1] = d;
	bool f = (arr[0] -arr[1] + abs(arr[0] - arr[1]));
	swap(arr[0],arr[!f])

	return arr[0];
}
