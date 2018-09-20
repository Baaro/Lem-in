#include "lem_in.h"

void		printer_init(t_printer *prt)
{
	ft_memset(prt, 0, sizeof(t_printer));
}

void		printer_analyze(t_printer *prt, int argc, char **argv)
{
	size_t	arg;

	if (!argv)
		return ;
	arg = 0;
	while (++arg < argc)
	{
		if (is_a(argv[arg]))
		{
			prt->a = TRUE;
			return ;
		}
		if (!prt->ht && is_ht(argv[arg]))
			prt->ht = TRUE;			
		if (!prt->at && is_at(argv[arg]))
			prt->at = TRUE;			
		if (!prt->p && is_p(argv[arg]))
			prt->p = TRUE;
		if (!prt->u && is_u(argv[arg]))
			prt->u = TRUE;
	}
}

void		print_all(t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	hashtable_print_room(ht);
    hashtable_print_coord(ht);
	adjtab_print(at);
	lstpaths_print(lp);
	// usage_print();
}

void		printer_print(t_printer *prt, t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	if (!prt->a)
	{
        // if (prt->u)
			// usage_print();
		if (prt->ht)
		{
			hashtable_print_room(ht);
			hashtable_print_coord(ht);
		}
		if (prt->at)
			adjtab_print(at);
		if (prt->p)
			lstpaths_print(lp);		
	}
	else
		print_all(lp, at, ht);
}