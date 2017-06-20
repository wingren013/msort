#ifndef MSORT_H
# define MSORT_H

# define THREAD_THRESHOLD 10000

#include <stdlib.h>

typedef struct	msort_param_s
{
	size_t		start;
	size_t		end;
	void		*sorts;
	size_t		sortsize;
	int			(*cmp) (const void *, const void *);
}				msort_param_t;

#endif