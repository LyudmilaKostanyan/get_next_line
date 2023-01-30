#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = -1;
	c %= 256;
	if (c == 0)
		return (ft_strlen(str) - 1);
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

char	*ft_strdup(char *s, int start, int j)
{
	char	*str;
	int		i;

	str = malloc(j + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < j)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_strlen(s1))
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
