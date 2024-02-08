#include "Frontend\format.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>

void main()
{
    //Función para que la consola de windows acepte colores
    setupConsole();
    
    //Establecer la semilla para números aleatorios
    //La función time() nos permite que sea más aleatorio el número
    srand(time(0));

    int vida, misiles, distancia, velocidad, contdecisiones;
    char op;

    /********************
    *      NIVEL 1      * 
    *********************/                  
    //Valores iniciales de vidas, velocidad y misiles
    vida = 2000,
    misiles = 8000;
    contdecisiones = 1;

    //Instrucciones
    printf("Instrucciones\n");
    clearOnKey();

    
    while(/*condicion para NO perder*/ 1 && contdecisiones <= 7)
    {
        //Generar una distancia aleatoria al objeto

        distancia = (rand() % 12 + 1) * 1000;
        velocidad = (rand() % 15 + 1) * 1000;

        //Display
        printf(MAGENTA "Vida restante: %d \n",vida);
        printf(CYAN "Tu velocidad es: %d \n", velocidad);
        printf(YELLOW "Misiles restantes: %d \n", misiles);

        printf(RESET);	

        //Generar objeto u obstáculo al azar
        int objeto = rand() % 3;

        switch(objeto)
        {
            //Planeta sin vida
            case 0:
                printf("Un " BLUE "PLANETA SIN VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
                //Obtener input del usuario
                do
                {
                    printf("Que desea hacer?\n");
                    printf("Presione[E] para esquivar o [D] para destruir\n");
                    op = getch();

                    switch (op)
                    {
                        //Decisiones para evitar o destruir obstáculos
                        case 'E': case 'e':
                            if (distancia > 8000)
                                printf("Se esquivo el planeta.\n");
                            else
                                printf("Se ha estrellado con el planeta\n");
                            break;
                        case 'D': case 'd': 
                            if (distancia<=8000 && velocidad >= 12000)
                            {
                                printf("Se destruyo el planeta.\n");
                                vida -= 25;
                                misiles -= 50;
                            }
                            else
                            {
                                if(distancia > 8000 && distancia <= 10000 && velocidad >= 12000)
                                {
                                    printf("Debiste haber esquivado\n");
                                }
                                else
                                {
                                    printf("No has podido destruir el planeta\n");
                                    vida -= 15;
                                    misiles -= 30;
                                }
                            }
                            break;
                        default:
                            printf("No presiono una opcion correcta.\n");
                            break;
                    }
                }while (op != 'e' && op != 'E' && op != 'D' && op != 'd');
                break;
            //Planeta con vida
            case 1:
                printf("Un " BRIGHT_GREEN "PLANETA CON VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
                //Obtener input del usuario
                do
                {
                    printf("Que desea hacer.\n");
                    printf("Presione [E] para esquivar y [S] para seguir adelante\n");
                    op = getch();

                    switch (op)
                    {
                        //Decisiones para evitar o destruir obstáculos
                        case 'e': case 'E':
                            if (distancia > 8000)
                                printf("Se esquivo el planeta.\n");
                            else
                                printf("Se ha estrellado con el planeta\n");
                            break;
                        case 's': case 'S': 
                            if (distancia <= 8000 || (distancia > 8000 && distancia < 10000 && velocidad >= 12000))
                            {
                                printf("Se ha estrellado con el planeta\n");
                            }
                            break;
                        default:
                            printf("No presiono una opcion correcta.\n");
                            break;
                    }
                } while (op != 'e' && op != 'E' && op != 'S' && op != 's');
                break;
            //Objeto de interés
            case 2:
                printf("Un " MAGENTA "OBJETO DE INTERES " WHITE "se encuentra a %d km de distancia\n", distancia);
                //Obtener input del usuario
                do
                {
                    printf("Que desea hacer.\n");
                    printf("Presione [C] para capturar y [E] para esquivar\n");
                    op = getch();

                    switch (op)
                    {
                        //Decisiones para capturar o esquivar
                        case 'c': case 'C':
                            if(distancia <= 6000)
                            {
                                printf("Objeto capturado\n");
                                vida += 5;
                            }
                            else
                            {
                                printf("Objeto no capturado\n");
                                vida -= 3;
                            }
                        break;
                        case 'e': case 'E':
                            printf("Esquivaste la capsula\n");
                            break;
                        default:
                            printf("No presiono una opcion correcta.\n");
                            break;
                    }
                } while (op != 'e' && op != 'E' && op != 'C' && op != 'c');
                break;
        }

        contdecisiones++;
        clearOnKey();
    } 
}

