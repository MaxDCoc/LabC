// Declaracion de las bibliotecas que van a usarse en el programa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

// Inicio del programa principal
int main()
{
  typedef struct DATA // Declaracion de registros
  {
    char apenom[35];      // Apellido y Nombre
    char sexo;            // Sexo
    unsigned int dni;     // Dni
    unsigned int edad;    // Edad
    char ciudad[30];      // Ciudad
    unsigned int num_tel; // Numero telefonico
    char sintoma[120];    // Sintoma extra
  } DATA;

  // Declaracion de variables a utilizarse
  FILE *archP;
  FILE *archG;
  DATA *pacientes;
  int cont, extra, opcion, gravedad, codigo, puncom, age;
  int estadistico[3][6];
  char car;

  archP = fopen("pacientes.txt", "a"); // Apertura del archivo pacientes para su escritura en el final del mismo. Si no existe el archivo, lo crea
  archG = fopen("graves.txt", "a");    // Apertura del archivo graves para su escritura en el final del mismo. Si no existe el archivo, lo crea

  // Inicializo el array de registros
  pacientes = NULL;

  // Inicializacion de variables
  gravedad = 0;
  opcion = 1;
  cont = 1;
  extra = 0;
  codigo = 0;
  puncom = 0;
  age = 0;

  // Reservo memoria para el primer registro
  pacientes = (DATA *)malloc(sizeof(DATA));

  // Si no puedo reservar memoria, informa error y finalizo el programa
  if (pacientes == NULL)
  {
    printf("ERROR, NO SE PUDO PROCESAR SU PETICION, ABORTANDO");
    return 1;
  }

  // Inicializacion en cero del array para el informe estadistico
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      estadistico[i][j] = 0;
    }
  }

  // Mientras no se indique que se finalice la introduccion de registros, con el codigo de personal autorizado, realizo el ingreso de los mismos
  while (opcion != 99)
  { // Introduccion de datos basicos de los pacientes
    printf("Ingrese su Nombre y Apellido:");
    fflush(stdin);
    fgets(pacientes[cont - 1].apenom, 35, stdin);
    strtok(pacientes[cont - 1].apenom, "\n");

    printf("Ingrese su DNI:");
    fflush(stdin);
    scanf("%d", &pacientes[cont - 1].dni);

    while (pacientes[cont - 1].sexo != 'M' && pacientes[cont - 1].sexo != 'm' && pacientes[cont - 1].sexo != 'F' && pacientes[cont - 1].sexo != 'f')
    {
      printf("Ingrese su sexo F/M:");
      fflush(stdin);
      scanf("%c", &pacientes[cont - 1].sexo);
      if (pacientes[cont - 1].sexo != 'M' && pacientes[cont - 1].sexo != 'm' && pacientes[cont - 1].sexo != 'F' && pacientes[cont - 1].sexo != 'f')
        printf("Respuesta incorrecta, vuelva a intentar\n");
    }

    printf("Ingrese su edad:");
    fflush(stdin);
    scanf("%d", &pacientes[cont - 1].edad);

    printf("Ingrese su ciudad:");
    fflush(stdin);
    fgets(pacientes[cont - 1].ciudad, 30, stdin);
    strtok(pacientes[cont - 1].ciudad, "\n");

    printf("Ingrese su numero de telefono celular sin el 15:");
    fflush(stdin);
    scanf("%d", &pacientes[cont - 1].num_tel);

    // Se utiliza sleep de medio segundo para no dar un cambio tan abrupto
    Sleep(500);
    printf("\nLe haremos una breve encuesta, por favor contestar con sinceridad las preguntas\n\n");
    opcion = 2;
    Sleep(500);

    // Inicio de la encuesta. La gravedad del mismo se basa en las respuestas que se de
    while (opcion != 0 && opcion != 1)
    {
      printf("Ha tenido dolor de pecho estas ultimas semanas? No=0 Si=1\n");
      printf("RTA:");
      fflush(stdin);
      scanf("%d", &opcion);
      if (opcion == 1 || opcion == 0)
        gravedad += opcion;
      else
        printf("\nOpcion Incorrecta, intente otra vez\n");
    }
    opcion = 2;

    while (opcion != 0 && opcion != 1)
    {
      printf("Ha tenido falta de aire estas ultimas semanas? No=0 Si=1\n");
      printf("RTA:");
      fflush(stdin);
      scanf("%d", &opcion);
      if (opcion == 1 || opcion == 0)
        gravedad += opcion;
      else
        printf("\nOpcion Incorrecta, intente otra vez\n");
    }
    opcion = 2;

    while (opcion != 0 && opcion != 1)
    {
      printf("Ha tenido hinchazon de los pies o los tobillos estas ultimas semanas? No=0 Si=1\n");
      printf("RTA:");
      fflush(stdin);
      scanf("%d", &opcion);
      if (opcion == 1 || opcion == 0)
        gravedad += opcion;
      else
        printf("\nOpcion Incorrecta, intente otra vez\n");
    }
    opcion = 2;

    while (opcion != 0 && opcion != 1)
    {
      printf("Ha tenido latidos cardiacos lentos/acelerados estas ultimas semanas? No=0 Si=1\n");
      printf("RTA:");
      fflush(stdin);
      scanf("%d", &opcion);
      if (opcion == 1 || opcion == 0)
        gravedad += opcion;
      else
        printf("\nOpcion Incorrecta, intente otra vez\n");
    }
    opcion = 2;

    while (opcion != 0 && opcion != 1)
    {
      printf("Ha tenido mareos estas ultimas semanas? No=0 Si=1\n");
      printf("RTA:");
      fflush(stdin);
      scanf("%d", &opcion);
      if (opcion == 1 || opcion == 0)
        gravedad += opcion;
      else
        printf("\nOpcion Incorrecta, intente otra vez\n");
    }
    opcion = 2;

    while (opcion != 0 && opcion != 1)
    {
      printf("Ha tenido erupciones cutaneas o manchas inusuales en la piel? No=0 Si=1\n");
      printf("RTA:");
      fflush(stdin);
      scanf("%d", &opcion);
      if (opcion == 1 || opcion == 0)
        gravedad += opcion;
      else
        printf("\nOpcion Incorrecta, intente otra vez\n");
    }
    opcion = 2;

    while (opcion != 0 && opcion != 1)
    {
      printf("Ha tenido dificultad para respirar al hacer actividad? No=0 Si=1\n");
      printf("RTA:");
      fflush(stdin);
      scanf("%d", &opcion);
      if (opcion == 1 || opcion == 0)
        gravedad += opcion;
      else
        printf("\nOpcion Incorrecta, intente otra vez\n");
    }
    opcion = 2;

    while (opcion != 0 && opcion != 1)
    {
      printf("Desea escribir otro sintoma para que el equipo este informado del mismo? No=0 Si=1\n");
      printf("RTA:");
      fflush(stdin);
      scanf("%d", &opcion);
      if (opcion == 1)
      {
        gravedad += opcion;
        extra = opcion;
      }
      else if (opcion == 0)
        gravedad += opcion;
      else
        printf("\nOpcion Incorrecta, intente otra vez\n");
    }
    if (opcion != 0)
    {
      fflush(stdin);
      fgets(pacientes[cont - 1].sintoma, 120, stdin);
      strtok(pacientes[cont - 1].sintoma, "\n");
    }

    // Si las respuestas fueron un SI en al menos el 50%, se lo trata como un caso grave
    if (gravedad >= 4)
    { // Comunicacion del caso a la persona
      if (pacientes[cont - 1].sexo == 'f' || pacientes[cont - 1].sexo == 'F')
        printf("Queria informarle senora: %s, que usted cuenta con varios sintomas referidos a problemas cardiacos, el equipo se estara comunicando con usted al numero: +549-%d\n", pacientes[cont - 1].apenom, pacientes[cont - 1].num_tel);
      else
        printf("Queria informarle senor: %s, que usted cuenta con varios sintomas referidos a problemas cardiacos, el equipo se estara comunicando con usted al numero: +549-%d\n", pacientes[cont - 1].apenom, pacientes[cont - 1].num_tel);
      // Escritura en el archivo graves
      if (extra == 1)
        fprintf(archG, "%s;\n%c;\n%d;\n%d;\n%s;\n%d;\n%s;\n*\n", pacientes[cont - 1].apenom, pacientes[cont - 1].sexo, pacientes[cont - 1].edad, pacientes[cont - 1].dni, pacientes[cont - 1].ciudad, pacientes[cont - 1].num_tel, pacientes[cont - 1].sintoma);
      else
        fprintf(archG, "%s;\n%c;\n%d;\n%d;\n%s;\n%d;\n*\n", pacientes[cont - 1].apenom, pacientes[cont - 1].sexo, pacientes[cont - 1].edad, pacientes[cont - 1].dni, pacientes[cont - 1].ciudad, pacientes[cont - 1].num_tel);
    }

    // Escritura en el archivo de pacientes
    fprintf(archP, "%s;\n%c;\n%d;\n%d;\n%s;\n%d;\n*\n", pacientes[cont - 1].apenom, pacientes[cont - 1].sexo, pacientes[cont - 1].edad, pacientes[cont - 1].dni, pacientes[cont - 1].ciudad, pacientes[cont - 1].num_tel);

    printf("Ingrese el codigo para finalizar la ejecucion del programa (solo personal autorizado) o ingrese cualquier tecla para finalizar de registrar sus datos y respuestas:");
    scanf("%d", &codigo);

    // Si no se ingresa el codigo, se prepara para la introduccion de un nuevo registro
    if (codigo != 75376)
    {
      printf("%s, su registro fue creado existosamente. Muchas gracias y que tenga buen dia!\n\n", pacientes[cont - 1].apenom);
      cont += 1;
      pacientes = (DATA *)realloc(pacientes, sizeof(DATA) * cont); // Reservo una nueva cantidad de memoria para el nuevo registro en el array
      if (pacientes == NULL)                                       // Si no logro reservar, informo error y finalizo el programa
      {
        printf("ERROR, NO SE PUDO PROCESAR SU PETICION, ABORTANDO");
        return 1;
      }
      opcion = 1;
      gravedad = 0;
      extra = 0;
    }
    else // En cambio, si el codigo fue ingresado correctamente, comienzo el tratamiento del archivo graves
    {
      // Cierro y vuelvo a abrir el archivo, pero esta vez en modo de lectura
      fclose(archG);
      archG = fopen("graves.txt", "r");

      // Leo y, cada vez que encuentro un punto y coma, sumo uno a la variable puncom
      car = fgetc(archG);

      while (!feof(archG))
      {
        if (car == ';')
        {
          puncom += 1;
        }

        if (puncom == 1)
        {

          car = fgetc(archG);
          car = fgetc(archG);

          // Determinacion del genero del registro en tratamiento
          if (car == 'f' || car == 'F')
          {
            estadistico[0][5] += 1;
            estadistico[2][5] += 1;

            car = fgetc(archG);
            car = fgetc(archG);
            car = fgetc(archG);

            // Segun el genero y el rango de edad correspondiente, se suma uno a una de las casillas del informe estadistico
            while (car != ';')
            {
              age = age * 10 + car - 48;
              car = fgetc(archG);
            }

            if (age < 18)
            {
              estadistico[0][0] += 1;
              estadistico[2][0] += 1;
            }
            else if (age >= 18 && age < 28)
            {
              estadistico[0][1] += 1;
              estadistico[2][1] += 1;
            }
            else if (age >= 28 && age < 41)
            {
              estadistico[0][2] += 1;
              estadistico[2][2] += 1;
            }
            else if (age >= 41 && age < 60)
            {
              estadistico[0][3] += 1;
              estadistico[2][3] += 1;
            }
            else if (age >= 60)
            {
              estadistico[0][4] += 1;
              estadistico[2][4] += 1;
            }
          }
          else if (car == 'm' || car == 'M')
          { // Mismo caso para el otro genero
            estadistico[1][5] += 1;
            estadistico[2][5] += 1;

            car = fgetc(archG);
            car = fgetc(archG);
            car = fgetc(archG);

            while (car != ';')
            {
              age = age * 10 + car - 48;
              car = fgetc(archG);
            }

            if (age < 18)
            {
              estadistico[1][0] += 1;
              estadistico[2][0] += 1;
            }
            else if (age >= 18 && age < 28)
            {
              estadistico[1][1] += 1;
              estadistico[2][1] += 1;
            }
            else if (age >= 28 && age < 41)
            {
              estadistico[1][2] += 1;
              estadistico[2][2] += 1;
            }
            else if (age >= 41 && age < 61)
            {
              estadistico[1][3] += 1;
              estadistico[2][3] += 1;
            }
            else if (age > 60)
            {
              estadistico[1][4] += 1;
              estadistico[2][4] += 1;
            }
          }

          puncom = 2;
          age = 0;
        }
        // Al encontrar un nuevo registro, se reinician las variables utilizadas
        if (car == '*')
        {
          puncom = 0;
          age = 0;
        }
        car = fgetc(archG);
      }

      // Salgo del mientras con el valor indicado
      opcion = 99;

      // Impresion por pantalla del informe estadistico. PREGUNTAR POR LA SOBREESCRITURA O NO DEL ARCHIVO
      printf("\nInforme estadistico del dia:\n");
      printf("------------------------------------------------------------------|\n");
      printf("----------|                   EDADES                  |-----------|\n");
      printf("------------------------------------------------------------------|\n");
      printf("  SEXO   |<18|>=18 y <28||>=28 y <41|>=41 y <60||>=60 ||TOTALxSEXO|\n");
      printf("------------------------------------------------------------------|\n");
      printf("FEMENINO | %d |     %d    |     %d     |     %d    |   %d   |     %d    |\n", estadistico[0][0], estadistico[0][1], estadistico[0][2], estadistico[0][3], estadistico[0][4], estadistico[0][5]);
      printf("------------------------------------------------------------------|\n");
      printf("MASCULINO| %d |     %d    |     %d     |     %d    |   %d   |     %d    |\n", estadistico[1][0], estadistico[1][1], estadistico[1][2], estadistico[1][3], estadistico[1][4], estadistico[1][5]);
      printf("------------------------------------------------------------------|\n");
      printf("TOTxEDAD | %d |     %d    |     %d     |     %d    |   %d   |     %d    |\n", estadistico[2][0], estadistico[2][1], estadistico[2][2], estadistico[2][3], estadistico[2][4], estadistico[2][5]);
      printf("------------------------------------------------------------------|\n");
    }
  }

  // Libero la memoria del array de registros
  free(pacientes);

  // Cierro los archivos y en caso de error, informo por pantalla
  if ((fclose(archP) != 0) && (fclose(archG) != 0))
  {
    printf("ERROR AL CERRAR EL ARCHIVO!\n");
    return 1;
  }
  Sleep(20000);
  return 0;
}