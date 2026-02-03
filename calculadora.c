#include <stdio.h>
#include <string.h>

struct Gasto {
    char fecha[12];
    char descripcion[50];
    float monto;
};
// BLOQUE RECURSIVO: Calcula la suma total de los montos recorriendo el arreglo de forma recursiva
float sumarGastosRecursivo(struct Gasto gastos[], int n, int i) {
    if (i >= n) { // Caso base: cuando el índice alcanza el número total de gastos
        return 0;
    }
    return gastos[i].monto + sumarGastosRecursivo(gastos, n, i + 1);
}

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
        // BLOQUE DE CONTROL DE ENTRADA: Valida que el usuario ingrese un número entero
        // Si el usuario ingresa letras, scanf falla y el bucle limpia el buffer para evitar errores
        if (scanf("%d", &opcion) != 1) {
            printf("Error: Por favor, ingrese un numero del menu.\n");
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
                    while (scanf("%f", &misGastos[n].monto) !=1 || misGastos[n].monto < 0){
                        printf("Error: Ingrese un monto numerico valido (positivo): ");
                        while (getchar() != '\n');
                    }
                    n++;
                    printf("Gasto registrado.\n");
                } else {
                    printf("Limite de gastos alcanzado.\n");
                }
                break;

            case 2: {
            // REGISTRO DE INGRESOS: Acumula montos positivos en la variable de ingresos
                float nuevoIngreso;
                printf("Monto del ingreso: ");
                // Validación para evitar datos corruptos en el balance
                while (scanf("%f", &nuevoIngreso) != 1 || nuevoIngreso < 0) {
                    printf("Error: Ingrese un monto numerico valido: ");
                    while (getchar() != '\n');
                }
                ingresos += nuevoIngreso;
                printf("Ingreso registrado. Total actual: %.2f\n", ingresos);
                break;
            }

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