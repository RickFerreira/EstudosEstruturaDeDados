#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int contador;
int numero;
int soma;
int final;
int count;
int resultado;
int x;
int y;

main(void)
{
	contador = 0;
	
	for (y = 1; y <= 5; y++)
	{
		scanf("%i",&numero);
		resultado = numero+1;
		soma = 0;
		count = 0;
		for (x = 1; x <= resultado; x++)
		{
			count = count+1;
			if ((numero%count) == 0)
			{
				soma = soma + count;
			}
		}
		if (soma > contador)
		{
			contador = soma;
			final = numero;
		}
	}
	printf("%d",final);
}
