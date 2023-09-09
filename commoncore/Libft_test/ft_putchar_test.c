#include "libft_test.h"

typedef struct s_test
{
	char *desc;
	char c;
	char *expected;
} t_test;

void    ft_putchar_test(void)
{
    	t_test tests[] = {
	    {.desc = "ft_putchar('c')",
	     .c = 'c',
	     .expected = "c"},
	    {.desc = "ft_putchar('x')",
	     .c = 'x',
	     .expected = "x"},
	    {.desc = "ft_putchar(' ')",
	     .c = ' ',
	     .expected = " "},
	    {.desc = "ft_putchar('\\n')",
	     .c = '\n',
	     .expected = "\n"},
	    {.desc = "ft_putchar('\\t')",
	     .c = '\t',
	     .expected = "\t"},
	    {.desc = "ft_putchar('\\0')",
	     .c = '\0',
	     .expected = "\0"},
	    {.desc = "ft_putchar('\\xFF')",
	     .c = '\xFF',
	     .expected = "\xFF"},
	    // Add more test cases here
	};

   	int count = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < count)
    {
        printf("%s , input: ",tests[i].desc);
        ft_putchar(tests[i].c);
        printf("expected: %s\n",tests[i].expected);
        i++;
    }
}
