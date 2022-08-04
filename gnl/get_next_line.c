/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:20:10 by pmeising          #+#    #+#             */
/*   Updated: 2022/06/10 19:18:58 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// callocs new memory space for combined length of remainder and read_into
// Adds read_into to remainder.
static char	*ft_add_read_into(char *remainder, char *read_into)
{
	char	*new;
	int		i;
	int		k;
	int		len;

	len = (ft_strlen(remainder) + ft_strlen(read_into));
	new = ft_calloc((len + 1), 1);
	i = 0;
	if (new == NULL)
		return (NULL);
	while (remainder[i] != '\0')
	{
		new[i] = remainder[i];
		i++;
	}
	k = 0;
	while (read_into[k] != '\0')
	{
		new[i + k] = read_into[k];
		k++;
	}
	return (new);
}

// updating remainder and freeing input strings.

static char	*ft_join_free(char *remainder, char *read_into)
{
	char	*new;
	int		i;

	i = 0;
	if (remainder == NULL)
	{
		new = ft_calloc(BUFFER_SIZE + 1, 1);
		while (read_into[i] != '\0')
		{
			new[i] = read_into[i];
			i++;
		}
	}
	else
		new = ft_add_read_into(remainder, read_into);
	free(read_into);
	free (remainder);
	return (new);
}

// this is where I read into the buffer via while loop.
// checking if remainder has \n. -> return remainder;
// joining of remainder and read_into. Freeing input strings.

static char	*ft_read_from_file(int fd, char *remainder)
{
	char	*read_into;
	int		count;

	count = 1;
	if (remainder != NULL)
		if (ft_strchr(remainder, '\n') != NULL)
			return (remainder);
	while (count > 0)
	{
		read_into = ft_calloc(BUFFER_SIZE + 1, 1);
		count = read(fd, read_into, BUFFER_SIZE);
		if (count == -1 || count == 0)
		{
			free (read_into);
			if (count == 0)
				break ;
			else
				return (NULL);
		}
		remainder = ft_join_free(remainder, read_into);
		if (ft_strchr(remainder, '\n'))
			break ;
	}
	return (remainder);
}

// if statement checks for 1. scenario, in which there is no new line.
// 2. scenario, in which \n is the last character in the string.
// else (3.) scenario, in which there is more in the remainder than up to \n.

static char	*ft_update_remainder(char *remainder, int len)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = len;
	if (((len - 1) == (int)ft_strlen(remainder)) || (remainder[len] == '\0'))
	{
		free(remainder);
		return (NULL);
	}
	else
	{
		new = ft_calloc((ft_strlen(remainder) - len) + 2, 1);
		while (remainder[i] != '\0')
		{
			new[j] = remainder[i];
			i++;
			j++;
		}
	}
	free (remainder);
	return (new);
}

// read_into is the buffer size which temporarily stores the read string.
// remainder stores the left over string after reading it.
// return_string is the substring up to \n character which is being returned.
// l. 142 length of return_string. if \n found,
// len = ft_strchr(remainder, '\n') - remainder. if not,
// len = ft_strlen(remainder);
// l.144 doesn't free input string.
// l.145 updates remainder by callocing new memory. frees old remainder.
char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*return_string;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	remainder = ft_read_from_file(fd, remainder);
	if (remainder == NULL)
		return (NULL);
	len = ft_len(remainder);
	return_string = ft_substr(remainder, 0, len);
	remainder = ft_update_remainder(remainder, len);
	return (return_string);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*string;
// 	char	*file_name;

// 	file_name = "readfrom.c";
// 	i = 0;
// 	// printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
// 	fd = open(file_name, O_RDWR);
// 	if (fd == -1)
// 	{
// 		printf("open() failed.");
// 		return (0);
// 	}
// 	printf("File descriptor chosen: %d\n", fd);
// 	while (i < 20)
// 	{
// 		string = get_next_line(fd);
// 		printf("Return string: %s", string);
// 		i++;
// 		free(string);
// 	}
// 	if (close(fd) == -1)
// 	{
// 		printf("close() failed.");
// 		return (0);
// 	}
// }