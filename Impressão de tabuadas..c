#include <stdio.h>

int a;
int b;
int x;
int y;

main(void)
{
	while(1)
	{
		scanf("%i",&a);
		if ((1>a) || (a>9))
		{
			printf("Insira um número inicial entre 1 e 9\n");	
		}
		else
		{
			break;
		}
	}
	while(1)
	{
		scanf("%i",&b);
		if ((1>b) || (b>9))
		{
			printf("Insira um número final entre 1 e 9\n");	
		}
		else
		{
			break;
		}
	}
	if (a > b)
	{
		printf("Nenhuma tabuada nesse intervalo");
	}	
	if ((10>a>0) && (10>b>0))
	{
		for (x = a; x <= b; x++)
		{
			for (y = 1; y <= 9; y++)
			{
				printf("%i x %i = %i\n",x, y,(x*y));
			}
			printf("\n");
		}
	}
}
