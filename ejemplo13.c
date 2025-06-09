// Programa que te dice si son numeros palindromos

#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0, inv = 0;

    printf("Te voy a decir si dos numeros son palindromos, master\n");

    printf("Primero, tirame un numero, crack:");
    scanf("%d", &num1);

    printf("Ahora tirame el segundo 7w7:");
    scanf("%d", &num2);

    while (num1 != 0)
    {
        inv *= 10;
        inv += num1 % 10;
        num1 /= 10;
    };

    if (num2 == inv)
        printf("Son palindromos master!\n");
    else
        printf("Una pena viejo, no son palindromos, la baja una locura\n\n");

    printf("Chau maquina, espero haberte ayudado, suerte en la vida!");
    return 0;
}