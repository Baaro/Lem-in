#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

static void				free_all(size_t numargs, ...)
{
	va_list ap;
	void    **to_free;
	size_t  i;

	i = -1;
	va_start(ap, numargs);
	while (++i < numargs)
	{
		to_free = va_arg(ap, void **);
        ft_strdel(to_free);
	}
}

int main(void)
{
    char    *one = malloc(sizeof(char));
    char    *two = malloc(sizeof(char));
    char    *three = malloc(sizeof(char));
    int     *four = malloc(sizeof(int));

    free_all(4, &one, &two, &three, &four);
    // free_all(4, &one, &two, &three, &four);
    system("leaks a.out");
    return (0);
}