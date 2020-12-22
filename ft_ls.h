/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:47:49 by nabdelba          #+#    #+#             */
/*   Updated: 2020/12/21 16:49:08 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

# define FLAGS "lRart"

typedef struct		s_node
{
	char			*name;
	char			*path;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	dev_t			st_rdev;
	struct s_node	*next;
}					t_node;

typedef struct		s_flags
{
	int				l;
	int				u_r;
	int				r;
	int				a;
	int				t;
}					t_flags;

typedef struct		s_size
{
	int				total;
	int				size;
	int				groupspace;
	int				userspace;
	int				linkspace;
	int				min;
	int				maj;
}					t_size;

void				display_file(t_flags flags, t_node **files, int fileordir);

void				ft_lstpush(t_list **path, void const *content,\
														size_t content_size);
void				get_parm(int ac, char **av, t_flags *flags, t_list **path);

void				handle_err(char *name, char *error, int ex);
void				handle_files(t_flags flags, t_list *paths);
void				handle_dirs(t_flags flags, t_list *paths, int mdir);

t_size				get_size(t_flags flags, t_node *files);
int					cmp_time(t_node *n1, t_node *n2);
int					cmp_alpha(t_node *n1, t_node *n2);

void				node_push_file(t_node **files, char *name, char *path);
t_node				*new_node(char *name, char *path);
int					node_get_data(t_node **files, struct dirent *file,\
																char *path);
t_node				*sort_nodes(t_node *node, t_flags flags);

void				print_2(char *str1, char *str2);
void				print_link(t_node *node);
void				print_date(time_t date);
void				print_majmin(t_node *file, t_size size);
void				print_str(char *str, int spacemax);
void				print_int(int nlink, int spacemax);
void				print_access(t_node *elem);

void				free_tnode(t_node **nodes);
void				free_tlist(t_list **list);
int					file_is_link(t_list *cur);

void				reverse_sort(t_node **new);

void				recursion(t_flags flags, t_node *files);

#endif
