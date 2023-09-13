#include <stdlib.h>
#include <stdio.h>
#include <string.h>
size_t ft_strlcpy(char * dst, const char * src, size_t maxlen) {
    const size_t srclen = strlen(src);
    if (srclen < maxlen) {
        memcpy(dst, src, srclen + 1);
    } else if (maxlen != 0) {
        memcpy(dst, src, maxlen - 1);
        dst[maxlen-1] = '\0';
    }
    return srclen;
}

 int main(void)
{
    char dst[5];
    const char *src = "Hello";
    
    size_t srclen = ft_strlcpy(dst, src, 6);
    printf("%s of len %d .\n",dst,(int)srclen);
}
