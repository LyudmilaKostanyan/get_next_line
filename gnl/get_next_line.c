#include "get_next_line.h"

static char	*f1(int fd)
{

	while (1)
	{
		if (f(s))
	}
}

char *get_next_line(int fd)
{
	unsigned	read_size;
	unsigned	i;
	unsigned	j;
	static char	*s;
	char		*s1;
	char		*str;
	char		*tmp;


	s1 = malloc(BUFFER_SIZE + 1);
	read_size = read(fd, s1, BUFFER_SIZE);
	s1[read_size] = 0;
	if (s)
	{
		tmp = ft_strjoin(s, s1);
		free()
	}
	else
	{
		s = ft_strdup(s1, 0, ft_strlen(s1))
		free(s1);
	}
	i = ft_strchr(s, '\n') + 1;
	if (i != -1)
	{
		str = ft_strdup(s, 0, i);
		tmp = ft_strdup(s, i, read_size - i - 1);
		free(s);
		s = ft_strdup(tmp, i, read_size - i - 1);
		free(tmp);
	}
	// s[read_size] = 0;
	// printf("r = %u\n", read_size);
	// if (!f(s))
	// {
	// 	while (!f(s))
	// 	{
	// 		read_size = read(fd, s, BUFFER_SIZE);
	// 		// printf("r1 = %u\n", read_size);
	// 		s[read_size] = 0;
	// 	}
	// }

	return (str);
}
#include <fcntl.h>
int main()
{
	int fd = open("./mr.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s", s);
	// free(s);
	close(fd);
	int fd1 = open("./mr.txt", O_RDONLY);
	char *str = get_next_line(fd1);
	printf("%s", str);
	// free(str);
	close(fd1);
	fd1 = open("./mr.txt", O_RDONLY);
	str = get_next_line(fd1);
	printf("%s", str);
	// free(str);
	close(fd1);
}