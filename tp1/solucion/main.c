#include "tdt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *archivoCasoChico  =  "salida.caso.chico.txt";
char *archivoCasoGrande =  "salida.caso.grande.txt";
void casoC();
void casoG();

uint8_t clave1[3] = {1,2,3};
uint8_t valor1[15] = {3,4,5,6,7,8,4,5,63,2,3,4,5,6,5};
uint8_t clave2[3] = {2,2,2};
uint8_t valor2[15] = {3,4,5,3,7,8,4,5,63,2,3,4,5,6,5};
uint8_t clave3[3] = {3,2,3};
uint8_t valor3[15] = {3,4,5,6,7,8,4,5,0,2,3,4,5,6,5};
uint8_t clave4[3] = {8,9,3};
uint8_t valor4[15] = {3,4,5,6,7,8,4,5,63,2,3,4,5,6,5};
uint8_t clave5[3] = {0,2,2};
uint8_t valor5[15] = {63,4,5,2,7,8,4,5,0,2,3,4,5,6,5};
uint8_t clave6[3] = {7,2,3};
uint8_t valor6[15] = {3,4,5,6,7,8,4,5,63,2,3,4,5,6,5};
uint8_t clave7[3] = {8,2,3};
uint8_t valor7[15] = {9,4,5,6,7,8,4,5,63,2,3,4,5,6,5};

uint8_t claveMin[3] = {0,0,0};
uint8_t claveMax[3] = {255,255,255};
uint8_t valorMax[15] = {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
uint8_t valorMin[15] = {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};

bloque b1 = {{1,5,3},{3,4,5,6,7,8,4,5,6,2,3,4,5,0,5}};
bloque b2 = {{2,5,2},{3,4,5,3,7,8,4,3,0,2,0,4,5,6,5}};
bloque b3 = {{3,5,3},{3,4,5,6,7,8,4,5,0,2,3,4,5,6,5}};

bloque* b[4] = {&b1,&b2,&b3,0};

int main (void){
    tdt* tabla = tdt_crear("sa");
    
    tdt_destruir(&(tabla));
    
    return 0;
}

void printmaxmin(FILE *pFile, tdt* tabla) {
    int i;
    maxmin *mm = tdt_obtenerMaxMin(tabla);
    fprintf(pFile,"max_clave = %i",mm->max_clave[0]);
    for(i=1;i<3;i++) fprintf(pFile,"-%i",mm->max_clave[i]);
    fprintf(pFile,"\n");
    fprintf(pFile,"min_clave = %i",mm->min_clave[0]);
    for(i=1;i<3;i++) fprintf(pFile,"-%i",mm->min_clave[i]);
    fprintf(pFile,"\n");
    fprintf(pFile,"max_valor = %i",mm->max_valor[0]);
    for(i=1;i<15;i++) fprintf(pFile,"-%i",mm->max_valor[i]);
    fprintf(pFile,"\n");
    fprintf(pFile,"min_valor = %i",mm->min_valor[0]);
    for(i=1;i<15;i++) fprintf(pFile,"-%i",mm->min_valor[i]);
    fprintf(pFile,"\n");
    free(mm);
}

void printBloque(FILE *pFile, bloque* b) {
    int i;
    fprintf(pFile,"%i",b->clave[0]);
    for(i=1;i<3;i++) fprintf(pFile,"-%i",b->clave[i]);
    fprintf(pFile," => ");
    fprintf(pFile,"%i",b->valor[0]);
    for(i=1;i<15;i++) fprintf(pFile,"-%i",b->valor[i]);
    fprintf(pFile,"\n");  
}