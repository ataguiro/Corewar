/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:45 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/09 20:25:24 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "op.h"

typedef int				t_map;
typedef int				t_cmd;
typedef struct s_player	t_player;

struct			s_player
{
	t_header	header;
	char		*str;
	t_player	*next;
	t_player	*prev;
};

typedef struct	s_vm_env
{
	t_map			map;
	t_player		*player;
	t_cmd			cmd;
	unsigned char	opt;
}				t_vm_env;

t_vm_env		g_env;

#endif
