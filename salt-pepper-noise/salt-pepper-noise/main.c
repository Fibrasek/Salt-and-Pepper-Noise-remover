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

    int M1[MAX][MAX];
    int M2[MAX][MAX];
    int M3[MAX][MAX];
    int M4[MAX][MAX];
    
    /* PEGA O NOME DO ARQUIVO */
    printf("Digite o nome do arquivo PGM de entrada: ");
    scanf("%s", fname);
    
    arq = fopen(fname, "r");
    
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
    
    /* LE OS DADOS E COLOCA ELES NUMA MATRIZ */
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= m - 1; j++) {
            fscanf(arq, " %d ", &M1[i][j]);
        }
    }
    fclose(arq);
    
    arq = fopen("Lena.pgm", "r");
    
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
    /* LE OS DADOS E COLOCA ELES NUMA MATRIZ */
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= m - 1; j++) {
            fscanf(arq, " %d ", &M2[i][j]);
        }
    }
    fclose(arq);
    
    arq = fopen("Lena.pgm", "r");
    
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
    /* LE OS DADOS E COLOCA ELES NUMA MATRIZ */
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= m - 1; j++) {
            fscanf(arq, " %d ", &M3[i][j]);
        }
    }
    fclose(arq);
    
    arq = fopen("Lena.pgm", "r");
    
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
    /* LE OS DADOS E COLOCA ELES NUMA MATRIZ */
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= m - 1; j++) {
            fscanf(arq, " %d ", &M4[i][j]);
        }
    }
    fclose(arq);
    
    /* EXECUTA POR FORÇA BRUTA (Bubble Sort)*/
    limpa_imagem_bubble(magic_number, n, m, max, M1);
    
    /* EXECUTA POR FORÇA BRUTA (QuickSort) */
    limpa_imagem_quick(magic_number, n, m, max, M2);
    
    /* EXECUTA POR RECURSÃO (Bubble Sort) */
    clock_t t1 = clock();
    limpa_imagem_recursive_bubble(magic_number, 0, 0, MAX, M3);
    
    t1 = clock() - t1;
    double total1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("RECURSÃO (Bubble Sorte): Levou %f s\n", total1);
    
    grava_nova(magic_number, n, m, max, M3, "lena_recursive_bubble.pgm");
    
    /* EXECUTA POR RECURSÃO (Quick Sort)*/
    clock_t t2 = clock();
    limpa_imagem_recursive_quick(magic_number, 0, 0, MAX, M4);
    
    t2 = clock() - t2;
    double total2 = ((double)t2)/CLOCKS_PER_SEC;
    printf("RECURSÃO (Quick Sort): Levou %f s\n", total2);
    
    grava_nova(magic_number, n, m, max, M4, "lena_recursive_quick.pgm");
    
    return 0;
}
