#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int menu() {
	int opcion;
	do {
		printf("\n1. Afegir llibre\n");
		printf("2. Borrar llibre\n");
		printf("3. Llistar biblioteca\n");
		printf("4. Buscar por autor\n");
		printf("5. Mostrar libros que superen la media de ventas\n");
		printf("0. Sortir\n");
		scanf("%d", &opcion);

	} while (opcion>5 || opcion<0);
	return opcion;
}

int comprobarisbn(libro lib[], char isbn2[], int longi){
	int i = 0;


	while (strcmp(lib[i].isbn, isbn2) != 0 && i < longi) {
		i++;
	}

	return i;
}

int posicionlibre(libro lib[], int longi){
	int i = 0;
	while (lib[i].isbn[0] != '\0' && i<longi){
		i++;
	}
	return i;
	
}

void afegirllibre(libro *lib, char isbn2[]){
	
	    strcpy(lib->isbn, isbn2);
		printf("Introduce el titulo: \n");
		gets(lib->titol);
		//scanf("%s", lib->titol);
		fflush(stdin);
		printf("Introduce editorial: \n");
		//scanf("%s", lib->editorial);
		gets(lib->editorial);
		fflush(stdin);
		printf("Introduce el autor: \n");
		gets(lib->autor);
		fflush(stdin);
		printf("Introduce las ventas del libro: \n");
		scanf("%f", &lib->ventas);
		do {
			printf("Introduce any de edicion: \n");
			scanf("%d", &lib->any);
		} while (lib->any < 0 || lib->any > 2016);
		do {
			fflush(stdin);
			printf("Introduce precio libro: \n");
			scanf("%f", &lib->preu);
			
		} while (lib->preu < 0);
		
		printf("Libro añadido correctamente\n");
		
	}

void borrarlibros(libro *lib) {
	lib->isbn[0] = '\0';
	lib->titol[0] = '\0';
	lib->editorial[0] = '\0';
	lib->autor[0] = '\0';
	lib->any = 0;
	lib->preu = 0;
	lib->ventas = 0;
}

void mostrarlibro(libro lib) {
	printf("\nDATOS DEL LIBRO SELECCIONADO\n");
	printf("<-------------------------->\n");
	printf("ISBN: %s\n", lib.isbn);
	printf("Titol: %s\n", lib.titol);
	printf("Editorial: %s\n", lib.editorial);
	printf("Anyo edicion: %d\n", lib.any);
	printf("Autor: %s\n", lib.autor);
	printf("Ventas: %.2f\n", lib.ventas);
	printf("Preu: %.2f\n", lib.preu);

}

int comprobarautor(libro lib, char autor2[], int longi){
	int i=0;
	while (strcmp(lib.autor, autor2) != 0 && i < longi) {
		i++;
	}
	return i;
}

float mediatotal(libro lib[], int longi){
	float media = 0;
	int e, i=0;
	for (e = 0; e < longi; e++){
		if (lib[e].isbn[0] != '\0'){
			media = media + lib[e].ventas;
			i++;
		}
	}
	media = media / i;

	return media;
}

void copiararray(libro lib, libro *lib2){
	
	strcpy(lib2->isbn, lib.isbn);
	strcpy(lib2->titol, lib.titol);
	strcpy(lib2->editorial, lib.editorial);
	strcpy(lib2->autor, lib.autor);
	lib2->any = lib.any;
	lib2->preu = lib.preu;
	lib2->ventas = lib.ventas;
}

int comprobarlibro(libro lib[], int longi){
	int i = 0;
	while (lib[i].isbn[0] == '\0' && i<longi){
		i++;
	}
	return i;
}