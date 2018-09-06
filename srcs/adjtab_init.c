#include "lem_in.h"

void	adjtab_init(t_adjtab *adjtab, size_t size)
{
	adjtab->size = size;
    if (!(adjtab->lsts = (t_adjlst **)malloc(sizeof(t_adjlst *) * adjtab->size + 1)))
        errors_memory(CANT_ALLOCATE_MEM, "adjtab_init");
	adjlst_init(adjtab->lsts, adjtab->size + 1);
}
