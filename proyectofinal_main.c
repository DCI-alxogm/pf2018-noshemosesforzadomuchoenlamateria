/*Proyecto final, José Misael Rojas Sánchez (Josemi213), Brandon Emmanuel Hernandez Corona (BrandonIB) */



//Declaramos las librerias que utilizaremos.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
#include <time.h>





float main()
{
FILE*fp=NULL; //SE ABRE ARCHIVO DE LECTURA
char*nombrearchivo="entrada.txt";


 float entradax[8], entraday[8], entradaz[8];//DECLARACIÓN DE VARIABLES


 //SE DEFINEN PUNTEROS:
 float*entradamemx;
 float*entradamemy;
 float*entradamemz;


 //SE DEFINE MEMORIA
 entradamemx=malloc(8*sizeof(float));
 entradamemy=malloc(8*sizeof(float));
 entradamemz=malloc(8*sizeof(float));



 //LECTURA DE ENTRADA (COORDENADAS DE CUBO 3X3)
 int i=0;
 fp = fopen(nombrearchivo, "r");
 if(fp==NULL)return -1;
 for (i=0;i<8;i++)
 {
     fscanf(fp,"%f %f %f",&entradax[i],&entraday[i],&entradaz[i]);
     entradamemx=&entradax[i];
     entradamemy=&entraday[i];
     entradamemz=&entradaz[i];


     //SE IMPRIMEN VALORES DE MATRIZ CUBO
     printf("%f\n", entradax[i]);
     printf("%f\n", entraday[i]);
     printf("%f\n", entradaz[i]);
     //printf("%p\n", entradamem);
     //printf("%f\n", *entradamemx);
 }

//float matrizentrada[3][8];



//LECTURA DE MATRIZ ALEATORIA GENERADA POR OTRA FUNCION
FILE*fp2=NULL;
char*nombrearchivo2="aleatoria.txt";
fp2 = fopen(nombrearchivo2, "r");
float entrada_aleatoria_x[8], entrada_aleatoria_y[8], entrada_aleatoria_z[8];
int a;
if(fp==NULL)return -1;
printf("\naleatorios:\n\n");


//SE IMPRIMEN VALORES DE MATRIZ ALEATORIA
for (a=0;a<8;a++)
{
     fscanf(fp2,"%f %f %f",&entrada_aleatoria_x[i],&entrada_aleatoria_y[i],&entrada_aleatoria_z[i]);
     printf("%f\n", entrada_aleatoria_x[i]);
     printf("%f\n", entrada_aleatoria_y[i]);
     printf("%f\n", entrada_aleatoria_z[i]);
}


//USUARIO ELIGE TIPO DE ESTIMADOR
int opcion;
printf("\nSi quieres utilizar estimador simple presiona 1 \no presiona 2 para Landy-Szalay\n");
scanf("%i", &opcion);
	switch(opcion){
    case 1:
    printf("Estimador Simple activo");
			 //Es=((nR/nD)*(DD/RR))-1;
    break;
    case 2:
    printf("Estimador Landy-Szalay activo\n");
			//Els=((DD/nD)-(2*DR/nDR)+(RR/nR))/(RR/nR);
    break;
	}


return 0;
}
