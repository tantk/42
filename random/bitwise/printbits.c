#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int		one_zero(int i)
{
	if (i)
		return 1;
	else
		return 0;
}

int		write_one_zero(int i)
{
	if (i)
		write(1,"1",1);
	else
		write(1,"0",1);
}
void	print_bits(unsigned char octet)
{
	// For learning to print bits using masking
	// 128 is 0b10000000 in binary,
	int a = 0b10000000;
	// 64
	int b = 0b01000000;
	// 32
	int c = 0b00100000;
	// 16
	int d = 0b00010000;
	// 8
	int e = 0b00001000;
	// 4
	int f = 0b00000100;
	// 2
	int g = 0b00000010;
	// 1
	int h = 0b00000001;

	// visualizing
	printf("1:%d0000000\n",one_zero(a&octet));
	printf("2:0%d000000\n",one_zero(b&octet));
	printf("3:00%d00000\n",one_zero(c&octet));
	printf("4:000%d0000\n",one_zero(d&octet));
	printf("5:0000%d000\n",one_zero(e&octet));
	printf("6:00000%d00\n",one_zero(f&octet));
	printf("7:000000%d0\n",one_zero(g&octet));
	printf("8:0000000%d\n",one_zero(h&octet));

	//for exam
	int mask = 128;
	while(mask)
	{
		write_one_zero(mask & octet);
		mask = mask >> 1;
	}
}

int	main()
{
	int a = 124;
	int b = 49;
	int c = 64;
	printf("First example %d :\n",a);
	print_bits(a);
	printf("\n");
	printf("Second example %d : \n",b);
	print_bits(b);
	printf("\n");
	printf("Third example %d : \n",c);
	print_bits(c);
}
