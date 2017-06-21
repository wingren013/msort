#include "msort.h"
#include <stdlib.h>
#include <stdio.h>

int	cmp(void *a, void *b)
{
	char *x = (char*)a;
	char *y = (char*)b;
	
	if (*x > * y)
		return (1);
	if (*x == *y)
		return (0);
	if (*x < *y)
		return (-1);
	return (0);
}

void	*msort(void *sort, size_t count, size_t datasize, int (*cmp) (void *, void *))
{
	size_t		pi;
	size_t		i;
	size_t		l;
	size_t		end;
	char		*sorts = (char*)sort;

	//do sample of data
	//if looks partially sorted dp timsort
	/*
	if (datasorted)
	{
		tmsort(sort, count, datasize);
	}
	*/
	end = count - 1;
	mphore = 0;
	g_size = datasize;
	g_cmp = cmp;
	i = 0;
	end = count - 1;
	pi = end / 2;
	l = end;
	while (i <= l)
	{
		while (cmp(&sorts[I], &sorts[PI]) == -1)
			i++;
		while (cmp(&sorts[L], &sorts[PI]) == 1)
			l--;
		if (i >= l)
			break ;
		if (i == pi)
			pi = l;
		else if (l == pi)
			pi = i;
		msort_swap(datasize, sorts, i, l);
	}
	
	msort_param_t	param1;
	param1.start = 0;
	param1.end = l;
	param1.sorts = sorts;
	param1.sortsize = datasize;
	
	msort_param_t	param2;
	param2.start = (l + 1);
	param2.end = end;
	param2.sorts = sorts;
	param2.sortsize = datasize;
	msort(&sorts[l + 1]
	
	return (sort);
}
int	main(void)
{
	char *a = malloc(8);
	a[0] = 35;
	a[1] = 80;
	a[2] = 20;
	a[3] = 9;
	a[4] = 6;
	a[5] = 2;
	a[6] = 32;
	a[7] = 42;

	int i = 0;
	while (i < 8)
	{
		printf("%d\n", a[i]);
		i++;
	}
	msort(a, 8, 1, cmp);
	printf("____\n");
	while (i < 8)
	{
		printf("%d\n", a[i]);
		i++;
	}
}
