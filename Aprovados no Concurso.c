#include <stdio.h>
#include <string.h>
#include <locale.h>

int portugues;
int matematica;
float redacao;
int contador;

main(void)
{
	contador = 0;
	for(;;)
	{
		scanf("%i",&portugues);
		
		if (portugues < 0)
		{
			break;
		}
		else
		{
			scanf("%i",&matematica);
			scanf("%f",&redacao);
			if (portugues >= 40)
			{
				if (matematica >= 21)
				{
					if (redacao >= 7)
					{
						contador = contador + 1;
					}
				}
			}		
		}
	}
	printf("%d",contador);
}

