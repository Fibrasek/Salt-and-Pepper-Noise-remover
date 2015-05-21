#include "img.h"
#include "quick.h"

#define MAX_NAME 256
#define MAX 512

// LIMPA UMA IMAGEM A PARTIR DO MÉTODOO DA MEDIANA
void limpa_imagem(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]) {
    
    clock_t t;
    t = clock();

	printf("Magic Number: %s\nN: %d\nM: %d\nMax: %d\n", magic_number, n, m, max);

	int vizinhos[9];

	int i, j;

    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < m - 1; j++) {

            int ii,jj,k;

            for(ii = -1, k = 0;ii <= 1; ii++){
              for(jj = -1; jj <= 1; jj++, k++){
                    vizinhos[k] = matriz[i+ii][j+jj];
                }
            }

            matriz[i][j] = mediana_quick(vizinhos);
        }
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("Levou %f s\n", time_taken);
    
	grava_nova(magic_number, n, m, max, matriz);
}

void limpa_imagem_recursive(char magic_number[128], int n, int m, int max, int matriz[][MAX]){
    
    printf("Magic Number: %s\nN: %d\nM: %d\nMax: %d\n", magic_number, n, m, max);
    //printf("M=%d\n",m);
    if(n == MAX && m == MAX){
        return;
    } else if (n < MAX){
        limpa_imagem_recursive(magic_number, n + 1, m, max, matriz);
    }else if(m < MAX){
        limpa_imagem_recursive(magic_number, n, m + 1, max, matriz);
    }
    
    matriz = encontra_vizinhos(n, m, matriz);
}

int** encontra_vizinhos(int n, int m, int matriz[MAX][MAX]){
    int vizinhos[9];
    
    int i, j;
    
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < m - 1; j++) {
            
            int ii,jj,k;
            
            for(ii = -1, k = 0;ii <= 1; ii++){
                for(jj = -1; jj <= 1; jj++, k++){
                    vizinhos[k] = matriz[i+ii][j+jj];
                }
            }
            
            matriz[i][j] = mediana_quick(vizinhos);
        }
    }
    
    return matriz;
}

// ORDENA MATRIZ E RETORNA MEDIANA
int mediana_quick(int org[9]) {
    
    if(org != NULL){
        quicksort(org, org[0], 9);
    }
	
    if(org[4] == 0){
        //printf("Mediana: %d\n",org[3]);
		return org[3];
	} else if(org[4] == 255){
        //printf("Mediana: %d\n",org[5]);
		return org[5];
	}
    
    //printf("Mediana: %d\n",org[4]);
	return org[4];
}

// ORDENA MATRIZ E RETORNA MEDIANA
int mediana_bubble(int org[]) {
    int i, aux;

    for (i = 0; i < 9; ++i) {
        if (org[i] >= org[i + 1]) {
            aux = org[i];
            org[i] = org[i + 1];
            org[i + 1] = aux;
        }
    }
    
    //printf("Mediana: %d\n", org[4]);
    
    if(org[4] == 0){
        return org[3];
    } else if(org[4] == 255){
        return org[5];
    }
    
    return org[4];
}

// GRAVA A NOVA IMAGEM LIMPA
void grava_nova(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]) {

	int i, j;

	FILE *new_arq;

	new_arq = fopen("/Users/fibrasek/Dev/Salt-and-Pepper-Noise-remover/salt-pepper-noise/salt-pepper-noise/nova_Lena.pgm", "w+");

	fprintf(new_arq, "%s\n", magic_number);
	fprintf(new_arq, "%d ", n);
	fprintf(new_arq, "%d\n", m);
	fprintf(new_arq, "%d\n", max);

	for (i = 0; i <= n-1; i++) {
		for (j = 0; j <= m-1; j++) {
			fprintf(new_arq, " %d ", matriz[i][j]);
		}
	}

	fclose(new_arq);
}