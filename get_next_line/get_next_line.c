#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i = 0;
	if (!s)
		return(0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char *res = NULL;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_res = 0;
	static int	buffer_pos = 0;
	char		*line = NULL;
	char		temp[2];

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	
	while (1)
	{
		if (buffer_pos >= buffer_res)
		{
			buffer_res = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_res <= 0)
				break ;
		}
		temp[0] = buffer[buffer_pos++];
		temp[1] = '\0';
		line = ft_strjoin(line, temp);
		if (temp[0] == '\n')
			break ;
	}
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	fd = open("txt.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	close (fd);
	return 0;
}*/