#include "lem_in.h"

void			info_init(t_info **info)
{
	if (!(*info = (t_info *)malloc(sizeof(t_info))))
		errors_memory(CANT_ALLOCATE_MEM, "info_init");
	ft_memset(*info, 0, sizeof(t_info));
}

void			info_clear(t_info *info)
{
	if (info)
	{
		free(info);
		info = NULL;
	}
}

void			info_clear_links(t_info *info)
{
	free(info->first_room);
	free(info->second_room);
}

void			info_get_links(t_info *info, char *line)
{
	if (!(info->line = ft_strsplit(line, '-')))
		errors_memory(CANT_ALLOCATE_MEM, "info_get_links");
	info->first_room = ft_strredup(info->line[FIRST]);
	info->second_room = ft_strredup(info->line[SECOND]);
	free(info->line);
}

void			info_get_rooms(t_info *info, t_htab *htab, t_buff *buff)
{

	info->cnt_rooms++;
	if (!(info->line = ft_strsplit(buff->line, ' ')))
		errors_memory(CANT_ALLOCATE_MEM, "info_get_rooms");
	info->room = info->line[NAME];
	info->id_room = get_id(htab, info->room, ft_strlen(info->room));
	info->coord = ft_strjoincl(info->line[X], info->line[Y], 1);
	info->id_coord = get_id(htab, info->coord, ft_strlen(info->coord));
	free(info->line);
}