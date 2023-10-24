#include  <stdio.h>

void print_bin(unsigned char value)
{
    for (int i = sizeof(char) * 7; i >= 0; i--)
        printf("%d", (value & (1 << i)) >> i );
    putc('\n', stdout);
}

int main()
{
	print_bin(32 << 1);
	print_bin(64);
	print_bin(89);
	print_bin(89 << 1);
	print_bin(89 >> 1);
	print_bin(32 ^ 189);
	printf("%d\n",32);
	printf("%d\n",32);
	printf("%d\n",32&189);

}
