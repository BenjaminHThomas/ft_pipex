/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:00:56 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 17:50:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	append_path(t_pipe *data, char *path)
{
	int	i;

	i = 0;
	while (data->cmd_paths[i])
		i++;
	data->cmd_paths[i] = path;
}

static char	*is_callable(char *path, char *cmd)
{
	char	*executable;
	char	*temp;

	temp = ft_strjoin(path, "/");
	if (!temp)
		return (NULL);
	executable = ft_strjoin(temp, cmd);
	free(temp);
	if (!executable)
		return (NULL);
	if (access(executable, X_OK) == -1)
	{
		free(executable);
		executable = NULL;
	}
	return (executable);
}

/* When given a shell command like 'wc' it searches through the path
* to find the executable */
char	*find_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**split_path;
	char	*exec_path;

	i = -1;
	path = NULL;
	while (envp[++i] && !path)
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			path = envp[i];
	if (!path)
		return (NULL);
	path += 5;
	split_path = ft_split(path, ':');
	if (!split_path)
		return (NULL);
	i = -1;
	exec_path = NULL;
	while (split_path[++i] && exec_path == NULL)
		exec_path = is_callable(split_path[i], cmd);
	free_arr(split_path);
	if (!exec_path && access(cmd, X_OK) != -1)
		return (ft_strdup(cmd));
	return (exec_path);
}
