
//Integrantes: Mateo Mero, Juan Yepes, Juliano Toapanta 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int id, stock = 0, opcion, cantidad;
    char nombre[50];
    float precio = 0.0, ganancias = 0.0, descuento = 0.0;

    printf("Registro del producto:\n");
    printf("Ingrese ID del producto: ");
    scanf("%d", &id);
    getchar(); // limpiar buffer
    printf("Ingrese nombre del producto: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // eliminar salto de línea
    printf("Ingrese cantidad en stock: ");
    scanf("%d", &stock);
    printf("Ingrese precio unitario: ");
    scanf("%f", &precio);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Consultar información\n");
        printf("4. Mostrar ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese cantidad a vender: ");
                scanf("%d", &cantidad);
                if (cantidad <= 0) {
                    printf("Cantidad inválida. Debe ser mayor que cero.\n");
                    break;
                }
                if (cantidad > stock) {
                    printf("Stock insuficiente. Solo hay %d unidades disponibles.\n", stock);
                    break;
                }
                printf("Ingrese descuento (%%): ");
                scanf("%f", &descuento);
                if (descuento < 0 || descuento > 100) {
                    printf("Descuento inválido. Debe estar entre 0 y 100.\n");
                    break;
                }
                float precioFinal = precio * (1 - descuento / 100);
                ganancias += precioFinal * cantidad;
                stock -= cantidad;
                printf("Venta realizada. Precio final por unidad: %.2f\n", precioFinal);
                break;

            case 2:
                printf("Ingrese cantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                if (cantidad <= 0) {
                    printf("Cantidad inválida. Debe ser mayor que cero.\n");
                    break;
                }
                stock += cantidad;
                printf("Stock actualizado. Nuevo stock: %d\n", stock);
                break;

            case 3:
                printf("\n--- Información del producto ---\n");
                printf("ID:\t%d\n", id);
                printf("Nombre:\t%s\n", nombre);
                printf("Stock:\t%d\n", stock);
                printf("Precio:\t%.2f\n", precio);
                break;

            case 4:
                printf("Ganancias acumuladas: $%.2f\n", ganancias);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }

    } while(opcion != 5);

    return 0;
}
    1