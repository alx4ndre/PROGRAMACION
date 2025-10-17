#include <stdio.h>

int main() {
    const int estudiantes = 5;
    const int asignatura = 3;
    const float notaParaAprobar = 6.0;

    float nota;
    float suma;

    float promEstudiantes[estudiantes];
    float NotaMaxEstudiantes[estudiantes];
    float NotaMinEstudiantes[estudiantes];

    float PromedioAsignatura[asignatura];
    int AprobadosAsignatura[asignatura];
    int ReprobadosAsignatura[asignatura];
    float NotaMaxAsignatura[asignatura];
    float NotaMinAsignatura[asignatura];

    for (int j = 0; j < asignatura; j++) {
        PromedioAsignatura[j] = 0.0;
        NotaMaxAsignatura[j] = 0.0;
        NotaMinAsignatura[j] = 10.0;
        AprobadosAsignatura[j] = 0;
        ReprobadosAsignatura[j] = 0;
    }

    printf("     INGRESO DE CALIFICACIONES (0 a 10)       \n");

    for (int i = 0; i < estudiantes; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        suma = 0.0;
        float maximo = 0.0;
        float minimo = 10.0;

        for (int j = 0; j < asignatura; j++) {
            do {
                printf("  Asignatura %d: ", j + 1);
                if (scanf("%f", &nota) != 1) {
                    printf("  Error: Ingrese un número.\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != 0) { }
                    nota = -1.0;
                } else if (nota < 0.0 || nota > 10.0) {
                    printf("  Error: La calificacion debe estar entre 0 y 10.\n");
                }
            } while (nota < 0.0 || nota > 10.0);

            suma += nota;
            if (nota > maximo){
                maximo = nota;
            }
            if (nota < minimo){
                minimo = nota;
            }

            PromedioAsignatura[j] += nota;
            if (nota > NotaMaxAsignatura[j]) {
                NotaMaxAsignatura[j] = nota;
            }
            if (nota < NotaMinAsignatura[j]){
                NotaMinAsignatura[j] = nota;
            }
            if (nota >= notaParaAprobar){
                AprobadosAsignatura[j]++;
            }
            else ReprobadosAsignatura[j]++;
        }

        promEstudiantes[i] = suma / asignatura;
        NotaMaxEstudiantes[i] = maximo;
        NotaMinEstudiantes[i] = minimo;
    }

    for (int j = 0; j < asignatura; j++) {
        PromedioAsignatura[j] /= estudiantes;
    }



    printf("-------RESULTADOS DEL ANALISIS-------\n");


    printf("\n PROMEDIOS POR ESTUDIANTE\n");
    for (int i = 0; i < estudiantes; i++) {
        printf("\nEstudiante %d\n", i + 1);
        printf("Promedio: %.2f\n", promEstudiantes[i]);
        printf("---------------------------");
    }

    printf("\n CALIFICACIONES ALTAS Y BAJAS POR ESTUDIANTE\n");
    for (int i = 0; i < estudiantes; i++) {
        printf("\nEstudiante %d\n", i + 1);
        printf("  Maxima: %.2f\n", NotaMaxEstudiantes[i]);
        printf("  Mínima: %.2f\n", NotaMinEstudiantes[i]);
        printf("---------------------------");
    }

    printf("\n  PROMEDIOS POR ASIGNATURA\n");
    for (int j = 0; j < asignatura; j++) {
        printf("\nAsignatura %d\n", j + 1);
        printf("Promedio general: %.2f\n", PromedioAsignatura[j]);
        printf("---------------------------");
    }

    printf("\n CALIFICACIONES ALTAS Y BAJAS POR ASIGNATURA\n");
    for (int j = 0; j < asignatura; j++) {
        printf("\nAsignatura %d\n", j + 1);
        printf("  Maxima: %.2f\n", NotaMaxAsignatura[j]);
        printf("  Mínima: %.2f\n", NotaMinAsignatura[j]);
        printf("---------------------------");
    }

    printf("\n RESULTADOS DE APROBACION \n");
    for (int j = 0; j < asignatura; j++) {
        printf("\nAsignatura %d\n", j + 1);
        printf("  Aprobados: %d\n", AprobadosAsignatura[j]);
        printf("  Reprobados: %d\n", ReprobadosAsignatura[j]);
        printf("---------------------------");
    }

    printf("\n-------FIN-------\n");
    return 0;
}
