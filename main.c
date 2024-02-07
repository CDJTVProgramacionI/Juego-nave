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

    int op, vida, misiles, distancia, velocidad;

    /********************
    *      NIVEL 1      * 
    *********************/                  
    //Valores iniciales de vidas, velocidad y misiles
    vida = 2000, misiles = 8000;

    //Instrucciones
    printf("Instrucciones\n");
    clearOnKey();

    
    while(/*condicion para NO perder*/ 1 /*contador de tiempo u obstáculos*/)
    {
        //Generar una distancia aleatoria al objeto
        //rand() % 8 genera un número entre 0 y 7
        //al sumarle 5 se convierte en un número entre 5 y 12
        distancia = (rand() % 8 + 5) * 1000;
        velocidad = (rand() % 8 + 5) * 1000;

        //Generar objeto u obstáculo al azar
        int objeto = 0;//rand() % 3;

        //Display
        printf(MAGENTA "Vida restante: %d \n",vida);
        printf(CYAN "Tu velocidad es: %d \n", velocidad);
        printf(YELLOW "Misiles restantes: %d \n", misiles);	
        

        switch(objeto)
        {
            //Planeta sin vida
            case 0:
                printf(RESET "Un " BLUE "PLANETA SIN VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
                //Obtener input del usuario
                do
                {
                    printf("Que desea hacer?\n");
                    printf("Presione 1 para esquivar y 2 para destruir\n");
                    scanf("%d",&op);

                    switch (op)
                    {
                        //Decisiones para evitar o destruir obstáculos
                        case 1:
                            if (distancia>=8000 && distancia< 10000 && velocidad >= 12000 || distancia >= 10000)
                                printf("Se esquivo el planeta.\n");
                            else
                                printf("Se ha estrellado con el planeta\n");
                            break;
                        case 2: 
                            if (distancia<=8000 && velocidad > 12000)
                            {
                                printf("Se destruyo el planeta.\n");
                                vida -= 25;
                                misiles -= 50;
                            }
                            else
                            {
                                printf("No has podido destruir el planeta\n");
                                vida -= 15;
                                misiles -= 30;
                            }
                            break;
                        default:
                            printf("No presiono una opcion correcta.");
                            break;
                    }
                }while (op != 1 && op != 2);
                break;
            //Planeta con vida
            case 1:
                printf("Un " BRIGHT_GREEN "PLANETA CON VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
                //Obtener input del usuario
                printf("Que desea hacer.\n");
                printf("Presione 1 para esquivar y 2 para seguir adelante\n");
                scanf("%d",&op);
                switch (op)
                {
                    //Decisiones para evitar o destruir obstáculos
                    case 1:
                        if (distancia>=8000 && distancia< 10000 && velocidad > 12000 || distancia >= 10000)
                            printf("Se esquivo el planeta.");
                        else
                            printf("Se ha estrellado con el planeta");
                            vida -= 15;
				            misiles -= 30;
                        break;
                    case 2: 
                        if (distancia >= 10000 && distancia < 10000)
                        {
                            printf("Perdiste");
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
                            vida += 5;
                        }
                        else
                        {
                            vida -= 3;
                        }
                    break;
                    case 2:
                        printf("Esquivaste la capsula\n");
                    default:
                        printf("No presiono una opcion correcta.");
                        break;
                }
                break;
        }

        clearOnKey();
    } 
}

