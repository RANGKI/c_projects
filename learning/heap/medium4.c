#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int(*fp) (const char *);

fp *toInt()
{
	fp *ti;
	ti = malloc(sizeof(*ti));
	*ti = atoi;
	return ti;
}

int main(int argc, char **argv)
{
	unsigned int *array, length, size, i;

	length = atoi(argv[1]);

	size = sizeof(unsigned int) * length;
	array = malloc(size);

	fp *nt = toInt();

	i = 0;
	while(i < length)
	{
		scanf("%ld",&array[i]);
		if(array[i] == 1)
			break;
		i++;
	}

	(*nt)(argv[2]);

	return 0;
}