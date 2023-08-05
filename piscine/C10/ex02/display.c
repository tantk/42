#include "ft_header.h"

int	get_file_size(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        // handle error
        return -1;
    }

    int file_size = 0;
    char buffer[1024];  // or some other suitable block size
    int bytes_read;
	bytes_read = read(fd, buffer, sizeof(buffer));
    while (bytes_read > 0)
	{
        file_size += bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer));
    }

    close(fd);

    return file_size;
}

int	skip_byte(int fd, int bytes_skip, int file_size)
{
	char buffer[BUFF_SIZE];
	int bytes_read;

	while (bytes_skip > 0)
	{
		if (bytes_skip > (int) sizeof(buffer))
			bytes_read = read(fd,&buffer, sizeof(buffer));
		else
			bytes_read = read(fd,&buffer, bytes_skip);
		bytes_skip -= bytes_read;
		file_size -= bytes_read;
	}
	return file_size;
}

void	display_last_byte(char *file, int last_byte)
{
	int 			file_size;
	long			bytes_read;
	unsigned char 	buffer[BUFF_SIZE];
	int				fd;

	file_size = get_file_size(file);
	if (file_size >= last_byte)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			print_error_msg(file);
		else
		{
			bytes_read = skip_byte(fd, file_size - last_byte, file_size);
			while (bytes_read)
			{
				bytes_read = read(fd, &buffer, sizeof(buffer) - 1);
				buffer[bytes_read] = '\0';
				ft_putstr((char *)buffer);
			}
			close(fd);
		}
	}
	else
		display_file(file);
}

void	display_file(char *file)
{
	long			bytes_read;
	unsigned char 	buffer[BUFF_SIZE];
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error_msg(file);
	else
	{
		bytes_read = read(fd, &buffer, sizeof(buffer) - 1);
		while (bytes_read)
		{
			buffer[bytes_read] = '\0';
			ft_putstr((char *)buffer);
			bytes_read = read(fd, &buffer, sizeof(buffer) - 1);
		}
		close(fd);
	}
}

char	*read_txtfile(char *file,int fd)
{
	long			bytes_read;
	unsigned char	buffer[BUFF_SIZE];
	char			*read_file;
	char			*read_st;

	read_st = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error_msg(file);
	else
	{
		read_file = (char *) malloc((get_file_size(file) + 1) * sizeof(char));
		read_st = read_file;
		bytes_read = read(fd, &buffer, sizeof(buffer) - 1);
		while (bytes_read)
		{
			buffer[bytes_read] = '\0';
			read_file = ft_strcpy_cont(read_file, (char *)buffer);
			bytes_read = read(fd, &buffer, sizeof(buffer) - 1);
		}
		close(fd);
		*read_file = '\0';
	}
	return read_st;
}

void	display_last(char *file, int n)
{
	char	*read_file;
	int		*newline_pos;
	int		newline_count;

	read_file = read_txtfile(file, 0);
	newline_count = count_newlines(read_file);
	newline_pos = get_newlines_pos(read_file,newline_count);
	if (n > newline_count)
		display_file(file);
	else
	{
		ft_putstr_nl(read_file + newline_pos[newline_count-n-1]);
		free(newline_pos);
	}
}

void	ft_foreach(char **files,int last, void (*f)(char*, int))
{
	int files_count;

	files_count = ft_strlistlen(files);
	if (files_count > 1)
	{
		while(*files)
		{
			ft_putstr("==> ");
			ft_putstr(*files);
			ft_putstr(" <==\n");
			f(*files,last);
			if (files[1])
				ft_putchar('\n');
			files++;
		}
	}
	else
		f(*files,last);
}

void	std_input()
{
	long	bytes_read;
	unsigned char buffer[BUFF_SIZE];

	bytes_read = read(0, &buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ft_putstr((char *)buffer);
		bytes_read = read(0, &buffer, sizeof(buffer) - 1);
	}
	if (bytes_read == -1)
	{
		print_error_msg("Standard_input");
		return;
	}
}

