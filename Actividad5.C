#include <stdio.h>

int comparaCads(char*, char*);
int longCad(char*);
char* copiaCad(char*, char*);
char* concatenaCad(char*, char*);
int subcadena(char*, char*);
void menu();
void leerCadenas(char*, char*);
void joctan();

//Programa con funciones del manejo de cadenas
int main(){
	
	char zerone[50];
	char zerotwo[50];
	char option;
	
	
	do{
		menu();
		scanf("%c", &option);
		printf("\n");
		fflush(stdin);
		joctan();
		switch(option){
			/*
			Declaration of new variables in case statements cause problems.
			Enclosing all case statements in {} will limit the scope of newly declared 
			variables to the currently executing case
			*/
			case 'A':
			case 'a':{
				printf("Comparar dos cadenas lexicograficamente\n\n");
				leerCadenas(zerone, zerotwo);
				int resultado = comparaCads(zerone, zerotwo);
				if (resultado == 1)
					printf("\nLa primer cadena es mayor\n");
				else if (resultado == -1)
					printf("\nLa segunda cadena es mayor\n");
				else
					printf("\nLas dos cadenas son iguales\n");									
				break;
			}
			case 'B':
			case 'b':{
				printf("Escribe una cadena y te dire su longitud\n");
				gets(zerone);
				int longitud = longCad(zerone);
				printf("\nLa longitud de la cadena es: %d\n", longitud);
				
				break;
			}
			
			case 'C':
			case 'c':{
				printf("Copiar la segunda cadena en la primer cadena\n\n");
				leerCadenas(zerone, zerotwo);
				copiaCad(zerone, zerotwo);
				printf("\nPrimer cadena: %s", zerone);
				printf("\nSegunda cadena: %s\n", zerotwo);
				break;
			}
			case 'D':
			case 'd':{
				printf("Concatenar la segunda cadena en el fin de la primera\n\n");
				leerCadenas(zerone, zerotwo);
				concatenaCad(zerone, zerotwo);
				printf("\nPrimer cadena: %s", zerone);
				printf("\nSegunda cadena: %s\n", zerotwo);
				break;
			}
			case 'E':
			case 'e':{
				printf("Comprobar si la primer cadena es subcadena de la segunda\n\n");
				leerCadenas(zerone, zerotwo);
				if (subcadena(zerone, zerotwo) == 1)
					printf("\nLa primera cadena es subcadena de la segunda\n");
				else
					printf("\nNo es subcadena\n");
				break;
			}
			case 'F':
			case 'f':
				printf("Hasta luego\n");
				break;
		}
		joctan();
		printf("\n");
	}while (option != 'f');
	
	return 0;
}

void menu(){
	printf("a) Comparar lexicograficamente dos cadenas de caracteres");
	printf("\nb) Calcular la longitud de una cadena de caracteres");
	printf("\nc) Copiar una cadena dentro de otra");
	printf("\nd) Concatenar dos cadenas");
	printf("\ne) Comprobar si una cadena es subcadena de otra");
	printf("\nf) Salir\n");
	printf("\nTeclea la opcion a realizar:\n");
}

void joctan(){
	for (int i = 0; i < 50; i++)
		printf("-");
	printf("\n");
}

void leerCadenas(char* cad1, char* cad2){
	printf("Escribe la primera cadena\n");
	gets(cad1);
	
	printf("\nEscribe la segunda cadena\n");
	gets(cad2);
}


int comparaCads(char* cad1, char* cad2){
	int i;
	
	while (*(cad1 + i) != '\0' && *(cad2 + i) != '\0'){
		
		if (*(cad1 + i) < *(cad2 + i))
			return -1;
		else if (*(cad1 + i) > *(cad2 + i))
			return 1;
		
		i++;
	}
	
	return 0;
}

int longCad(char* cadena){
	int i = 0;
	
	while (*(cadena + i) != '\0')
		i++;
	
	return i;
}

char* copiaCad(char* cad1, char* cad2){
	int i = 0;
	
	while (*(cad2 + i) != '\0'){
		*(cad1 + i) = *(cad2 + i);
		i++;
	}
	
	*(cad1 + i) = '\0'; //Cerrar la cadena
		
	return cad1;
}

char* concatenaCad(char* cad1, char* cad2){
	
	int i = 0;
	int j = longCad(cad1);
	
	while (*(cad2+ i) != '\0'){
		*(cad1 + j) = *(cad2 + i);
		j++;
		i++;
	}
	
	*(cad1 + j) = '\0'; //Cerrar la cadena
		
	return cad1;
}

int subcadena(char* cad1, char* cad2){
	
	int i, j = 0;
	
	while(*(cad2 + i) != '\0'){
		j = 0;
		while (*(cad1 + j) != '\0'){
			
			if (*(cad1 + j) != *(cad2 + i + j))
				break;
			j++;
			
			if (*(cad1 + j) == '\0')
				return 1;
		}
		i++;
	}
	return 0;
}
