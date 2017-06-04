/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:09:48 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/04 03:40:00 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <netinet/in.h>

# include <pthread.h>
# include <netdb.h>
# include <signal.h>

# include "libft.h"

# define ON				1
# define OFF			0

# define MED			256
# define PORT			4243

typedef struct			s_socket
{
	int					sfd;
	int					port;
	struct sockaddr_in	s_addr;
}						t_socket;

typedef struct			s_client
{
	int					fd;
	int					id;
	int					connected;
	int					ready;
	socklen_t			size_c;
	char				buff[MED];
	struct sockaddr_in	c_addr;
	pthread_t			cli;
}						t_client;

typedef struct			s_server
{
	struct s_socket		s;
	int					server_mode;
	int					num_players;
	int					ready;
	char				**se_av;
}						t_server;

extern t_server			g_server;
extern t_client			g_client[5];
extern int				g_saver;
extern int				g_len;
extern pthread_t	accept_mode;

void					se_check(char **ev);
void					se_get(char **av, int ac);
void					se_fatal(void);
void					se_accept_players(void);
void					*se_accept_thread(void *arg);
void					se_sendinfo(int i);
void					se_handle(int sig);
void					se_secure(int element);
int						se_search_slot(void);

#endif