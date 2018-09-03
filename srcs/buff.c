#include "lem_in.h"

void    buff_clear(t_buff *buff)
{
	ft_strdel(&buff->data);
	ft_strdel(&buff->line);
	free(buff);
	buff = NULL;
}

void    buff_init(t_buff **buff)
{
	if (!(*buff = (t_buff *)malloc(sizeof(t_buff))))
		errors_memory(CANT_ALLOCATE_MEM, "buff_init");
	(*buff)->line = NULL;
	(*buff)->data = ft_strnew(0);
}