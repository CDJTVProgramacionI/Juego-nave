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

    printf(" ______     ______     __   __   ______           __    __     ______     ______     ______\n");    
    printf("/\\  ___\\   /\\  __ \\   /\\ \\ / /  /\\  ___\\         /\\ \"-./  \\   /\\  __ \\   /\\  == \\   /\\  ___\\\n");   
    printf("\\ \\___  \\  \\ \\  __ \\  \\ \\ \\'/   \\ \\  __\\         \\ \\ \\-./\\ \\  \\ \\  __ \\  \\ \\  __<   \\ \\___  \\\n");  
    printf(" \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\__|    \\ \\_____\\        \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\/\\_____\\\n"); 
    printf("  \\/_____/   \\/_/\\/_/   \\/_/      \\/_____/         \\/_/  \\/_/   \\/_/\\/_/   \\/_/ /_/   \\/_____/\n\n"); 
                                                                                               

    printf("                                            @@@@\n");
    printf("                                          @@@@@@@@\n");
    printf("                                          @@....@@\n");
    printf("                                         @@@.....@@\n");
    printf("                                         @@.@@@@.@@\n");
    printf("                                       @@@@......@@@@\n");
    printf("                                     @@@@@@@@@@@@@@@@@@              PROGRAMACION I\n");
    printf("                                     @@@@.@......@.@@@@       Primer examen departamental\n");
    printf("                                     @@@@.@......@.@@@@             Huerta Johana\n");
    printf("                                     @@@@.@@@@@@@@.@@@@             Garcia Viridiana\n");
    printf("                                   @@@@@..@......@..@@@@@           Garcia Tania\n");
    printf("                                  @@@@@...@.@..@.@....@@@@@         Gomez Camila\n");
    printf("                                 @@@@@....@.@..@.@.....@@@@         Rosas Daniel\n");
    printf("                               @@@@@......@.@..@.@......@@@@@\n");
    printf("                             @@@@@........@......@........@@@@@\n");
    printf("                             @@@@.........@@@@@@@@.........@@@@\n");
    printf("                             @@@@....@@..@@@@@@@@@@..@@....@@@@\n");
    printf("                              @@.@@@@@@.@....@@....@.@@@@@@.@@\n");
    printf("                              @@@@@@@@@@@....@@....@.@@@@@@@@@\n");
    printf("                                       @@@@@@@@@@@@@@\n");

    clearOnKey();

    /********************
    *      NIVEL 1      * 
    *********************/                  
    //Valores iniciales de vidas, velocidad y misiles
    vida = 2000;
    misiles = 8000;
    contdecisiones = 1;

    //Instrucciones
    printf("Instrucciones\n");
    printf("En este juego podras realizar diferentes jugadas, pasando asi los niveles con cierto numero de movimientos; pues en el momento en que los movimiento se acaben perdera el juego\n");
    printf("En el nivel 1 podras realizar diferentes acciones con ciertas condiciones:\nInicia con 2000 caps. de vida y 8000 misiles\nSi la distancia entre la nave y el planeta es de 8000 y 10,000 se debe evadir el planeta\nSi la distancia entre un planeta y la nave es menor a 8000 la nave choca y pierde el juego\nSi la distancia entre la nave y el planeta esta arriba de 10,000 km la nave sigue su camino\nSi la distancia entre nave y objeto de interes es menor o igual a 6000 km se ganan 5 caps. de vida (No importa la velocidad)\nSi no se cumplen las condiciones se pierden 3 capsulas de vida\nLa nave puede destruir planetas sin vida si la distancia es igual o mayor a 8000 km\nPor cada planeta destruido se pierden 25 caps. de vida y 50 misiles\nAl intentar destruir un planeta sin respetar las condiciones se pierden 15 caps. y 30 misiles\nPierdes si tus misiles son < 7800 o tus caps. de vida son < 1900\n");
    clearOnKey();

    
    while(misiles >= 7800 && vida >= 1900 && contdecisiones <= 7)
    {
        //Generar una distancia aleatoria al objeto

        distancia = (rand() % 12 + 1) * 1000;
        velocidad = (rand() % 15 + 1) * 1000;

        //Display
        printf(MAGENTA "CAPS. VIDA: %d  ",vida);
        printf(WHITE "|" CYAN "  VELOCIDAD: %d km/h  ", velocidad);
        printf(WHITE "|" YELLOW "    MISILES: %d\n", misiles);

        printf(RESET);	

        //Generar objeto u obstáculo al azar
        int objeto = rand() % 3;

        switch(objeto)
        {
            //Planeta sin vida
            case 0:
                printf("Un " BRIGHT_BLUE "PLANETA SIN VIDA " WHITE "se encuentra a %d km de distancia\n", distancia);
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
                            {
                                printf("Se ha estrellado con el planeta\n");
                                vida = 0;
                            }
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
                                    vida = 0;
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
                            {
                                printf("Se ha estrellado con el planeta\n");
                                vida = 0;
                            }     
                            break;
                        case 's': case 'S': 
                            if (distancia <= 8000 || (distancia > 8000 && distancia <= 10000 && velocidad >= 12000))
                            {
                                printf("Se ha estrellado con el planeta\n");
                                vida = 0;
                            }
                            else
                            {
                                printf("Siga adelante\n");
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
                printf("Un " BRIGHT_RED "OBJETO DE INTERES " WHITE "se encuentra a %d km de distancia\n", distancia);
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

    //Compara la cantidad de misiles y de capsulas restantes y define si pierdes o ganas
    if (misiles >= 7800 && vida >= 1900)
    {
        printf("Ganaste el nivel 1\n");
    }
    else 
    {
        printf("Perdiste\n");
    }

    /********************
    *      NIVEL 2      * 
    *********************/                  
    //Valores iniciales de vidas, velocidad y misiles
    vida = 1900;
    misiles = 7800;
    contdecisiones = 1;

    //Instrucciones
    printf("Instrucciones\n");
    printf("En este juego podras realizar diferentes jugadas, pasando asi los niveles con cierto numero de movimientos; pues en el momento en que los movimiento se acaben perdera el juego\n");
    printf("En el nivel 2 podras realizar diferentes acciones con ciertas condiciones:\nLa nave comienza con 1900 cápsulas de vida y 7800 misiles\nSi la distancia entre la nave y los asteroides está entre 6000 y 8000 km y la velocidad de la nave es mayor a 20000 km/h la nave debe evadir los asteroides\nSi la distancia es de 6000km o menos (sin importar la velocidad) la nave choca con el asteroide y pierde el juego\nSi la distancia es de 8000km o más (sin importar la velocidad) la nave continúa su viaje\nPor cada objeto capturado (si la distancia entre la nave y el objeto no excede los 4000 km) la nave gana 10 cápsulas de vida. Pero recibe una PENALIZACIÓN de 7 cápsulas de vida si intenta capturar los objetos sin cumplir las condiciones necesarias\nLa nave puede destruir asteroides si la distancia entre la nave y el asteroide es igual o menor a 6000 km y la velocidad de la nave es de 20000 km/h o mas\nPor cada asteroide destruido la nave pierde 30 cápsulas de vida y 60 misiles.Intentar destruir un asteroide sin cumplir los requisitos necesarios resulta en una penalización de 20 cápsulas de vida y 40 misiles\nSe supera el nivel si la nave queda con al menos 7400 misiles y al menos 1500 cápsulas de vida\nEl jugador pierde si la nave tiene menos de 7400 misiles o menos de 1500 cápsulas de vida\n");
    clearOnKey();

    
    while(misiles >= 7400 && vida >= 1500 && contdecisiones <= 7)
    {
        //Generar una distancia aleatoria al objeto

        distancia = (rand() % 12 + 1) * 1000;
        velocidad = (rand() % 15 + 1) * 1000;

        //Display
        printf(MAGENTA "CAPS. VIDA: %d  ",vida);
        printf(WHITE "|" CYAN "  VELOCIDAD: %d km/h  ", velocidad);
        printf(WHITE "|" YELLOW "    MISILES: %d\n", misiles);

        printf(RESET);	

        //Generar objeto u obstáculo al azar
        int objeto = rand() % 2;

        switch(objeto)
        {
            //Asteroide
            case 0:
                printf("Un " BLUE "ASTEROIDE " WHITE "se encuentra a %d km de distancia\n", distancia);
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
                            if (distancia > 6000)
                                printf("Se esquivo el asteroide.\n");
                            else
                            {
                                printf("Se ha estrellado con el asteroide\n");
                                vida = 0;
                            }
                            break;
                        case 'D': case 'd': 
                            if (distancia<=6000 && velocidad >= 20000)
                            {
                                printf("Se destruyo el asteroide.\n");
                                vida -= 30;
                                misiles -= 60;
                            }
                            else
                            {
                                if(distancia > 6000 && distancia <= 8000 && velocidad >= 20000)
                                {
                                    printf("Debiste haber esquivado\n");
                                    vida = 0;
                                }
                                else
                                {
                                    printf("No has podido destruir el asteroide\n");
                                    vida -= 20;
                                    misiles -= 40;
                                }
                            }
                            break;
                        default:
                            printf("No presiono una opcion correcta.\n");
                            break;
                    }
                }while (op != 'e' && op != 'E' && op != 'D' && op != 'd');
                break;
            //Objeto de interés
            case 1:
                printf("Un " BRIGHT_RED "OBJETO DE INTERES " WHITE "se encuentra a %d km de distancia\n", distancia);
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
                            if(distancia <= 4000)
                            {
                                printf("Objeto capturado\n");
                                vida += 10;
                            }
                            else
                            {
                                printf("Objeto no capturado\n");
                                vida -= 7;
                            }
                        break;
                        case 'e': case 'E':
                            printf("Esquivaste el objeto\n");
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

    //Compara la cantidad de misiles y de capsulas restantes y define si pierdes o ganas
    if (misiles >= 7400 && vida >= 1500)
    {
        printf("Ganaste el nivel 2\n");
    }
    else 
    {
        printf("Perdiste\n");
    }

    /********************
    *      NIVEL 3      * 
    *********************/                  
    //Valores iniciales de vidas, velocidad y misiles
    vida = 1500;
    misiles = 7400;
    contdecisiones = 1;

    //Instrucciones
    printf("NIVEL 3 instrucciones\n");
    printf("Inicias con 1500 caps. de vida y 7400 misiles\nSi la distancia entre la nave y el hoyo negro es de 4,000 km y 6,000 km se debe evadir\nSi la distancia entre un hoyo negro y la nave es menor a 4000 km la nave chocara si intenta esquivar y pierde el juego\nSi la distancia entre la nave y el hoyo negro esta arriba de 10,000 km la nave sigue su camino\nSi la distancia entre nave y objeto de interes es menor o igual a 2000 km se ganan 15 caps. de vida (No importa la velocidad)\nSi no se cumplen las condiciones se pierden 35 capsulas de vida\nLa nave puede destruir hoyos negros si la distancia es igual o mayor a 4000 km y su velocidad supera los 28,000 km/h\nPor cada planeta destruido se pierden 35 caps. de vida y 80 misiles\nAl intentar destruir un planeta sin respetar las condiciones se pierden 30 caps. y 50 misiles\nPierdes si tus misiles son < 6900 o tus caps. de vida son < 1000\n");
    clearOnKey();

    
    while(misiles >= 7800 && vida >= 1900 && contdecisiones <= 7)
    {
        //Generar una distancia aleatoria al objeto

        distancia = (rand() % 12 + 1) * 1000;
        velocidad = (rand() % 15 + 1) * 1000;

        //Display
        printf(MAGENTA "CAPS. VIDA: %d  ",vida);
        printf(WHITE "|" CYAN "  VELOCIDAD: %d km/h  ", velocidad);
        printf(WHITE "|" YELLOW "    MISILES: %d\n", misiles);

        printf(RESET);	

        //Generar objeto u obstáculo al azar
        int objeto = rand() % 2;

        switch(objeto)
        {
            //Hoyo negro
            case 0:
                printf("Un " PURPLE "HOYO NEGRO " WHITE "se encuentra a %d km de distancia\n", distancia);
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
                            if (distancia > 4000 && distancia < 6000 && velocidad > 28000 )   //Opcion de seguir con  el viaje 
                                printf("Se esquivo el planeta.\n");
                            else if (distancia<=4000)
                            {
                                printf("Se ha estrellado con el planeta\n");
                                vida = 0;
                            }
                            break;
                        case 'D': case 'd': 
                            if (distancia<=4000 && velocidad >= 28000)
                            {
                                printf("Se destruyo el planeta.\n");
                                vida -= 35;
                                misiles -= 80;
                            }
                            else if (distancia>4000 && velocidad< 28000)
                            {
                                printf("Debiste haber esquivado\n");
                                vida = 0;
                            }
                            else 
                            {
                                printf("No has podido destruir el planeta\n");
                                vida -= 30;
                                misiles -= 50;
                            }
                            break;
                        default:
                            printf("No presiono una opcion correcta.\n");
                            break;
                    }
                } while (op != 'e' && op != 'E' && op != 'D' && op != 'd');
                break;
            //Objeto de interés
            case 1:
                printf("Un " BRIGHT_RED "OBJETO DE INTERES " WHITE "se encuentra a %d km de distancia\n", distancia);
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
                            if(distancia <= 2000)
                            {
                                printf("Objeto capturado\n");
                                vida += 15;
                            }
                            else
                            {
                                printf("Objeto no capturado\n");
                                vida -= 35;
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

    //Compara la cantidad de misiles y de capsulas restantes y define si pierdes o ganas
    if (misiles >= 6900 && vida >= 1000)
    {
        printf("Ganaste el nivel 3\n");
    }
    else 
    {
        printf("Perdiste\n");
    }
}
