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

    int op;

    /********************
    *      NIVEL 1      * 
    *********************/                  
    //Valores iniciales de vidas, velocidad y misiles

    //Instrucciones
    printf("Instrucciones\n");
    printf("En este juego podras realizar diferentes jugadas, apsando asi los niveles con cierto numero de movimientos;pues en el momento en que los movimiento se acaben perdera el juego\n")
    printf("En el nivel 1 podras realizar diferentes acciones con ciertas condiciones:\n la velocidad inicial de la nave es de 12,000 km por hora\n Inicia con 2000 caps. de vida y 8000 misiles\n Si la distancia entre la nave y el planeta es de 8000 y 10,000 se puede evadir el planeta\n 
    Si la distancia entre un planeta y la nave es menor a 8000 la nave choca y pierde el juego\n Si la distancia entre la nave y el planeta está arriba de 10,000 la nave sigue su camino\n Si la distancia entre nave y objeto de interés es menor o igual a 6000 km 
    se ganan 5 caps. de vida (No importa velocidad)\n si no se cumplen las condiciones se pierden 3 capsulas de vida\n La nave puede destruir planetas s/v si distancia es igual o mayor a 8000 km\n
    Por cada planeta destruido se pierden 25 caps. de vida y 50 misiles\n Al intentar destruir un planeta sin respetar las condiciones se pierden 15 caps. y 30 misiles\n Ganas si tus misiles son >= 7800 y tienes >=1900 caps. de vida\n
    Pierde si tus misiles son <7800 o tus caps. de vida son <1900 ")
    clearOnKey();

    int totcapsulas = 2000, totmisiles = 8000;
    while(/*condicion para NO perder*/ 1 /*contador de tiempo u obstáculos*/)
    {
        int vida,misiles, capsulas;

        //Generar una distancia aleatoria al objeto
        //rand() % 8 genera un número entre 0 y 7
        //al sumarle 5 se convierte en un número entre 5 y 12
        int distancia = (rand() % 8 + 5) * 1000;
        int velocidad = (rand() % 8 + 5) * 1000;

        //Generar objeto u obstáculo al azar
        int objeto = rand() % 3;

        //Display
        printf("Vida restante: %d \n",vida);
        printf("Tu velocidad es: %d \n", velocidad);
        printf("Misiles restantes: %d \n", capsulas);	
        

        switch(objeto)
        {
            //Planeta con vida
            case 0:
                printf("Un " BLUE "PLANETA SIN VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
                //Obtener input del usuario
                printf("Que desea hacer.\n");
                printf("Presione 1 para Esquivar y 2 para destruir\n");
                scanf("%d",&op);
                switch (op)
                {
                    //Decisiones para evitar o destruir obstáculos
                    case 1:
                        if (distancia>=8000 && distancia< 10000 && velocidad > 12000 || distancia >= 10000)
                            printf("Se esquivo el planeta.");
                        else
                            printf("Se ha estrellado con el planeta");
                            totcapsulas = totcapsulas-15;
				            totmisiles = totmisiles-30;
                        break;
                    case 2: 
                        if (distancia<=8000 && velocidad > 12000)
                        {
                            printf("Se destruyo el planeta.");
                            totcapsulas = totcapsulas - 25;
				            totmisiles = totmisiles - 50;
                        }
                        else
                        {
                            printf("Se ha estrellado con el planeta");
                            totcapsulas = totcapsulas-15;
				            totmisiles = totmisiles-30;
                        }
                        break;
                    default:
                        printf("No presiono una opcion correcta.");
                        break;
                }
                break;
            //Planeta sin vida
            case 1:
                printf("Un " BRIGHT_GREEN "PLANETA CON VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
                //Obtener input del usuario
                printf("Que desea hacer.\n");
                printf("Presione 1 para Esquivar y 2 para destruir\n");
                scanf("%d",&op);
                switch (op)
                {
                    //Decisiones para evitar o destruir obstáculos
                    case 1:
                        if (distancia>=8000 && distancia< 10000 && velocidad > 12000 || distancia >= 10000)
                            printf("Se esquivo el planeta.");
                        else
                            printf("Se ha estrellado con el planeta");
                            totcapsulas = totcapsulas-15;
				            totmisiles = totmisiles-30;
                        break;
                    case 2: 
                        if (distancia<=8000 && velocidad > 12000)
                        {
                            printf("Se destruyo el planeta.");
                            totcapsulas = totcapsulas - 25;
				            totmisiles = totmisiles - 50;
                        }
                        else
                        {
                            printf("Se ha estrellado con el planeta");
                            totcapsulas = totcapsulas-15;
				            totmisiles = totmisiles-30;
                        }
                        break;
                    default:
                        printf("No presiono una opcion correcta.");
                        break;
                }
                break;
            //Objeto de interés
            case 2:
                printf("Un " MAGENTA "OBJETO DE INTERES " WHITE "se encuentra a %d km de distancia\n", distancia);
                //Obtener input del usuario
                printf("Que desea hacer.\n");
                printf("Presione 1 para capturar y 2 para esquivar\n");
                scanf("%d",&op);
                switch (op)
                {
                    //Decisiones para capturar o esquivar
                    case 1:
                        if(distancia<=6000)
                        {
                            totcapsulas=totcapsulas+5;break;
                        }
                        else
                        {
                            totcapsulas=totcapsulas-3;break;
                        }
                    break;
                    case 2:
                        printf("Esquivaste la capsula");
                    default:
                        printf("No presiono una opcion correcta.");
                        break;
                }
                break;
        }
        clearOnKey();
    } 
}

