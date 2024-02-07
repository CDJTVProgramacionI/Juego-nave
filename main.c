#include "Frontend\format.h"
#include <stdio.h>
#include <time.h>

void main()
{
    //Función para que la consola de windows acepte colores
    setupConsole();
    
    //Establecer la semilla para números aleatorios
    //La función time() nos permite que sea más aleatorio el número
    srand(time(0));

    /********************
    *      NIVEL 1      * 
    *********************/                  
    //Valores iniciales de vidas, velocidad y misiles

    //Instrucciones
    printf("Instrucciones\n");
    clearOnKey();

    while(/*condicion para NO perder*/ 1 /*contador de tiempo u obstáculos*/)
    {
        //Display de vidas, velocidad y misiles

        //Generar objeto u obstáculo al azar
        int objeto = rand() % 3;
        
        //Generar una distancia aleatoria al objeto
        //rand() % 8 genera un número entre 0 y 7
        //al sumarle 5 se convierte en un número entre 5 y 12
        int distancia = (rand() % 8 + 5) * 1000;
        int velocidad = (rand() % 8 + 5) * 1000;

        switch(objeto)
        {
            //Planeta con vida
            case 0:
                printf("Un " BLUE "PLANETA SIN VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
                break;
            //Planeta sin vida
            case 1:
                printf("Un " BRIGHT_GREEN "PLANETA CON VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
                break;
            //Objeto de interés
            case 2:
                printf("Un " MAGENTA "OBJETO DE INTERES " WHITE "se encuentra a %d km de distancia\n", distancia);
                break;
        }

        clearOnKey();

        //Obtener input del usuario

        //Decisiones para evitar o destruir obstáculos

        //Decisiones para capsulas
    } 
}