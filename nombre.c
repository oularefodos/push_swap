
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **str)
{
	int i;
	int n;

	if (ac == 1)
		return (0);
	n = 0;
	for(i = 0; i < atoi(str[1]); i++)
	{
		if (n % 2)
			printf("%d ", n * -1);
		else 
			printf ("%d ", n);
		n++;
	}
}
