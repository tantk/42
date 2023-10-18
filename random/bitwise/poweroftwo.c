#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	return ((n & (n-1)) == 0);
}

int main()
{
	int a = 125;
	int b = 256;
	int c = 64;
	int d = 808;
	int e = 15596;
	printf("is %d power of 2? %d \n",a,is_power_of_2(a));
	printf("is %d power of 2? %d \n",b,is_power_of_2(b));
	printf("is %d power of 2? %d \n",c,is_power_of_2(c));
	printf("is %d power of 2? %d \n",d,is_power_of_2(d));
	printf("is %d power of 2? %d \n",e,is_power_of_2(e));
}

/*
   applying n & n - 1 == 0
   using some examples:
   a = 125, binary format = 1111101
   a - 1 = 124,binary fmt = 1111100
   AND operator applied   = 1111100
   not equals to zero. its not power of 2

   b=256, binary format   = 100000000
   b-1=255, binary format = 011111111
   AND operator applied   = 000000000
   hence equals to zero and considered as power of 2

   c = 64, binary format  = 1000000
   c-1=61, binary format  = 0111111
   AND operator applied   = 0000000

   d =808 binary format   = 1100101000
   d-1=807 binary format  = 1100100111
   AND operator applied   = 1100100000
   not equals zero.

   e=15596 binary format  = 11110011101100
   e=15595 binary format  = 11110011101011
   AND operator applied   = 11110011101000
   not equals zero
   */
