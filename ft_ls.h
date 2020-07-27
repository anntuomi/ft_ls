/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:03:28 by atuomine          #+#    #+#             */
/*   Updated: 2020/07/25 14:03:29 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/xattr.h>

# define FLAG_L 1
# define FLAG_BR 2
# define FLAG_SR 4
# define FLAG_A 8
# define FLAG_T 16

typedef struct	s_user
{
	char			*name;
	int				len;
}				t_user;

typedef struct	s_group
{
	char			*name;
	int				len;
}				t_group;

typedef struct	s_size
{
	char			*nbr;
	int				len;
}				t_size;

typedef struct	s_hard_l
{
	char			*nbr;
	int				len;
}				t_hard_l;

//change data types to reflect stat struct data types

typedef struct	s_information
{
	char			*name;
	int				type;
	int				blocks;
	char			*time_str;
	mode_t			mode;
	t_size			size;
	t_user			user;
	t_group			group;
	t_hard_l		hlinks;
}				t_information;

typedef struct	s_file
{
	t_information	info;
	struct s_file	*subfolder;
	struct s_file	*next;
}				t_file;

char	*parse_arguments(int argc, char **argv, int *flags);
void	sort_entries_default(t_file *entries, int flags);

#endif
