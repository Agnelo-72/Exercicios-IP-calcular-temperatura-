#include <stdio.h>
#include<stdlib.h>
#define MESES 12
#define MAX_DIAS 31


void main (void)
{
    int temperatura[MESES][MAX_DIAS];
    int dias[MESES];
    double mediatemp[MESES] = {0.0};
    int nmeses, i_mes, i_dia;
    
     // Obter número de meses a considerar, entre 1 e 12 meses
     
     do{
         printf ("Diga o numero de meses a considerar ([1, %d]):", MESES);
         scanf("%d", &nmeses);
     } while ( (nmeses <= 0) || (nmeses > MESES) );
     
     for (i_mes=0; i_mes < nmeses; i_mes++){ // para cada um dos meses
     
         do{ // Obter número de dias a considerar nesse mês, entre 1 e 31 dias
             printf ("Diga o numero de dias do mes %d ([1, %d]):", i_mes+1, MAX_DIAS);
             scanf("%d", &dias[i_mes]);
         } while ( (dias[i_mes] <= 0) || (dias[i_mes] > MAX_DIAS) );
         
         // Obter as temperaturas que se registaram nesses dias desse mês
         
         for (i_dia=0; i_dia < dias[i_mes]; i_dia++)
         {
             printf("Temperatura do dia %d: ", i_dia+1);
             scanf("%d",&temperatura[i_mes][i_dia]);
             
             // Somas acumuladamente as temperaturas desse mês para calcular média do mês
             mediatemp[i_mes]+=temperatura[i_mes][i_dia];
         }
         
     } // FIM de for (i_mes=0; i_mes<nmeses; i_mes++)
     // Agora mostra a tabela de temperaturas toda e a média das temperaturas em cada mês
     
     for (i_mes=0; i_mes < nmeses; i_mes++)
     {
        printf("\nTemperatura do mes %d\n", i_mes+1);
        
     for (i_dia=0; i_dia < dias[i_mes]; i_dia++)
         printf("dia %d = %d\n",i_dia+1, temperatura[i_mes][i_dia]);
         printf("Media do mes = %8.3lf\n", mediatemp[i_mes]/dias[i_mes]);
         printf("\n");
     }
}
