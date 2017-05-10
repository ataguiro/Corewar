/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:30:54 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 11:23:06 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include "op.h"
# include "struct.h"
# define BUF_SIZE 4096

t_player	*vm_lst_new(void);
void		vm_lst_add(t_player **lst, t_player *n);
t_header	vm_get_player(char *str);
void		vm_fill_player(int argc, char **argv);

#endif
