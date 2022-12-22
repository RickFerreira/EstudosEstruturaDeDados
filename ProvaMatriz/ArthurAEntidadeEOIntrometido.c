#include <stdio.h>
int x, arthur, entidade, rodrigo;
arthur = 0; entidade = 0; rodrigo = 0;
int main(void) 
{

  scanf("%d", &x);
  int matriz[x][x];
  for(int i=0; i<x; i++)
  {
    for(int j=0; j<x; j++)
    {
      scanf("%d", &matriz[i][j]);
      if(i==j)
      {
        rodrigo+=matriz[i][j];
      }
      if(i%2 == 0)
      {
        arthur+=matriz[i][j];
      }
      if(j%2 != 0)
      {
        entidade+=matriz[i][j];
      }
    }
  }
  if(arthur>entidade && arthur>rodrigo)
  {
    printf("Arthur venceu!\n");
    printf("Resultado: %d", arthur);
  }
  else if(rodrigo>arthur && rodrigo>entidade)
  {
    printf("O intrometido venceu!\n");
    printf("Resultado: %d", rodrigo);
  }
  else if(entidade>arthur && entidade>rodrigo)
  {
    printf("A entidade venceu!\n");
    printf("Resultado: %d", entidade);
  }
  else
  {
    printf("Empate!\n");
    printf("Resultado: %d", rodrigo);
  }
  return 0;
}