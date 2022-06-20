/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:47:33 by seoyepar          #+#    #+#             */
/*   Updated: 2022/06/20 21:52:58 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_path_cmd{
	char	*cmd;
	char	**path;
	char	**options;
}	t_pc;

char	**ft_split(char const *s, char c);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	**find_path(char **envp);
void	init_pc(t_pc *pc);
void	ft_pipex(int argc, char **argv, int *f, char **envp);
int		access_cmd(t_pc *pc, char **envp);
void	free_struct(t_pc *pc);
int		get_pc(t_pc *pc, char *argv, char **envp);
void	free_arr(char **st);
char	**find_path(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	child_p(int *f, char **envp, int *fd, t_pc *pc);
int		go_pipex(int *f, char **envp, t_pc *pc);
void	parent_p(int *f, char **envp, int *fd, t_pc *pc);

#endif
