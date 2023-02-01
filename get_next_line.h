#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strdup(char *s, int start, int j);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*get_next_line(int fd);

#endif