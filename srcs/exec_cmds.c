/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:55:58 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 19:27:36 by bthomas          ###   ########.fr       */
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
}

void	debug_print(t_pipe *data, int i)
{
	int	j;

	if (i == 2)
		ft_printf("First iteration.\n");
	else if (i == (data->ac - 2))
		ft_printf("Last iteration.\n");
	else
		ft_printf("Middle iteration.\n");
	ft_printf("path: %s\n", data->cmd_paths[i - 2]);
	ft_printf("cmd: %s\n", data->av[i]);
	ft_printf("Number of commands: %d\n", data->ac - 3);
	j = 0;
	while (data->pipes[j])
		j++;
	ft_printf("Number of pipes: %d\n\n", j);
}

int	child(t_pipe *data, int i)
{
	int	retval;
	int	idx;

	idx = i - 2;
	retval = 0;
	close(data->pipes[idx][1]);
	data->pid = fork();
	if (data->pid < 0)
		clean_exit(data, 1);
	if (data->pid == 0)
	{
		debug_print(data, i);
		if (i == 2)
			redirect_io(data->fdinfile, data->pipes[idx + 1][1], data);
		else if (i == (data->ac - 2))
			redirect_io(data->pipes[idx][0], data->fdoutfile, data);
		else
			redirect_io(data->pipes[idx][0], data->pipes[idx + 1][1], data);
		close_fds(data);
		retval = execve(data->cmd_paths[idx], data->cmd_args[idx], data->envp);
	}
	else
		waitpid(data->pid, NULL, 0);
	return (retval);
}

int	exec_cmds(t_pipe *data)
{
	int	i;
	int	retval;

	i = 2;
	retval = 0;
	while (i < (data->ac - 1))
	{
		retval = child(data, i);
		if (retval != 0)
			clean_exit(data, retval);
		waitpid(data->pid, NULL, 0);
		i++;
	}
	return (retval);
}
