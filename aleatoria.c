#include <stdio.h>
#define filas 8
#define columnas 3

float main(){

FILE*fp2=NULL;
fp2=fopen("aleatoria.txt","w");
int j, k;

srand(time(NULL));
int matriz[filas][columnas];
for(j=0;j<filas;j++){
for(k=0;k<columnas;k++){
matriz[j][k]= rand()%25;
fprintf(fp2,"%d  ",matriz[j][k]);
//printf("%d  ",matriz[j][k]);
}
fprintf(fp2,"\n");
}

}
