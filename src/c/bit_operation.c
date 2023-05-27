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
// bit twiddle hacks-http://graphics.stanford.edu/~seander/bithacks.html
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
int find_bit_pattern(void *memory_region, int msize, unsigned int bit_pat, int bit_pat_size){
    if (NULL == memory_region){
        return 0;
    }
    unsigned int mask = (1<<bit_pat_size)-1;
    unsigned int window = 0;
    unsigned int mem_shift_data = 0;
    unsigned int carry =0;
    unsigned int byte_index =0;
    unsigned int j = 0;
    unsigned int count = 0;
    unsigned int * memory = (int *)memory_region;
    printf("memory-%d: %X\n",0,((memory[0])));
    printf("memory-%d: %X\n",1,((memory[1])));
  
    for(int i =0; i <msize*8;i++){
       printf("memory-%d: %X:\t",byte_index,((memory[byte_index])));
	   byte_index = i/(8*sizeof(int));
	   //bit_shift_width = (i%(sizeof(int)*8);
	   if ((i%(sizeof(int)*8)) > ((8*sizeof(int)) - bit_pat_size)){
		   carry = mem_shift_data;
		   printf("carry %d Skip\n",carry);
		   continue;
	   }
	   mem_shift_data= (((memory[byte_index]))>>(i%(sizeof(int)*8)));
	   if(carry){
		   window = carry | (mem_shift_data <<(bit_pat_size + j -1) & mask) ;
		   j++;
		   carry = carry>>1;
	   }else{
		   window = mem_shift_data & mask;
		   j = 0;
	   }
	   if(window == bit_pat){
	       count++;
	   }
       printf("byte_index %d  window-%d:%X carry: %X bit_pat: %X count:%d\n", byte_index,i,window,carry,bit_pat,count);
    }
	return 0;
}

void slidingBitWindow(unsigned int num, int windowSize) {
    unsigned int mask = (1 << windowSize) - 1;  // Create a mask for the window size
    unsigned int window = 0;//num & mask;  // Initialize the window with the first bits
    
    printf("maks %x Window 1: %u\n",mask, window);

    for (int i = 0 ; i < sizeof(unsigned int) * 8; i++) {
        window = (num>>i) & mask;
        
        printf("window-%d: %x\n",i, window);
        
        
    }
}

int main() {
    //double num = 0b0101010101010101010101010101010101010101101011110010101010000000;
    int num[2] ={0x55555555,0x55AF2A80};
    int windowSize = 3;

    //slidingBitWindow(num, windowSize);
    find_bit_pattern(&num,8,0xF,4);
    

    return 0;
}

struct uart
   {
      unsigned baud : 3;
      unsigned parity : 2;
      unsigned unused : 2;
      unsigned interrupt_enable : 1;
   };

unsigned *char dev_reg = (unsigned char *)0x80000000;
class uart
   {
      unsigned char* port_address;
   public:
      uart(unsigned addr)
      {
         port_address = (unsigned char*)addr;
      }
      void set_parity(unsigned parity)
      {
         *port_address |= (parity << 3);
      }
   };

  
#if 0
void main()
{
	 uart myuart(0x8000000);
         myuart.set_parity(2);
   
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
