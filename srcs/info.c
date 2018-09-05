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
	if (info->first_room)
		free(info->first_room);
	if (info->second_room)
		free(info->second_room);
}

void			info_clear_rooms(t_info *info)
{
	if (info->room)
		free(info->room);
	if (info->coord)
		free(info->coord);
}

void			info_get_links(t_info *info, char *line)
{
	if (!(info->room_coord = ft_strsplit(line, '-')))
		errors_memory(CANT_ALLOCATE_MEM, "info_get_links");
	if (!(info->first_room = ft_strredup(info->room_coord[FIRST_ROOM])))
		errors_memory(CANT_ALLOCATE_MEM, "info_get_links");
	if (!(info->second_room = ft_strredup(info->room_coord[SECOND_ROOM])))
		errors_memory(CANT_ALLOCATE_MEM, "info_get_links");
	free(info->room_coord);
}

void			info_get_rooms(t_info *info, t_htab *htab, t_buff *buff)
{

	info->cnt_rooms++;
	if (!(info->room_coord = ft_strsplit(info->line, ' ')))
		errors_memory(CANT_ALLOCATE_MEM, "info_get_rooms");
	info->room = ft_strredup(info->room_coord[NAME]);
	info->id_room = get_id(htab, info->room, ft_strlen(info->room));
	info->coord = ft_strjoincl(info->room_coord[X], info->room_coord[Y], 1);
	info->id_coord = get_id(htab, info->coord, ft_strlen(info->coord));
	free(info->room_coord);
}