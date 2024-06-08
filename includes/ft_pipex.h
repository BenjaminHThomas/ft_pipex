/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:30:25 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/08 21:00:19 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "ft_printf.h"
# include <sys/wait.h>

typedef struct s_pipe
{
	int		ac;
	char	**av;
	char	**envp;
	int		fdinfile;
	int		fdoutfile;
	int		fdin;
	int		fdout;
	int		here_doc;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
	int		**pipes;
	pid_t	*pids;
}	t_pipe;

/*
typedef struct s_pipe
{
	int		pipefd[2];
	int		fdread;
	int		fdwrite;
	pid_t	pid1;
	char	**envp;
}	t_pipe;
*/

char	*find_path(char **envp, char *cmd);
void	free_arr(char **arr);
void	close_fds(t_pipe *data);
char	**split_cmd(char *cmd);
char	*clean_cmd(char *cmd);
int		init(t_pipe *data, int ac, char **av, char **envp);
void	clean_exit(t_pipe *data, int exitcode);
char	**get_split(char *cmd);
void	append_path(t_pipe *data, char *path);
void	append_cmd(t_pipe *data, char **split);
void	free_mem(t_pipe *data);
int		exec_cmds(t_pipe *data);

#endif
