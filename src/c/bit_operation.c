#define setbit(num,k) (num | (1<<k))
#define clearbit(num,k) (num & ~(1<<k))
#define togglebit(num,k) (num ^(1<<(k-1)))
#define SIZEOF(a) ((char*)(&a+1)-(char*)&a)
//number is 2^n
#define power2n(num) num & (num-1)
//to-do another methods of 2^n
// middle noe of linkedlist
//add @beging of linkrd list
//plaindrom of mumber


