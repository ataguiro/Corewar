/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:09:48 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/02 03:07:14 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <netinet/in.h>

# include <pthread.h>
# include <netdb.h>

# include "libft.h"

# define ON				1
# define OFF			0

# define MED			256
# define PORT			4243

typedef struct			s_socket
{
	int					sfd;
	int					cfd[4];
	int					port;
	socklen_t			size_c[4];
	char				buff[MED][4];
	struct sockaddr_in	s_addr;
	struct sockaddr_in	c_addr[4];
}						t_socket;

typedef struct			s_server
{
	struct s_socket		s;
	int					server_mode;
	int					num_players;
	char				**se_av;
}						t_server;

extern t_server			g_server;

void					se_check(char **ev);
void					se_get(char **av, int ac);
void					se_fatal(void);
void					se_accept_players(void);

#endif