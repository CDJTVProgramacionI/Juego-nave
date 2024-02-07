#include "Frontend\format.h"
#include <stdio.h>

void main()
{
    //Función para que la consola de windows acepte colores
    setupConsole();

    /********************
     *      NIVEL 1     * 
    *********************/                  
    //Valores iniciales de vidas, velocidad y misiles

    while(/*condicion para NO perder*/ || /*contador de tiempo u obstáculos*/)
    {
        //Display de vidas, velocidad y misiles

        //Generar objeto u obstáculo al azar

        //Obtener input del usuario

        //Decisiones para evitar o destruir obstáculos
    int dist,op,vel;
    printf("Solo tani escribe la velocidad:\n");
    scanf("%d",& vel);
    printf("Solo tani escribe la distancia: ");
    scanf("%d",& dist);

    if (dist>=10000 && vel>12000)
    printf("Se esquivo el planeta.");
    else if (dist>=8000 && dist<10000)
    {
     printf("Que desea hacer.\n");
     printf("Presione 1 para Esquivar y 2 para destruir\n");
     scanf("%d",&op);
      switch (op)
      {
      case 1:
        printf("Se esquivo el planeta.");break;
      case 2: 
        printf("Se destruyo el planeta.");break;
      default:
      printf("No presiono una opcion correcta.");break;
      }
    }
     else if (dist<8000)
     printf("Se ha estrellado con el planeta");
     else if (dist<6000)
     printf("Desea agarrar un objeto de interes");

    
    
      


        //Decisiones para capsulas
    } 
}
