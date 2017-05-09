/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:45 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/09 14:53:01 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef int t_map;
typedef void t_player;
typedef int t_cmd;

typedef struct	s_vm_env
{
	t_map		map;
	t_player	*player;
	t_cmd		cmd;
}				t_vm_env;

#endif
