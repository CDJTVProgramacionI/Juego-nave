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
int de, va;
    printf("Se te ofrecen tomar 3 acciones: 0=destruir, 1=pierdes, 2=capturar, 3=esquivar, 4=seguir adelante\n");
    printf("Ingrese una velocidad\n");
    scanf("%d",&de);
 if (de >=8000 && de<=10000) {
  va=(3);
    }
 else if (de<8000) {
  va=(1);
     }
     else if (de>10000) {
  va=(4);
     }
     else if (de<=6000) {
  va=(2);
     }
     else if (de>=8000) {
  va=(0);
     }
     printf("Su desicion es: %d", va);
        //Decisiones para capsulas
    } 
}
