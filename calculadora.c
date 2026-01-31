#include <stdio.h>
#include <string.h>

struct Gasto {
    char fecha[12];
    char descripcion[50];
    float monto;
};

int main() {
    struct Gasto misGastos[100];
    int n = 0;
    int opcion;
    float ingresos = 0;

    do {
        printf("\n--- Menu de Finanzas ---\n");
        printf("1. Anotar gasto\n");
        printf("2. Anotar ingreso\n");
        printf("3. Ver estado de cuenta\n");
        printf("4. Guardar datos\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;
        }

        switch(opcion) {
            case 1:
                if (n < 100) {
                    while (getchar() != '\n');
                    printf("Fecha: ");
                    fgets(misGastos[n].fecha, 12, stdin);
                    misGastos[n].fecha[strcspn(misGastos[n].fecha, "\n")] = 0;

                    printf("Descripcion: ");
                    fgets(misGastos[n].descripcion, 50, stdin);
                    misGastos[n].descripcion[strcspn(misGastos[n].descripcion, "\n")] = 0;

                    printf("Monto: ");
                    scanf("%f", &misGastos[n].monto);
                    n++;
                    printf("Gasto registrado.\n");
                } else {
                    printf("Limite de gastos alcanzado.\n");
                }
                break;

            case 2:
                printf("Monto del ingreso: ");
                float nuevoIngreso;
                scanf("%f", &nuevoIngreso);
                ingresos += nuevoIngreso;
                printf("Ingreso registrado.\n");
                break;

            case 3:
                printf("\n--- Estado Actual ---\n");
                printf("Total ingresos: %.2f\n", ingresos);
                printf("Gastos registrados: %d\n", n);
                break;

            case 4:
                printf("Guardando informacion...\n");
                break;

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 0);

    return 0;
}