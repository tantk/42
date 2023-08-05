#include "ft_header.h"

t_Options *init_opt(int argc)
{
	t_Options *opt;
	int idx;

	idx = 0;
	opt = (t_Options *)malloc(sizeof(t_Options));
	if (!opt)
		return NULL;
	opt->c = -1;
	opt->argc = argc;
	opt->file_count = 0;
	opt->files = (char **)malloc(sizeof(char *) * argc);
	if (!opt->files)
	{
		free(opt);
		return NULL;
	}
	while (idx < argc)
		opt->files[idx++] = 0;
	return opt;
}

void	free_opt(t_Options *t_opt)
{
	char **files = t_opt->files;
	int idx;

	idx = 0;
	if (files)
	{
		while (idx < t_opt->argc)
		{
			free(files[idx]);
			idx++;
		}
	}
	free(files);
	free(t_opt);
}

t_Options *parse_opt(t_Options *t_opt, char *argv[], char **files_ptr)
{
	argv++;
	while (*argv)
	{
		if (!ft_strcmp(*argv,"-c"))
		{
			if (argv[1])
			{
				t_opt->c = ft_atoi(argv[1]);
				argv += 2;
			}
			else
			{
				t_opt->c = 0;
				return t_opt;
			}
		}
		else
		{
			*files_ptr++ = ft_strdup(*argv++);
			t_opt->file_count++;
		}
	}
	return t_opt;
}
