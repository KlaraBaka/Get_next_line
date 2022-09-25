/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:47:51 by radriann          #+#    #+#             */
/*   Updated: 2022/09/25 20:15:51 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_count_word(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(left_str)
					+ ft_strlen(buff)) + 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (left_str[++i] != '\0')
			new_str[i] = left_str[i];
	while (buff[j] != '\0')
		new_str[i++] = buff[j++];
	new_str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (new_str);
}

char	*ft_left_str(int fd, char *string)
{
	char	*buff;
	int		was_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	was_read = -42;
	while (!ft_count_word(string) && was_read != 0)
	{
		was_read = read(fd, buff, BUFFER_SIZE);
		if (was_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[was_read] = '\0';
		string = ft_strjoin(string, buff);
	}
	free(buff);
	return (string);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!new_str)
		return (NULL);
	i++;
	while (left_str[i])
		new_str[j++] = left_str[i++];
	new_str[j] = '\0';
	free(left_str);
	return (new_str);
}
