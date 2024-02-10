#include "Frontend\format.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void main()
{
    //Función para que la consola de windows acepte colores
    setupConsole();
    
    //Establecer la semilla para números aleatorios
    //La función time() nos permite que sea más aleatorio el número
    srand(time(0));

    int vida, misiles, distancia, velocidad, contdecisiones, objeto, planeta, nivel = 0;
    char op, obstaculo[25];
    const int MAXVIDAS[4] = {2000, 1900, 1500, 1000}, MAXMISILES[4] = {8000, 7800, 7400, 6900};
    const int DESTMISILES[3] = {50, 20, 80}, DESTVIDAS[3] = {25, 30, 35}, CAPSULAS[3] = {5, 10, 55};
    const int NODESTMISILES[3] = {30, 40, 50}, NODESTVIDAS[3] = {50, 60, 30}, NOCAPSULAS[3] = {3, 7, 35};
    const int MAXDIST[3] = {10000, 8000, 6000}, MAXVEL[3] = {12000, 20000, 28000};

    //Pantalla principal
    //Instrucciones
    printf("Instrucciones\n");
    printf("En este juego podras realizar diferentes jugadas, esquivar, atacar o capturar\n");
    clearOnKey();

    do
    {
        //Valores iniciales de vidas, velocidad y misiles
        vida = MAXVIDAS[nivel];
        misiles = MAXMISILES[nivel];
        contdecisiones = 1;

        //Instrucciones de nivel
        printf("NIVEL %d\n", nivel + 1);
        printf("Inicia con %d caps. de vida y %d misiles\n", MAXVIDAS[nivel], MAXMISILES[nivel]);
        printf("Si la distancia entre la nave y un planeta esta entre %d y %d km se DEBE evadir el planeta\n", MAXDIST[nivel] - 2000, MAXDIST[nivel]);
        printf("Si la distancia entre un planeta y la nave es menor a %d km la nave choca y pierde el juego\n", MAXDIST[nivel] - 2000);
        printf("Si la distancia entre la nave y el planeta es mayor a %d km la nave sigue su camino\n", MAXDIST[nivel]);
        printf("Si la distancia entre nave y objeto de interes es menor o igual a %d km se ganan %d caps. de vida (No importa la velocidad)\n", MAXDIST[nivel] - 4000, CAPSULAS[nivel]);
        printf("    - Si no se cumplen las condiciones se pierden %d capsulas de vida\n", CAPSULAS[nivel]);
        printf("La nave puede destruir planetas sin vida si la distancia es igual o menor a %d km\n", MAXDIST[nivel] - 2000);
        printf("    - Por cada planeta destruido se pierden %d caps. de vida y %d misiles\n", DESTVIDAS[nivel], DESTMISILES[nivel]);
        printf("    - Al intentar destruir un planeta sin respetar las condiciones se pierden %d caps. y %d misiles\n", NODESTVIDAS[nivel], NODESTMISILES[nivel]);
        printf("Pierdes si tienes menos de %d misiles o menos de %d caps. de vida\n", MAXMISILES[nivel + 1], MAXVIDAS[nivel + 1]);
        clearOnKey();

        while(misiles >= MAXMISILES[nivel + 1] && vida >= MAXVIDAS[nivel + 1] && contdecisiones <= 7)
        {
            //Generar una distancia y velocidad aleatoria
            distancia = (rand() % 15 + 1) * 1000;
            velocidad = (rand() % 30 + 1) * 1000;

            //Display
            printf(MAGENTA "CAPS. VIDA: %d  ",vida);
            printf(WHITE "|" CYAN "  VELOCIDAD: %d km/h  ", velocidad);
            printf(WHITE "|" YELLOW "  MISILES: %d\n", misiles);

            printf(RESET);	

            //Generar objeto al azar
            objeto = rand() % 2;

            //Si se generó un obstáculo
            if(objeto == 0)
            {

                //Mostrar el obstáculo de acuerdo al nivel
                switch(nivel)
                {
                    case 0:
                        //Como hay dos tipos de planeta, generar uno aleatoriamente
                        planeta = rand() % 2;
                        if(planeta == 0)
                            strcpy(obstaculo, BRIGHT_BLUE "PLANETA SIN VIDA");
                        else
                            strcpy(obstaculo, BRIGHT_GREEN "PLANETA CON VIDA");
                        break;
                    case 1:
                        strcpy(obstaculo, BLUE "ASTEROIDE");
                        break;
                    case 2:
                        strcpy(obstaculo, PURPLE "HOYO NEGRO");
                        break;
                }

                printf("Un %s" WHITE " se encuentra a %d km de distancia\n", obstaculo, distancia);

                //Obtener input del usuario    
                do
                {
                    printf("Que desea hacer?\n");
                    printf("Presione[E] para esquivar o [D] para destruir\n");
                    op = getch();

                    switch (op)
                    {
                        //Evitar un obstáculo
                        case 'E': case 'e':
                            if (distancia > MAXDIST[nivel] - 2000)
                                printf("Se esquivo el %s\n", obstaculo);
                            else
                            {
                                printf("Se ha estrellado con el %s\n", obstaculo);
                                vida = 0;
                            }
                            break;
                        //Destruir un obstáculo
                        case 'D': case 'd': 
                            if(nivel == 0 && planeta == 1) //Un planeta sin vida, no se puede destruir
                            {
                                printf("Se ha estrellado con el %s\n", obstaculo);
                                vida = 0;
                            }
                            else if (distancia <= (MAXDIST[nivel] - 2000) && velocidad >= MAXVEL[nivel])
                            {
                                printf("Se destruyo el %s\n", obstaculo);
                                vida -= DESTVIDAS[nivel];
                                misiles -= DESTMISILES[nivel];
                            }
                            else
                            {
                                if(distancia > (MAXDIST[nivel] - 2000) && distancia <= MAXDIST[nivel] && velocidad >= MAXVEL[nivel])
                                {
                                    printf("Debiste haber esquivado\n");
                                    vida = 0;
                                }
                                else
                                {
                                    printf("No has podido destruir el %s\n", obstaculo);
                                    vida -= NODESTVIDAS[nivel];
                                    misiles -= NODESTMISILES[nivel];
                                }
                            }
                            break;
                        default:
                            printf("No presiono una opcion correcta.\n");
                            break;
                        }
                    }
                    while (op != 'e' && op != 'E' && op != 'D' && op != 'd');
            }
            //Si se generó un objeto de interés
            else
            {
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
                            if(distancia <= MAXDIST[nivel] - 4000)
                            {
                                printf("Objeto capturado\n");
                                vida += CAPSULAS[nivel];
                            }
                            else
                            {
                                printf("Objeto no capturado\n");
                                vida -= NOCAPSULAS[nivel];
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
            }

            contdecisiones++;
            clearOnKey();
        } 

        //Compara la cantidad de misiles y de capsulas restantes y define si pierdes o ganas
        if (misiles >= MAXMISILES[nivel + 1] && vida >= MAXVIDAS[nivel + 1])
        {
            nivel++;
            op = 's';
            printf("Ganaste el nivel %d\n", nivel);
            clearOnKey();
        }
        else 
        {
            printf("Perdiste\n");  
            printf(MAGENTA "CAPS. VIDA: %d  ",vida);
            printf(WHITE "|" YELLOW "    MISILES: %d\n", misiles);  

            //obtener input del usuario
            do
            {
                printf(WHITE "Deseas continuar? [s/n]\n");
                op = getch();
                printf("\e[1;1H\e[2J"); //Borrar pantalla

                if(op != 's' && op != 'S' && op != 'N' && op != 'n')
                    printf("No presiono una opcion correcta");
            } while (op != 's' && op != 'S' && op != 'N' && op != 'n');
        } 
    }
    while(op == 's' || op == 'S' && nivel < 3);

    printf("FIN DEL JUEGO\n");  
    clearOnKey();
}