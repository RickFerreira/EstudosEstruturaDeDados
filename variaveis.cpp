#include <stdio.h>
#include <string.h>
#include <locale.h>

int idade;
float salario;
char nome[50];

main(void)
{
	setlocale(LC_ALL, "Portuguese");
	printf("Qual sua idade?");
	scanf("%i",&idade);
	printf("Qual seu salario?");
	scanf("%f",&salario);
	printf("Qual o seu nome?");
	scanf("%s",&nome);
	
	printf("Os dados informados são: %i %2.f %s",idade,salario,nome);	
}
