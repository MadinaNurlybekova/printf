#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int main(void)
{
	char *test = (char *)malloc(INT_MAX);
	test = NULL;
	free(test);
	if (!test)
		printf("ERROR!\n");
	// printf("%s\n", test);
	return (0);
}