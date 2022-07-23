#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

int	check_error(int argc)
{
	char	*error;

	if (argc <= 1)
	{
		error = "File name missing.\n";
		write(2, error, ft_strlen(error));
		return (1);
	}
	if (argc >= 3)
	{
		error = "Too many arguments.\n";
		write(2, error, ft_strlen(error));
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
    char    *line;
    int     fd;
	int		error;

    error = check_error(argc);
    if (error)
		return (1);
    fd = open(argv[1], O_RDONLY);
    line = "";
    while (line != NULL)
    {
        line = get_next_line(fd);
        if (line) {
            printf("%s", line);
            free(line);
        }
    }
    close(fd);
}