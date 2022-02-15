#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num_inc, i, j, k, x, y, result;
    printf("  **  SISTEMAS DE ECUACIONES. METODO DE GAUSS-JORDAN V.2  **\n\n");
    printf("  Di cuantas incognitas tienes:  ");
    scanf(" %d", &num_inc);
    float matriz[num_inc][num_inc+1], recu[1][num_inc+1], incog[num_inc], aux0, aux1, aux2, ayuda;
    printf("\n  Introduce los valores de tu sistema de ecuaciones en la matriz:\n\n");
    for(i=0;i<num_inc;i++)
    {
        for(j=0;j<num_inc+1;j++)
        {
            printf("  Fila %d, columna %d:  ", i+1, j+1);
            scanf(" %d", &k);
            matriz[i][j] = k;
        }
        printf("\n");
    }
    printf("\n\n  Tu sistema seria el siguiente:  \n\n");
    for(i=0;i<num_inc;i++)
    {
        for(j=0;j<num_inc+1;j++)
        {
            printf("  %.2f  ", matriz[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<num_inc-1;i++)
    {
        aux1 = matriz[i][i];
        for(j=i+1;j<num_inc;j++)
        {
            aux2 = matriz[j][i];
            for(k=i;k<num_inc+1;k++)
            {
                aux0 = matriz[i][k];
                recu[0][k] = aux0;
                aux0 = aux0*aux2*(-1);
                matriz[i][k] = aux0;
                aux0 = matriz[j][k];
                aux0 = aux0*aux1*1;
                matriz[j][k] = aux0;
            }
            for(y=0;y<num_inc+1;y++)
            {
                aux0 = matriz[i][y] + matriz[j][y];
                matriz[j][y] = aux0;
            }
            for(x=i;x<num_inc+1;x++)
            {
                aux0 = recu[0][x];
                matriz[i][x] = aux0;
            }
        }
    }
    printf("\n\n  Tu sistema triangulado seria el siguiente:  \n\n");
    for(i=0;i<num_inc;i++)
    {
        for(j=0;j<num_inc+1;j++)
        {
            printf("  %.2f  ", matriz[i][j]);
        }
        printf("\n");
    }
    k=1;
    x=0;
    for(i=0;i<num_inc;i++)
    {
        result=0;
        aux2=0;
        aux0 = matriz[i][num_inc];
        for(j=0;j<num_inc;j++)
        {
            aux1 = matriz[i][j];
            aux2 += aux1;
        }
        if(aux2==0)
        {
            if(aux0==0)
            {
                result=1;
                break;
            }
            else
            {
                result=2;
                break;
            }
        }
    }
    if(result==0)
    {
        printf("\n  Sistema compatible determinado.");
        for(i=num_inc-1;i>=0;i--)
        {
            aux0 = matriz[i][i];
            aux1 = matriz[i][i+k];
            if(k==1)
            {
                aux2 = aux1/aux0;
                incog[x] = aux2;
                for(j=num_inc-1;j>=0;j--)
                {
                    ayuda = matriz[j][num_inc-k];
                    ayuda = ayuda*aux2;
                    matriz[j][num_inc-k] = ayuda;
                }
                k++;
                x++;
            }
            else
            {
                for(y=i+1;y<num_inc;y++)
                {
                    ayuda = matriz[i][y];
                    aux1 = aux1-ayuda;
                }
                aux2 = aux1/aux0;
                incog[x] = aux2;
                for(j=i;j>=0;j--)
                {
                    ayuda = matriz[j][num_inc-k];
                    ayuda = ayuda*aux2;
                    matriz[j][num_inc-k] = ayuda;
                }
                k++;
                x++;
            }
        }
        printf("\n  Tus incognitas son:  ");
        for(i=0;i<num_inc;i++)
        {
            printf("\n  Incognita numero %d:  %.2f", i+1, incog[num_inc-i-1]);
        }
    }
    if(result==1)
    {
        printf("\n  Sistema compatible indeterminado. Soluciones infinitas.");
    }
    if(result==2)
    {
        printf("\n  Sistema incompatible. No hay solucion.");
    }
    printf("\n\n");
    return 0;
}

