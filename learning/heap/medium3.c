#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
	char *p0,*p1;

	p0 = malloc(0x10);
	p1 = malloc(0x10);

	strcpy(p1,"pwd");

	printf("Enter your name:");
	scanf("%100s",p0);

	printf("Hello %s \n",p0);

	system(p1);

	free(p0);
	free(p1);
}