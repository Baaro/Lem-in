#include "lem_in.h"

void	adjtab_init(t_adjtab *adjtab, t_htab *htab)
{
	if (!(adjtab = ft_memset(adjtab, 0, sizeof(t_adjtab))))
	   errors_memory(CANT_SETZERO, "adjtab_init");
	adjtab->size = htab->size;
    if (!(adjtab->lsts = (t_adjlst **)malloc(sizeof(t_adjlst *) * adjtab->size + 1)))
        errors_memory(CANT_ALLOCATE_MEM, "adjtab_init");
	adjlst_init(adjtab->lsts, adjtab->size + 1);
}
