#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME 256
#define MAX 512 

//FUNCOES
void limpa_imagem(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]);
void grava_nova(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]);
int mediana(int org[]);

int main() {
	FILE *arq;
	char fname[MAX_NAME];
	char magic_number[128];
	int i, j, n, m, max, M[MAX][MAX];

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

	/* LE OS DADOS E ENFIA ELES NUMA MATRIZ */
	for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= m - 1; j++) {
			fscanf(arq, " %d ", &M[i][j]);
		}
	}
	fclose(arq);

	limpa_imagem(magic_number, n, m, max, M);

	return 0;
}

// LIMPA UMA IMAGEM A PARTIR DO MÉTODOO DA MEDIANA
void limpa_imagem(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]) {

	printf("Magic Number: %s\nN: %d\nM: %d\nMax: %d\n", magic_number, n, m, max);

	// VIZINHOS
	// X-1,Y-1 | X-1,Y | X-1,Y+1
	// X,Y-1   |  X,Y  | X,Y+1
	// X+1,Y-1 | X+1,Y | X+1,Y+1
	int vizinhos[9];

	// CONTADORES
	int i, j, k;

		for (i = 1; i < n - 1; i++) {
			for (j = 1; j < m - 1; j++) {
				vizinhos[0] = matriz[i - 1][j - 1];
				vizinhos[1] = matriz[i - 1][j];
				vizinhos[2] = matriz[i - 1][j + 1];
				vizinhos[3] = matriz[i][j - 1];
				vizinhos[4] = matriz[i][j];
				vizinhos[5] = matriz[i][j + 1];
				vizinhos[6] = matriz[i + 1][j - 1];
				vizinhos[7] = matriz[i + 1][j];
				vizinhos[8] = matriz[i + 1][j + 1];

				matriz[i][j] = mediana(vizinhos);
				//printf("%d\n", matriz[i][j]);
			}
		}

	grava_nova(magic_number, n, m, max, matriz);
}

// ORDENA MATRIZ E RETORNA MEDIANA
int mediana(int org[]) {
	int i, aux;

	for (i = 0; i < 9; ++i) {
		if (org[i] >= org[i + 1]) {
			aux = org[i];
			org[i] = org[i + 1];
			org[i + 1] = aux;
		}
	}
	printf("Mediana: %d\n", org[4]);
	if(org[4] == 0){
		return org[3];
	} else if(org[4] == 255){
		return org[5];
	}


	//printf("[0]: %d | [1]: %d | [2]: %d | [3]: %d | [4]: %d | [5]: %d | [6]: %d | [7]: %d | [8]: %d\n",
	//		org[0], org[1], org[2], org[3], org[4], org[5], org[6], org[7], org[8]);

	return (org[4]);
}

// GRAVA A NOVA IMAGEM LIMPA
void grava_nova(char magic_number[128], int n, int m, int max,
		int matriz[MAX][MAX]) {
	//printf("%s, %d, %d, %d", magic_number, n, m, max);

	int i, j;

	FILE *new_arq;

	new_arq = fopen("nova_Lena.pgm", "w+");

	fprintf(new_arq, "%s\n", magic_number);
	fprintf(new_arq, "%d ", n);
	fprintf(new_arq, "%d\n", m);
	fprintf(new_arq, "%d\n", max);

	for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= m - 1; j++) {
			fprintf(new_arq, " %d ", matriz[i][j]);
		}
	}

	fclose(new_arq);
}

