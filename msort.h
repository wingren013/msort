#ifndef MSORT_H
# define MSORT_H

# define THREAD_THRESHOLD 10000
# define SORTSWITCH_THRESH 100000

#include <stdlib.h>

typedef struct	msort_param_s
{
	size_t		start;
	size_t		end;
	void		*sorts;
	size_t		sortsize;
	int			(*cmp) (const void *, const void *);
}		msort_param_t;

void		*msort(void *sorts, size_t count, size_t datasize, int (*cmp) (void *, void *));
void		*tmsort(void *sorts, size_t count, size_t datasize, int (*cmp) (void *, void *));

#endif
