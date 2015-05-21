//
//  main.c
//  salt-pepper-noise
//
//  Created by Gabriel Bellon on 20/05/15.
//  Copyright (c) 2015 Gabriel Bellon. All rights reserved.
//

#include "img.h"

#define MAX_NAME 256
#define MAX 512

int main(int argc, const char * argv[]) {
    FILE *arq;
    char fname[MAX_NAME];
    char magic_number[128];
    int i, j, n, m, max;

    int M[MAX][MAX];
    
    /* PEGA O NOME DO ARQUIVO */
    //printf("Digite o nome do arquivo PGM de entrada: ");
    //scanf("%s", fname);
    
    arq = fopen("/Users/fibrasek/Dev/Salt-and-Pepper-Noise-remover/salt-pepper-noise/salt-pepper-noise/Lena.pgm", "r");
    
    if (arq == NULL) {
        printf("Erro na abertura do arquivo %s\n", fname);
        return 0;
    }
    
    /* LE O NUMERO MAGICO = P2  */
    fscanf(arq, "%s", magic_number);
    if (strcmp(magic_number, "P2") != 0) {
        printf("Arquivo não e um PGM\n");
        fclose(arq);
        return 0;
    }
    fscanf(arq, "%d %d %d", &m, &n, &max);
    
    /* LE OS DADOS E ENFIA ELES NUMA MATRIZ */
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= m - 1; j++) {
            fscanf(arq, " %d ", &M[i][j]);
        }
    }
    fclose(arq);
    
    limpa_imagem(magic_number, n, m, max, M);
    //clock_t t;
    //t = clock();
    
    //limpa_imagem_recursive(magic_number, 0, 0, MAX, M);
    
    //t = clock() - t;
    //double time_taken = ((double)t)/CLOCKS_PER_SEC;
    //printf("Levou %f s\n", time_taken);
    
    //printf("Gravando %d,%d com %d\n",n,m,255);
    //grava_nova(magic_number, n, m, max, M);
    
    return 0;
}
