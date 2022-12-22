#include <stdio.h>

int n, i, j, validos, total;
int main(void)
{
  scanf("%d", &n);
  int matriz[n][n];
  validos = total = 0; 
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      scanf("%d", &matriz[i][j]);
    }
  }
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(j == 0)
      {
        if(i == 0)
        {
          if(matriz[i + 1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i+1][j]);
          }
          if(matriz[i][j+1] > 0)
          {
            validos = validos+1;
            total= total+(matriz[i][j+1]);
          }
        }
        else if(i == (n-1))
        {
          if(matriz[i-1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i-1][j]);
          }
          if(matriz[i][j+1] >0)
          {
            validos = validos+1;
            total = total+(matriz[i][j+1]);
          }
        }
        else
        {
          if(matriz[i+1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i+1][j]);
          }
          if(matriz[i-1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i-1][j]);
          }
          if(matriz[i][j + 1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j+1]);
          } 
        }
      }
      else if(j == (n-1))
      {
        if(i == 0)
        {
          if(matriz[i+1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i+1][j]);
          }
          if(matriz[i][j-1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j-1]);
          }
        }
        else if(i == (n-1))
        {
          if(matriz[i-1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i-1][j]);
          }
          if(matriz[i][j-1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j-1]);
          }
        }
        else
        {
          if(matriz[i+1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i+1][j]);
          }
          if(matriz[i-1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i-1][j]);
          }
          if(matriz[i][j-1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j-1]);
          }
        }
      }
      else
      {
        if(i == 0)
        {
          if(matriz[i+1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i+1][j]);
          }
          if(matriz[i][j+1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j+1]);
          }
          if(matriz[i][j-1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j - 1]);
          }
        }
        else if(i == (n-1))
        {
          if(matriz[i-1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i-1][j]);
          }
          if(matriz[i][j+1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j+1]);
          }
          if(matriz[i][j-1]>0)
          {
            validos = validos+1;
            total = total+(matriz[i][j-1]);
          }
        }
        else
        {
          if(matriz[i+1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i+1][j]);
          }
          if(matriz[i-1][j] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i-1][j]);
          }
          if(matriz[i][j+1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j + 1]);
          }
          if(matriz[i][j - 1] > 0)
          {
            validos = validos+1;
            total = total+(matriz[i][j - 1]);
          }
        }
      } 
    }
  }
  printf("%d\n", validos);
  printf("%d", total);
  return 0;
}