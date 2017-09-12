#define MAX 5

typedef struct {
	char isbn[19];
	char titol[51];
	char editorial[31];
	char autor[31];
	int any;
	float ventas;
	float preu;
}libro;
#include "funciones.h"

void main() {
	int i, plibre, opc, o, pos, u, aux1, e, a=0;
	libro libros[MAX], librosventas[MAX];
	char isbn[19], resp, autor[31];
	float media;

	for (i = 0; i < MAX; i++) {
		borrarlibros(&libros[i]);
	}
	do {
		opc = menu();
		switch (opc) {
		case 1:
			plibre = posicionlibre(libros, MAX);
			if (plibre != MAX) {

				printf("Introduzca el ISBN que quieres anadir: \n");
				fflush(stdin);
				gets(isbn);
				//scanf("%s", isbn);

				if (comprobarisbn(libros, isbn, MAX) == MAX){

					afegirllibre(&libros[plibre], isbn);
				}
				else {
					printf("Tienes un libro con el mismo ISBN\n");
				}
			}
			else {
				printf("No hay huecos libres para mas libros\n");
			}
			break;

		case 2:
			printf("Introduzca el ISBN del libro que quieres borrar: \n");
			fflush(stdin);
			gets(isbn);
			//scanf("%s", isbn);
			pos = comprobarisbn(libros, isbn, MAX);
			if (pos != MAX) {
				mostrarlibro(libros[pos]);
				fflush(stdin);
				printf("\nQuieres eliminarlo? (s/n)\n");
				scanf("%c", &resp);
				if (resp == 's') {
					borrarlibros(&libros[pos]);
				}
				else{
					printf("\nCancelando operacion..\n");
				}
			}
			else {
				printf("No hay ningn libro con ese ISBN\n");
			}
			break;
		case 3:
			for (o = 0; o < MAX; o++) {
				if (libros[o].isbn[0] != '\0') {

					mostrarlibro(libros[o]);

				}
			}
			break;
		case 4:

			printf("Introduce el autor a buscar: \n");
			fflush(stdin);
			gets(autor);
			/*while (comprobarautor(libros[a], autor, MAX) != MAX && a < MAX){
				a++;
			}
			if (a == MAX){
				printf("\nNo hay ningun libro de este autor:\n");
			} no he conseguido hacer el paso de comprobar si no hay ningu autor con libros
			*/

				for (u = 0; u < MAX; u++){
					aux1 = comprobarautor(libros[u], autor, MAX);
					if (aux1 == 0){
						mostrarlibro(libros[u]);
					}


				}
			
			break;
		case 5:
			printf("La media de ventas es : %f", mediatotal(libros, MAX));
			if (comprobarlibro(libros, MAX) == MAX){
				printf("No hay ningu libro en la bilbioteca\n");
				
			}
			else{
				for (e = 0; e < MAX; e++){
					if (libros[e].ventas > mediatotal(libros, MAX)){
						copiararray(libros[e], &librosventas[e]);
						mostrarlibro(librosventas[e]);
					}
					
				}
				
			}
			
		}
		
	} while (opc != 0);




	system("pause");
}












	
	
	

	







	
	
	
