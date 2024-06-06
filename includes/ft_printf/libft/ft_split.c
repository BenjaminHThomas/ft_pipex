/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:11:17 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/21 20:40:07 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdlib.h>
#include <string.h>*/

static char	**free_list(char **wlist)
{
	int	i;

	i = 0;
	while (wlist[i])
	{
		free(wlist[i]);
		i++;
	}
	free(wlist);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int	wcount;
	int	i;

	if (!s)
		return (0);
	wcount = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			wcount++;
		else if (s[i] != c && s[i - 1] == c)
			wcount++;
		i++;
	}
	return (wcount);
}

static char	*get_word(const char *s, int *start, char c)
{
	char	*word;
	int		i;
	int		end;

	end = *start;
	while (s[end] && s[end] != c)
		end++;
	i = 0;
	word = (char *)ft_calloc((end - *start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (*start < end)
	{
		word[i] = s[*start];
		i++;
		(*start)++;
	}
	return (word);
}

static char	**null_wlist(void)
{
	char	**wlist;

	wlist = malloc(sizeof(char *));
	if (!wlist)
		return (NULL);
	*wlist = NULL;
	return (wlist);
}

char	**ft_split(char const *s, char c)
{
	char	**wlist;
	int		start;
	int		i;

	if (!s)
		return (null_wlist());
	wlist = ft_calloc((count_words(s, c) + 1), sizeof(*wlist));
	if (!wlist)
		return (null_wlist());
	start = 0;
	i = 0;
	while (s[start])
	{
		while (s[start] == c && s[start])
			start++;
		if (!s[start])
			continue ;
		wlist[i] = get_word(s, &start, c);
		if (!wlist[i])
			return (free_list(wlist));
		i++;
	}
	return (wlist);
}
/*
#include <stdio.h>
int	main(void)
{;
	char	**wlist = ft_split("hello! ", ' ');
	int		i;

	i = 0;
	while (wlist[i])
	{
		printf("%s\n", wlist[i]);
		i++;
	}
	i = 0;
	while (wlist[i])
	{
		free(wlist[i]);
		i++;
	}
	free(wlist);
	return (0);
}*/
