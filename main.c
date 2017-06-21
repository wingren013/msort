#include "msort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	mycmp(void *a, void *b)
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

void	msort_swap(size_t size, char *a, size_t i, size_t l)
{
	char *t = (char*)malloc(sizeof(char) * (size + 1));

	printf("what\n");
	memcpy(t, &a[i], size);
	memcpy(&a[i], &a[l], size);
	memcpy(&a[l], t, size);
	free(t);
}

void	*testsort(void *sort, size_t count, size_t datasize, int (*cmp) (void *, void *))
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
	i = 0;
	end = count - 1;
	pi = end / 2;
	l = end;
	while (i <= l)
	{
		while (cmp(&sorts[i * datasize], &sorts[pi * datasize]) == -1)
			{
				i++;
				printf("debug]\n");
			}
		while (cmp(&sorts[l * datasize], &sorts[pi * datasize]) == 1)
			{
				l--;
				printf("ok\n");
			}
		if (i >= l)
			break ;
		if (i == pi)
			pi = l;
		else if (l == pi)
			pi = i;
		printf("crash\n");
		msort_swap(datasize, sorts, i * datasize, l * datasize);
		printf("crash\n");
	}
	testsort(sorts, l + 1, datasize, cmp);
	testsort(&sorts[l + 1], end + 1, datasize, cmp);
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
	testsort(a, 8, 1, mycmp);
	printf("____\n");
	i = 0;
	while (i < 8)
	{
		printf("%d\n", a[i]);
		i++;
	}
}
