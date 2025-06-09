//Practicar con registros
#include <stdio.h>

int main ()
{
    FILE * dir_path = fopen("texto.txt","r");
    char caracter;

    if(dir_path == NULL)
    {
        printf("Error al leer el archivo\n");
        return 1;
    }

    printf("Fue posible leer el archivo!\n");

    printf("A partir de aca se lee el archivo:\n\n");
    caracter = fgetc(dir_path);

    while(feof(dir_path) == 0)
    {
        printf("%c",caracter);
        caracter = fgetc(dir_path);
    }

    return 0;
}