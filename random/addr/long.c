#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int arr[5] ={1,2,3,4,5};

	printf("address: %p\n",&arr);
	for (int i=0;i < 5;i++)
		printf("add %p , value: %d\n",&arr[i],arr[i]);
}
