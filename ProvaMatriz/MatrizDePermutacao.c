#include <stdio.h>
int i, j, n, c0, c1;
int main(void) 
{
  scanf("%d", &n);
  int matriz[n][n];
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < n; j++) 
	{
      scanf("%d", &(matriz[i][j]));
      printf("%i ", matriz[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < n; i++) 
  {
    c0 = 0;
    c1 = 0;
    for (j = 0; j < n; j++) 
	{
      if (matriz[i][j] == 0) 
	  {
		c0++;
      } 
      else 
	  {
		if (matriz[i][j] == 1) 
		{
	  	c1++;
		}
		else 
		{
	  		printf("False\n");
	  		return(1);
		}
      }
    }
    if (c0 != n-1 || c1 != 1) 
	{
      printf("False\n");
      return(1);
    }
  }
  for (j = 0; j < n; j++) 
  {
    c0 = 0;
    c1 = 0;
    for (i = 0; i < n; i++) 
	{
      if (matriz[i][j] == 0) 
	  {
		c0++;
      } 
      else 
	  {
		if (matriz[i][j] == 1) 
		{
	  		c1++;
		}
		else 
		{
	  		printf("False\n");
	  		return(1);
		}
      }
    }
    if (c0 != n-1 || c1 != 1) 
	{
      printf("False\n");
      return(1);
    }
  }
  printf("True\n");
  return(1);
}