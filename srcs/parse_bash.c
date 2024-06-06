/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:25:02 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 11:14:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/* Once it finds quotes in the bash command it stops counting */
static int	count_splits(char *cmd)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			count++;
			break ;
		}
		else if (cmd[i] == ' ' || cmd[i + 1] == '\0')
		{
			count++;
			while (cmd[i] == ' ' && cmd[i + 1] == ' ')
				i++;
		}
	}
	return (count);
}

static void	add_arg(char **cmdlist, char *split)
{
	int	i;

	i = 0;
	while (cmdlist[i])
		i++;
	cmdlist[i] = split;
}

static int	extract_quote(char **result, char *cmd, int *i)
{
	int		j;
	int		len;
	char	*temp;

	if (cmd[*i] != '\'' && cmd[*i] != '\"')
		return (0);
	j = ++(*i);
	len = ft_strlen(cmd);
	temp = ft_substr(cmd, *i, len - j - 1);
	if (!temp)
	{
		free_arr(result);
		return (1);
	}
	add_arg(result, temp);
	*i = len;
	return (0);
}

static int	extract_nonquote(char **result, char *cmd, int *i)
{
	int		j;
	char	*temp;

	j = *i;
	while (cmd[j] && (cmd[j] != '\'' || cmd[j] != '\"')
		&& cmd[j] != ' ')
		j++;
	if (j == *i)
		return (0);
	temp = ft_substr(cmd, *i, j - *i);
	if (!temp)
	{
		free_arr(result);
		return (1);
	}
	add_arg(result, temp);
	*i = j + 1;
	return (0);
}

char	**split_cmd(char *cmd)
{
	char	**result;
	int		i;
	int		len;

	if (!cmd)
		return (NULL);
	len = ft_strlen(cmd);
	result = (char **)ft_calloc(count_splits(cmd) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (cmd[i] == ' ')
			i++;
		if (extract_quote(result, cmd, &i))
			return (NULL);
		if (extract_nonquote(result, cmd, &i))
			return (NULL);
	}
	return (result);
}
