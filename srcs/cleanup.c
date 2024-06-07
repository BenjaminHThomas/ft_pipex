/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:05:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 19:21:42 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_mem(t_pipe *data)
{
	int	i;

	i = 0;
	if (data->cmd_paths)
		free_arr(data->cmd_paths);
	while (i < data->cmd_count)
	{
		free_arr(data->cmd_args[i]);
			i++;
	}
	free(data->cmd_args);
	if (data->pipes)
	{
		i = -1;
		while (data->pipes[++i])
			free(data->pipes[i]);
		free(data->pipes);
	}
}

void	close_fds(t_pipe *data)
{
	int	i;
	int	y;

	if (data->fdinfile >= 0)
		close(data->fdinfile);
	if (data->fdoutfile >= 0)
		close(data->fdoutfile);
	i = 0;
	while (data->pipes && data->pipes[i])
	{
		y = 0;
		while (y < 2)
		{
			if (data->pipes[i][y] >= 0)
				close(data->pipes[i][y]);
			y++;
		}
		i++;
	}
}

void	clean_exit(t_pipe *data, int exitcode)
{
	close_fds(data);
	free_mem(data);
	exit(exitcode);
}
