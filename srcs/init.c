/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:41:17 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 19:24:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	get_paths(t_pipe *data)
{
	int		i;
	char	*path;

	i = 0;
	while (i < (data->ac - 3))
	{
		path = find_path(data->envp, data->cmd_args[i][0]);
		if (!path)
		{
			perror("Error: command not found\n");
			return (1);
		}
		append_path(data, path);
		i++;
	}
	return (0);
}

static int	get_cmds(t_pipe *data)
{
	int		i;
	char	**cmd;

	i = 2;
	while (i < (data->ac - 1))
	{
		cmd = get_split(data->av[i]);
		if (!cmd)
		{
			perror("Error: could not split command.\n");
			return (1);
		}
		append_cmd(data, cmd);
		i++;
	}
	return (0);
}

static int	init_pipes(t_pipe *data)
{
	int	i;
	int	limit;

	limit = data->ac - 2;
	data->pipes = (int **)ft_calloc(sizeof(int *), limit + 1);
	if (!data->pipes)
		return (1);
	i = 0;
	while (i < limit)
	{
		data->pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (!data->pipes[i])
			return (1);
		if (pipe(data->pipes[i]) == -1)
		{
			perror("Error: could not open pipe.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	init(t_pipe *data, int ac, char **av, char **envp)
{
	data->envp = envp;
	data->av = av;
	data->ac = ac;
	data->cmd_count = ac - 3;
	data->cmd_args = ft_calloc(sizeof(char **), data->cmd_count + 1);
	if (!data->cmd_args)
		return (1);
	data->cmd_paths = ft_calloc(sizeof(char *), data->cmd_count + 1);
	if (!data->cmd_paths)
		return (1);
	data->fdinfile = open(av[1], O_RDONLY);
	if (data->fdinfile == -1)
		return (1);
	data->fdoutfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fdoutfile == -1)
		return (1);
	if (get_cmds(data) || get_paths(data) || init_pipes(data))
		return (1);
	return (0);
}
