#include "corewar.h"

static void	show()
{
	t_blink *top = g_env.blink;

	for (; g_env.blink ; g_env.blink = g_env.blink->next)
		printf("value %zu\n", g_env.blink->pos);
	g_env.blink = top;
	ft_putchar('\n');
}

void	test()
{
	nc_lst_place_blk(14);
	show();
	nc_lst_place_blk(10);
	show();
	nc_lst_place_blk(1);
	show();
	nc_lst_place_blk(9);
	show();
	nc_lst_place_blk(10);
	show();
	nc_lst_place_blk(14);
	show();
	nc_lst_place_blk(8);
	show();
	nc_lst_place_blk(7);
	show();
	nc_lst_place_blk(6);
	show();
	nc_lst_place_blk(100);
	show();
	exit(EXIT_SUCCESS);
	while (1);
}