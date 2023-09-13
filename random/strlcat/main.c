#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t ft_strlcat(dst, src, siz)
	char *dst;
	const char *src;
	size_t siz;
{
	register char *d = dst;
	register const char *s = src;
	register size_t n = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}
int main(void)
{
    char dst[10] = "Hello, ";
    const char *source = "world!";
    size_t result = ft_strlcat(dst, source, sizeof(dst));
    printf("%s, result size is %d",dst,(int)result);
}
