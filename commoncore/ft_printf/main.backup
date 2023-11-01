#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

int	main(void)
{
	char *str = "bonjour";
	printf("test 1:\n");
	printf("%c%sl%co, %s.\nI am %d years old.\n", 72, "e", 'l', "world", 31);
	ft_printf("%c%sl%co, %s.\nI am %d years old.\n", 72, "e", 'l', "world", 31);
	printf("test 2:\n");
	printf("at the address %p, the string %s is stored\n", str, str);
	ft_printf("at the address %p, the string %s is stored\n", str, str);
	printf("test 3:\n");
	printf("  ||  %i\n", printf(" NULL %s NULL", (char *)NULL));
	printf("  ||  %i\n", ft_printf(" NULL %s NULL", (char *)NULL));
  	printf("test 4:\n");
	printf("  ||  %i\n", ft_printf("%p", NULL));
  	printf("  ||  %i\n", printf("%p", NULL));
	printf("test 5:\n");
	printf("%p %p \n", (void *) (void *) 0 , (void *)0);
	ft_printf("%p %p \n", (void *) (void *) 0 , (void *)0);
	printf("test 6:\n");
	printf("  ||  %i\n", ft_printf(" %x ", 0));
	printf("  ||  %i\n", printf(" %x ", 0));
	printf("test 7:\n");
	ft_printf("  %%%%  \n");
	printf("  %%%%  \n");
	printf("test 8:\n");
	printf("  ||  %i\n", ft_printf("\x01\x02\a\v\b\f\r"));
	printf("  ||  %i\n", printf("\x01\x02\a\v\b\f\r"));
	printf("test 9:\n");
	printf("  ||  %i\n", ft_printf(""));
	printf("  ||  %i\n", printf(""));
	printf("test 10:\n");
	printf("  ||  %i\n", ft_printf("%%c"));
	printf("  ||  %i\n", printf("%%c"));
	printf("test 11:\n");
	printf("  ||  %i\n", ft_printf("%%%%%%"));
	printf("  ||  %i\n", printf("%%%%%%"));
	printf("test 12:\n");
	printf("  ||  %i\n", ft_printf("%%%c", 'x'));
	printf("  ||  %i\n", printf("%%%c", 'x'));
	printf("test 13:\n");
	printf("  ||  %i\n", ft_printf("%cc%cc%c", 'a', '\t', 'b'));
	printf("  ||  %i\n", printf("%cc%cc%c", 'a', '\t', 'b'));
	printf("test 14:\n");
	printf("  ||  %i\n", ft_printf("%s", (char *)NULL));
	printf("  ||  %i\n", printf("%s", (char *)NULL));
	printf("test 15:\n");
	printf("  ||  %i\n", ft_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&"));
	printf("  ||  %i\n", printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&"));
	printf("test 16:\n");
	printf("  ||  %i\n", ft_printf(" %s", "can it handle \t and \n?"));
	printf("  ||  %i\n", printf(" %s", "can it handle \t and \n?"));
	printf("test 17:\n");
	printf("  ||  %i\n", ft_printf("%u", UINT_MAX));
	printf("  ||  %i\n", printf("%u", UINT_MAX));
	printf("test 18:\n");
	printf("  ||  %i\n", ft_printf("%u", -6000023));
	printf("  ||  %i\n", printf("%u", -6000023));
	printf("test 19:\n");
	printf("  ||  %i\n", ft_printf("%X", UINT_MAX));
	printf("  ||  %i\n", printf("%X", UINT_MAX));
	printf("test 20:\n");
	printf("  ||  %i\n", ft_printf("%pp", (void *)LONG_MAX + 423856));
	printf("  ||  %i\n", printf("%pp", (void *)LONG_MAX + 423856));
	printf("test 21:\n");
	printf("  ||  %i\n", ft_printf("%pp", (void *)INT_MAX));
	printf("  ||  %i\n", printf("%pp", (void *)INT_MAX));
	printf("test 22:\n");
	printf("  ||  %i\n", ft_printf("%pp", (void *)0));
	printf("  ||  %i\n", printf("%pp", (void *)0));
	printf("test 23:\n");
	printf("  ||  %i\n", ft_printf("0x%p-", (void *)ULONG_MAX));
	printf("  ||  %i\n", printf("0x%p-", (void *)ULONG_MAX));
	printf("test 24:\n");
	printf("  ||  %i\n", ft_printf("%p", (void *)-14523));
	printf("  ||  %i\n", printf("%p", (void *)-14523));
	printf("test 25:\n");
	printf("  ||  %i\n", ft_printf("%p", ""));
	printf("  ||  %i\n", printf("%p", ""));
	printf("test 25:\n");
	printf("  ||  %i\n", printf("%s %s %s\n", "one", "two"));

	printf("  ||  %i\n", ft_printf("%s %s %s\n", "one", "two"));
}
