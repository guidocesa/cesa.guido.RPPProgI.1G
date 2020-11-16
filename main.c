#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float aplicarDescuento(float precioOriginal)
{
    float precioConDescuento = (precioOriginal * 0.95);

    return precioConDescuento;
}

int contarCaracteres(char* cadena, char caracterContado)
{
    int contador = 0, i = 0;
    char aux;
    do{
        aux = *(cadena + i);
        if(aux == caracterContado)
        {
            contador++;
        }
        i++;
    }while(aux != '\0');
    return contador;
}

typedef struct
{
    int id;
    char procesador[30];
    char marca[30];
    float precio;
}eNotebook;

void ordenarArray(eNotebook* notebooks, int tam)
{
    eNotebook aux;
    for(int i = 0; i < tam -1; i++)
    {
        for(int j = 0; j < (tam - 1 -i); j++)
        {
            if(strcmp(notebooks[j].marca, notebooks[j+1].marca) < 0)
            {
                aux = notebooks[j];
                notebooks[j] = notebooks[j+1];
                notebooks[j+1] = aux;
            }
            else
            {
                if(strcmp(notebooks[j].marca, notebooks[j+1].marca) == 0 && notebooks[j].precio > notebooks[j+1].precio)
                {
                    aux = notebooks[j];
                    notebooks[j] = notebooks[j+1];
                    notebooks[j+1] = aux;
                }
            }
        }
    }
}



int main()
{
    float a = 100.00;
    printf("%.2f\n" , aplicarDescuento(a) ); //El precio con descuento deberia ser $95.00

    printf("%i", contarCaracteres("Hola, mi nombre es Guido.", 'o')); //El resultado deberia ser 3.

    eNotebook notebooks[5];

    for(int i = 0; i < 5; i++)
    {
        notebooks[i].id = i;
    }
    for(int i = 0; i < 5; i++)
    {
        notebooks[i].precio = (i * 1250.95);
    }

    ordenarArray(notebooks, 5); //No llegue a harcodear los nombres y marcas.


    return 0;
}
