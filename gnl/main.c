#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(){
	int		fd;
	char	*s;

	fd = open("aa.txt", O_RDONLY);

	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		printf("%s", s);
		free(s);
	}
	close (fd);
}
