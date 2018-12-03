/*Proyecto final, José Misael Rojas Sánchez (Josemi213), Brandon Emmanuel Hernandez Corona (BrandonIB) */

//Declaramos las librerias que utilizaremos.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
FILE*fp=NULL;
char*nombrearchivo="entrada";
 float entrada[24];
 float*entradamem;
 entradamem=malloc(24*sizeof(float));
 int i=0;
 fp = fopen(nombrearchivo, "r");
 if(fp==NULL)return -1;
 for (i=0;i<=24;i++)
 {
     fscanf(fp,"%f",&entrada[i]);
     entradamem=&entrada[i];
     //printf("%f\n", entrada[i]);
     //printf("%p\n", entradamem);
     printf("%f\n", *entradamem);
 }

return 0;
}
