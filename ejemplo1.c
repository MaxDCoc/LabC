#include <stdio.h>
#include <math.h>
#define PI 3.14

int main()
{
    int radio;
    float vol;

    printf("Tirame un radio:");
    scanf("%d", &radio);

    vol = (4 / 3) * PI * pow(radio, 3);

    printf("El volumen de tu orto es este, crack: %f", vol);

    return 0;
}