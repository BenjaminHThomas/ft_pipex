/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:55:58 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 15:57:12 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	redirect_io(int fdin, int fdout, t_pipe *data)
{
	if (dup2(fdin, STDIN_FILENO) == -1)
	{
		perror("Error: could not redirect stdin\n");
		clean_exit(data, 1);
	}
	if (dup2(fdout, STDOUT_FILENO) == -1)
	{
		perror("Error: could not redirect stdout\n");
		clean_exit(data, 1);
	}
	close_fds(data);
}

void	child(t_pipe *data, int i)
{
	int	idx;

	idx = i - 2;
	data->pid = fork();
	if (data->pid < 0)
	{
		perror("Error: could not fork process.\n");
		clean_exit(data, 1);
	}
	if (data->pid == 0)
	{
		if (i == 2)
		{
			printf("first iteration\n");
			redirect_io(data->fdinfile, data->pipe_arr[idx + 1][1], data);
		}
		else if (i == (data->ac - 2))
		{
			printf("final iteration.\n");
			redirect_io(data->pipe_arr[idx][0], data->fdoutfile, data);
		}
		else
		{
			printf("middle iteration.\n");
			redirect_io(data->pipe_arr[idx][0], data->pipe_arr[idx + 1][1],
				data);
		}
		execve(data->cmd_paths[idx], data->cmd_args[idx],
				data->envp);
	}
	else
		waitpid(data->pid, NULL, 0);
}

int	exec_cmds(t_pipe *data)
{
	int	i;
	int	retval;

	i = 2;
	retval = 0;
	while (i < (data->ac - 1))
	{
		child(data, i);
		i++;
	}
	return (retval);
}
