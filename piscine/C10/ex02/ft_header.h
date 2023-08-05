#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libgen.h>
# include <errno.h>
# include <string.h>

#define BUFF_SIZE 30

typedef struct s_Options
{
	int c;
	int argc;
	int	file_count;
	char **files;
} t_Options;


void    ft_putchar(char c);
void    ft_putstr(char *str);
void	ft_putstr_nl(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_strlistlen(char **arr);
char	*ft_strcpy_cont(char *dest, char *src);
void	print_error_msg(char *file);

int		count_newlines(char *str);
int		*get_newlines_pos(char *str,int newlines);

t_Options	*init_opt(int argc);
void		free_opt(t_Options *t_opt);
t_Options	*parse_opt(t_Options *t_opt, char *argv[], char **files_ptr);


int		get_file_size(char *filename);
void	display_last_byte(char *file, int last_byte);
void	display_file(char *file);
char	*read_txtfile(char *file,int fd);
void	display_last(char *file,int n);
void 	ft_foreach(char **files,int last,void (*f)(char*,int));
void	std_input();

#endif
