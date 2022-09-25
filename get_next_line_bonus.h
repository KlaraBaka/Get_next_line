/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:37:33 by radriann          #+#    #+#             */
/*   Updated: 2022/09/25 20:11:56 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1000
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_left_str(int fd, char *string);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *string);
char	*get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
int		ft_count_word(char *string);

#endif