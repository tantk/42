#include <stdio.h>




size_t word_count(char const *s, char c)
   {
       size_t  words;
    char    *match;
       char    *s_ptr;
    s_ptr = s;
       words = 0;
       while (*s_ptr)
       {
           if (*s_ptr == c)
           {
               while(*s_ptr == c)
                   s_ptr++;
           }
           else
           {
               while(*s_ptr != c)
                   s_ptr++;
               words++;
            }
       }
       return (words);
   }

int main(void)
{
    char test1[] = " this is a number  hmm   test ha  ";
    printf("%d", (int)word_count(test1,' '));

}
