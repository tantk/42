#include "libft.h"
#include <stdio.h>

int main(void)
{
    char s[] = "    hello   world      42 sg test tes     ";
    char **result;

    result = ft_split(s,' ');

    while(*result)
        printf("--%s\n",*result++);

}
