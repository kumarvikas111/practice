#include <stdio.h>

#define SETBIT(num, k) (num | (1 << k))
#define CLEARBIT(num, k) (num & ~(1 << k))
#define TOGGLEBIT(num, k) (num ^ (1 << k))
#define SIZEOF(a) ((char *)(&a + 1) - (char *)&a)
//number is 2^n
#define POWER2N(num) (num & (num - 1)) // returns 0 for 2^n

/*
 *Get mask : it gives the mask for ith to jth position.
 */

#define GET_MASK(M, N) ((1U << ((M) - (N))) - 1)

/* 
 * Swap bits from i to j position for n consecative bits for given number.
 * i,j: position from where it start swapping.
 * n  : number of consecative bits.
 * b  : Given number
 * r  : result to return.
 * x  : temp varriable.  
 */

unsigned int swap_bits(unsigned int b, int i, int j, int n)
{

	unsigned int mask = ((1U << n) - 1);
	//printf("mask:0x%X\n", mask);
	unsigned int x = (((b >> i) ^ (b >> j)) & mask);
	//printf("x: 0x%X\n", x);
	unsigned int r = b ^ ((x << i) | (x << j));

	return r;
}
/*
 * Reverse bits: 
 */

int reverse_bits(unsigned int num, int from_bit, int to_bit)
{

	int i = 0;
	int mask = GET_MASK(to_bit,from_bit);
	printf("mask: %X\n",mask);
	unsigned int res = 0;
	for (i = from_bit; i <= to_bit -1 ; i++)
	{
		if (num & (1 << i))
		{
			res |= (1UL << ((to_bit -1)-i));
		}
	}
	//printf("%d res %X\n",__LINE__,res);
	return (res << from_bit) |(~(mask << from_bit) & num);
}

void diplay_binary(int a)
{
	if (a > 1)
	{
		diplay_binary(a);
	}
	printf("%d", a % 2);
}
#if 0
void main()
{
	unsigned int n = 0xABCD98EF;
	
	printf("%d n: 0x%X\n", __LINE__, n);
	int res = swap_bits(n, 0, 24, 8);
	printf("res: 0x%X\n", res);
	res = swap_bits(n, 8, 16, 8);
	printf("res: 0x%X\n", res);
	res = reverse_bits(n, 0, 27);
	printf("%d res: 0x%X\n", __LINE__, res);
	return;
}
#endif