#include <stdlib.h>
#include <string.h>
#include "msort.h"

#define I (sortsize * i)
#define L (sortsize * l)
#define PI (sortsize * pi)

volatile int	mphore;

void	msort_swap(size_t size, char *a, size_t i, size_t l)
{
	char *t = (char*)malloc(sizeof(char) * size);
	
	memcpy(t, &a[i], size);
	memcpy(&a[i], &a[l], size);
	memcpy(&a[l], t, size);
	free(t);
}

void	bsort(msort_param_t params)
{
	size_t		pi;
	size_t		i;
	size_t		l;
	char		*sorts = (char*)(params.sorts);
	size_t		sortsize = params.sortsize;
	size_t		end = params.end;
	size_t		start = params.start;
	int (*cmp) (void *, void *) = params.cmp
	
	if (start >= end)
		return (0);
	i = start;
	pi = (start + (end - start) / 2);
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
		msort_swap(sortsize, sorts, i, l);
	}
	
	msort_param_t	param1;
	param1.start = start;
	param1.end = l;
	param1.sorts = sorts;
	param1.cmp = cmp;
	param1.sortsize = sortsize;
	
	msort_param_t	param2;
	param2.start = (l + 1);
	param2.end = end;
	param2.sorts = sorts;
	param2.cmp = cmp;
	param2.sortsize = sortsize;
	
	if (mphore < 8 && l - start > THREAD_THRESHOLD)
	{
		mphore++;
		pthread_t tid1;;
		pthread_create(&tid1, NULL, qmsort, &param1);
	}
	else
	{
		bsort(param1);
	}
	if (mphore < 8 && end - l > THREAD_THRESHOLD)
	{
		mphore++;
		pthread_t tid2;
		pthread_create(&tid2, NULL, qmsort, &param2);
	}
	else
	{
		bsort(param2);
	}
	return ;
}

void	*qmsort(void *params)
{
	size_t		pi;
	size_t		i;
	size_t		l;
	size_t		sortsize = ((msort_param_t*)params)->sortsize;
	char		*sorts = (char*)(((msort_param_t*)params)->sorts);
	size_t		end = ((msort_param_t*)params)->end;
	size_t		start = ((msort_param_t*)params)->start;
	int (*cmp) (void *, void *) = ((msort_param_t*)params)->cmp;

	if (start >= end)
		return (0);
	i = start;
	pi = (start + (end - start) / 2);
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
		msort_swap(sortsize, sorts, i, l);
	}
	
	msort_param_t	param1;
	param1.start = start;
	param1.end = l;
	param1.sorts = sorts;
	param1.cmp = cmp;
	param1.sortsize = sortsize;
	
	msort_param_t	param2;
	param2.start = (l + 1);
	param2.end = end;
	param2.sorts = sorts;
	param2.cmp = cmp;
	param2.sortsize = sortsize;
	
	if (mphore < 8 && l - start > THREAD_THRESHOLD)
	{
		mphore++;
		pthread_t tid1;
		pthread_create(&tid1, NULL, qmsort, &param1);
	}
	else
	{
		bsort(&param1);
	}
	if (mphore < 8 && end - l > THREAD_THRESHOLD)
	{
		mphore++;
		pthread_t tid2;
		pthread_create(&tid2, NULL, qmsort, &param2);
	}
	else
	{
		bsort(&param2);
	}
	mphore--;
	return (sorts);
}

void	msort(void *sort, size_t count, size_t datasize)
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
	i = 0;
	end = count - 1;
	pi = (start + (end - start) / 2);
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
		msort_swap(sortsize, sorts, i, l);
	}
	
	msort_param_t	param1;
	param1.start = start;
	param1.end = l;
	param1.sorts = sorts;
	param1.cmp = cmp;
	param1.sortsize = datasize;
	
	msort_param_t	param2;
	param2.start = (l + 1);
	param2.end = end;
	param2.sorts = sorts;
	param2.cmp = cmp;
	param2.sortsize = datasize;
	
	if (mphore < 8 && l - start > THREAD_THRESHOLD)
	{
		mphore++;
		pthread_t tid1;
		pthread_create(&tid1, NULL, qmsort, &param1);
	}
	else
	{
		bsort(&param1);
	}
	if (mphore < 8 && end - l > THREAD_THRESHOLD)
	{
		mphore++;
		pthread_t tid2;
		pthread_create(&tid2, NULL, qmsort, &param2);
	}
	else
	{
		bsort(&param2);
	}
	
	return ;
}
