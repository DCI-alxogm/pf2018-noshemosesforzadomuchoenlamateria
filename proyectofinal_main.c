/*Proyecto final, José Misael Rojas Sánchez (Josemi213), Brandon Emmanuel Hernandez Corona (BrandonIB) */



//Declaramos las librerias que utilizaremos.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
#include <time.h>


void ESTIMADOR1(float[],float[],float[]);
void ESTIMADOR2(float[],float[],float[]);


float main()
{
FILE*fp=NULL; //SE ABRE ARCHIVO DE LECTURA
char*nombrearchivo="entrada.txt";


float entradax[8], entraday[8], entradaz[8], r[24];//DECLARACIÓN DE ALGUNAS VARIABLES


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
 printf("\nSimples:\n\n");
 for (i=0;i<8;i++)
 {
     fscanf(fp,"%f %f %f",&entradax[i],&entraday[i],&entradaz[i]);
     entradamemx=&entradax[i];
     entradamemy=&entraday[i];
     entradamemz=&entradaz[i];


     //SE IMPRIMEN VALORES DE MATRIZ CUBO
     printf("%.0f\t%.0f\t%.0f\n", entradax[i],entraday[i],entradaz[i]);
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
     printf("%.0f\t%.0f\t%.0f\n", entrada_aleatoria_x[i],entrada_aleatoria_y[i],entrada_aleatoria_z[i]);
}

//USUARIO ELIGE TIPO DE ESTIMADOR
int opcion;
printf("\nMENU TIPO ESTIMADOR\n\n1. Estimador simple\n2. Estimador Landy-Szalay\n\nSeleccione una opcion: ");
scanf("%i", &opcion);
	switch(opcion){
    case 1:
    ESTIMADOR1(entradax,entraday,entradaz);
    printf("\nEstimador Simple activo\n");
    break;

    case 2:
    ESTIMADOR2(entrada_aleatoria_x,entrada_aleatoria_y,entrada_aleatoria_z);
    printf("\n\nEstimador Landy-Szalay activo\n\n");
    break;
	}


return 0;
}

void ESTIMADOR1(float entradax[], float entraday[], float entradaz[])
{
    float DD=1,RR=1,nR=0, nD=0, nDR=0, E=0, temp=0,l,m=0;
    FILE*fp=NULL; //SE ABRE ARCHIVO DE LECTURA
    //CÁLCULOS:
int i,j;
char t;
////////////////////////////////////////////////////////////////
//CÁLCULOS DE ENTRADA:
fp = fopen("entrada.txt", "r");
while((t=fgetc(fp))!=EOF)
{
if(t=='\n')
{
temp++;
}
}
fclose(fp);
for(l=temp-1;l>0;l--)
{
nD+=l;
}
nR=temp;

    fp=fopen("EstimadorSimple.txt","w"); E=((nR/nD)*(DD/RR))-1; fprintf(fp,"%f",E); printf("\nEstimador: %.2f\n",E); fclose(fp);
}

void ESTIMADOR2(float entrada_aleatoria_x[], float entrada_aleatoria_y[], float entrada_aleatoria_z[])
{
    float DD=0,RR[24],nR=0, nD=0, nDR=0, E=0, temp=0,l,m=0,DR[24], dR,rR;
    FILE*fp=NULL; //SE ABRE ARCHIVO DE LECTURA
    //CÁLCULOS:
int i,j;
char t;

//CÁLCULOS DE ALEATORIA:
fp=fopen("aleatoria.txt","r");
while((t=fgetc(fp))!=EOF)
{
if(t=='\n')
{
temp++;
}
}
fclose(fp);
for(i=temp-1;i>0;i--)
{
nR+=i;
}
temp+=nDR;
nDR=0;
for(i=temp-1;i>0;i--)
{
nDR+=i;
}
//r:
for(i=0;i<temp;i++)
{
for(j=i+1;j<temp;j++)
{
rR=sqrt(pow((entrada_aleatoria_x[i]-entrada_aleatoria_x[j]),2)+pow((entrada_aleatoria_y[i]-entrada_aleatoria_y[j]),2)+pow((entrada_aleatoria_z[i]-entrada_aleatoria_z[j]),2));
}
}
int tempo;
//REORDER FOR CALCULUS:
for(i=0;i<nD;i++)
{
for(j=i+1;j<nD;j++){if(DR[j]<DR[i]){tempo=DR[i];DR[i]=DR[j];DR[j]=tempo;
}}}

for(i=0;i<nR;i++){for(j=i+1;j<nR;j++){if(RR[j]<RR[i]){tempo=RR[i];RR[i]=RR[j];RR[j]=tempo;
}}}

for(i=0;i<temp;i++)
{
for(j=i+1;j<temp;j++)
    {
    dR=sqrt(pow((entrada_aleatoria_x[i]-entrada_aleatoria_x[j]),2)+pow((entrada_aleatoria_y[i]-entrada_aleatoria_y[j]),2)+pow((entrada_aleatoria_z[i]-entrada_aleatoria_z[j]),2));
    }
}

float LSz=0;

LSz=((DD/nD)-(2*dR/nDR)+(rR/nR))/(rR/nR);
LSz=0;
printf("\nEstimado: %.2f",LSz);
}
