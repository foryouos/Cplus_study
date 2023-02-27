#include <stdio.h>

int main()
{
	int i = 0;
	while (1)
	{
		if (10 == i)
		{
			break;
		}
		printf("%d\n", i);
		i++;
	}
}