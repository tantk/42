#include "ft_header.h"
#include <stdio.h>
//never handle std input and norm
int main(int argc, char *argv[])
{
	t_Options *opt;

	opt = init_opt(argc);
	opt	= parse_opt(opt, argv, opt->files);
	if (opt->c > 0)
		ft_foreach(opt->files,opt->c,&display_last_byte);
	else
		ft_foreach(opt->files,10,&display_last);
	if (opt)
		free_opt(opt);
}
