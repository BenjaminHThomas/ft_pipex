/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:36:02 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 19:25:18 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	append_cmd(t_pipe *data, char **split)
{
	int	i;

	i = 0;
	while (data->cmd_args[i])
		i++;
	data->cmd_args[i] = split;
}

char	**get_split(char *cmd)
{
	char	*temp;
	char	**cmd_split;

	temp = clean_cmd(cmd);
	if (!temp)
	{
		perror("Memory allocation error: cannot split command");
		return (NULL);
	}
	cmd_split = split_cmd(temp);
	free(temp);
	if (!cmd_split)
	{
		perror("Memory allocation error: cannot split command");
		return (NULL);
	}
	return (cmd_split);
}

/*
* Removes escape characters
*/
char	*clean_cmd(char *cmd)
{
	char	*cleaned_cmd;
	int		i;
	int		j;

	if (!cmd)
		return (NULL);
	cleaned_cmd = ft_calloc(ft_strlen(cmd) + 1, 1);
	if (!cleaned_cmd)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\\')
			i++;
		else
		{
			cleaned_cmd[j] = cmd[i];
			j++;
			i++;
		}
	}
	return (cleaned_cmd);
}
