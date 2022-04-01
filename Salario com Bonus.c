#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char nome;
float salario;
float vendas;
float total;

main(void)
{
	scanf("%s",&nome);
	scanf("%f",&salario);
	scanf("%f",&vendas);
	total = (vendas*0.15+salario);
	printf("TOTAL = R$ %.2f", total);
}
