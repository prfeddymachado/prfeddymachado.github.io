#include <stdio.h>
#include <stdlib.h>

int main() {
	// El modo "a+" permite agregar datos al final del archivo y leerlos al mismo tiempo
	FILE *f = fopen("registro.log", "a+");
	if (f == NULL) {
		perror("Error crítico al ejecutar fopen");
		return EXIT_FAILURE;
	}
	
	// Escritura automatizada utilizando macros del compilador
	fprintf(f, "Log generado de forma automatica en la fecha: %s\n", __DATE__);
	
	// Reposicionamos el flujo al inicio para proceder con la lectura completa
	rewind(f);
	
	char buffer[100];
	while (fgets(buffer, sizeof(buffer), f) != NULL) {
		printf("%s", buffer);
	}
	
	// Control del cierre del flujo para verificar la correcta liberación por el Sistema Operativo
	if (fclose(f) == EOF) {
		perror("Error crítico al ejecutar fclose");
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
