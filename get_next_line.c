#include "get_next_line.h"

static void	ffree(char *s)
{
	free(s);
	s = NULL;
}

static void	sjoins(char *s, char *s1)
{
	char	*tmp;

	tmp = ft_strjoin(s, s1);
	ffree(s);
	s = ft_strdup(tmp, 0, ft_strlen(tmp));
	ffree(tmp);
}

static void	sdups(char **s, char **str, int i)
{
	char	*tmp;

	*str = ft_strdup(*s, 0, i + 1);
	tmp = ft_strdup(*s, i + 1, ft_strlen(*s) - i);
	*s = ft_strdup(tmp, 0, ft_strlen(tmp));
	ffree(tmp);
}

static char	*infinity(int fd)
{
	int			read_size;
	int			i;
	static char	*s;
	char		s1[BUFFER_SIZE + 1];
	char		*str;

	while (1)
	{
		read_size = read(fd, s1, BUFFER_SIZE);
		if (read_size == 0)
			return (NULL);
		s1[read_size] = 0;
		if (s)
			sjoins(s, s1);
		else
			s = ft_strdup(s1, 0, ft_strlen(s1));
		i = ft_strchr(s, '\n');
		if (i > -1)
		{
			sdups(&s, &str, i);
			break ;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;

	if (read(fd, 0, 0) < 0)
		return (NULL);
	str = infinity(fd);
	return (str);
}
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("./mr.txt", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// system ("leaks ./a.out");
// 	close(fd);
// }