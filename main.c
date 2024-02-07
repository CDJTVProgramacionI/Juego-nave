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
        int totcapsulas=2000,totmisiles=8000;
	char decision;
	float distancia,velocidad;
	switch(decision)
	{
		/*a=capturar objetos
		b=destruir planetas*/
		case 'a':
			if(distancia<=6000)
			{
				totcapsulas=totcapsulas+5;break;
			}
			else
			{
				totcapsulas=totcapsulas-3;break;
			}
		case 'b':
			if(distancia<=8000 && velocidad>=12000)
			{
				totcapsulas=totcapsulas-25;break;
				totmisiles=totmisiles-50;break;
			}
			else
			{
				totcapsulas=totcapsulas-15;break;
				totmisiles=totmisiles-30;break;
			}
			
	}
	

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
        int op;

        if (distancia>=10000 && velocidad>12000)
        printf("Se esquivo el planeta.");
        else if (distancia>=8000 && distancia<10000)
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
        else if (distancia<8000)
        printf("Se ha estrellado con el planeta");
        else if (distancia<6000)
        printf("Desea agarrar un objeto de interes");

    


        //Decisiones para capsulas
    } 
}

