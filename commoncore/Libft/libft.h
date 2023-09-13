/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:47:12 by titan             #+#    #+#             */
/*   Updated: 2023/09/13 02:57:30 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
//libc

int ft_isupper(int c);
int ft_islower(int c);
int ft_isalpha(int c);
int	ft_isdigit(char c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t  ft_strlen(const char *str);
void    *ft_memset(void *s, int c, size_t n);
void    *ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest,const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

int     ft_atoi(char *str);
void    ft_putchar(char c);

//part 2 additional function

char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void    ft_striteri(char *s, void (*f)(unsigned int, char*));
void    ft_putchar_fd(char c,int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);

