#include <stdio.h>
#include <stdlib.h>
int i, j, n, c0, c1;
int main(void) 
{
  scanf("%d", &n);
  int mat[n][n];
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < n; j++) 
	{
      scanf("%d", &(mat[i][j]));
      printf("%i ", mat[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < n; i++) 
  {
    c0 = 0;
    c1 = 0;
    for (j = 0; j < n; j++) 
	{
      if (mat[i][j] == 0) 
	  {
		c0++;
      } 
      else 
	  {
		if (mat[i][j] == 1) 
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
      if (mat[i][j] == 0) 
	  {
		c0++;
      } 
      else 
	  {
		if (mat[i][j] == 1) 
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
