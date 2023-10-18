#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char	*a = malloc(sizeof(char));
	char	*b = malloc(sizeof(char));
	char	*c = malloc(sizeof(char));
	int		*d = malloc(sizeof(int));
	int		*e = malloc(sizeof(int));
	int		*f = malloc(sizeof(int));

	*a = 100;
	*b = 'b';
	*c = 'c';
	*d = 1;
	*e = 2;
	*f = 3;
	printf("address: %p ptr address %p, value : %c\n",a,&a,*a);
	printf("address: %p ptr address %p, value : %c\n",b,&b,*b);
	printf("address: %p ptr address %p, value : %c\n",c,&c,*c);
	printf("address: %p ptr address %p, value : %d\n",d,&d,*d);
	printf("address: %p ptr address %p, value : %d\n",e,&e,*e);
	printf("address: %p ptr address %p, value : %d\n",f,&f,*f);
}
