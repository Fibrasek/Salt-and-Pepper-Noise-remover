#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME 256
#define MAX 512 

//FUNCOES
void limpa_imagem(char magic_number[128], int n, int m, int max, int matriz[512][512]);
void grava_nova(char magic_number[128], int n, int m, int max, int matriz[512][512]);
int mediana(int org[]);

int main(){
	FILE *arq;
	char fname[MAX_NAME];
	char magic_number[128];
	int i,j,n,m,max, M[MAX][MAX];

	/* FRESCURA */
	printf("Digite o nome do arquivo PGM de entrada: ") ;
	scanf("%s", fname) ;

	arq = fopen(fname, "r") ;

	if(arq == NULL) {
		printf("Erro na abertura do arquivo %s\n", fname) ;
		return 0 ;
	}

	/* LE O NUMERO MAGICO = P2  */
	fscanf(arq, "%s", magic_number);
	if(strcmp(magic_number, "P2") != 0) {
		printf("Arquivo nao e um PGM\n");
		fclose(arq) ;
		return 0 ;
	}
	fscanf(arq, "%d %d %d", &m, &n, &max);

	/* LE OS DADOS E ENFIA ELES NUMA MATRIZ */
	for(i=0; i<=n-1; i++) {
		for(j=0;j<=m-1;j++){
	    	fscanf(arq, " %d ", &M[i][j]);
	    }
	}
	fclose(arq);

	limpa_imagem(magic_number, n, m, max, M);

	return 0;
}

// LIMPA UMA IMAGEM A PARTIR DO M��TODO DA MEDIANA
void limpa_imagem(char magic_number[128], int n, int m, int max, int matriz[512][512]){

	printf("Magic Number: %s\nN: %d\nM: %d\nMax: %d\n", magic_number, n, m, max);

	// VIZINHOS
	// X-1,Y-1 | X-1,Y | X-1,Y+1
	// X,Y-1   |  X,Y  | X,Y+1
	// X+1,Y-1 | X+1,Y | X+1,Y+1
	int vizinhos[9];

	// CONTADORES
	int i,j;

	for(i = 1; i < n-1; i++) {
		for(j = 1; j < m-1; j++) {
			//CHECA SE i EST�� NA BORDA SUPERIOR
			//CASO SIM, OS VIZINHOS ACIMA SER��O = 0
	    	/*if(i == 0){
	    		vizinhos[0] = 0; vizinhos[1] = 0; vizinhos[2] = 0;
	    	} else {*/
	    		vizinhos[0] = matriz[i-1][j-1];
	    		vizinhos[1] = matriz[i-1][j];
	    		vizinhos[2] = matriz[i-1][j+1];
	    	//}

	    	// CHECA SE i EST�� NA BORDA INFERIOR
	    	// CASO SIM, OS VIZINHOS ABAIXO SER��O = 0
	    	/*if(i == n-1){
	    		vizinhos[6] = 0; vizinhos[7]; vizinhos[8] = 0;
	    	} else {*/
	    		vizinhos[6] = matriz[i+1][j-1];
	    		vizinhos[7] = matriz[i+1][j];
	    		vizinhos[8] = matriz[i+1][j+1];
	    	//}

			// CHECA SE i EST�� NA BORDA ESQUERDA
	    	// CASO SIM, OS VIZINHOS A ESQUERDA SER��O = 0
	    	/*if(j == 0){
	    		vizinhos[0] = 0; vizinhos[3] = 0; vizinhos[6] = 0;
	    	} else {*/
	    		//vizinhos[0] = matriz[i-1][j-1];
	    		vizinhos[5] = matriz[i][j+1];
	    		//vizinhos[6] = matriz[i+1][j-1];
	    	//}

	    	// CHECA SE i EST�� NA BORDA DIREITA
	    	// CASO SIM, OS VIZINHOS A ESQUERDA SER��O = 0
	    	/*if(j == m-1){
	    		vizinhos[2] = 0; vizinhos[5] = 0; vizinhos[8] = 0; 
	    	} else {
	    		vizinhos[2] = matriz[i-1][j+1]; 
	    		vizinhos[5] = matriz[i][j+1]; 
	    		vizinhos[8] = matriz[i+1][j+1];
	    	}*/

	    	vizinhos[4] = matriz[i][j];

	    	matriz[i][j] = mediana(vizinhos);
	    	printf("%d\n", matriz[i][j]);
		}
	}
			
	grava_nova(magic_number, n, m, max, matriz);
}

// ORDENA MATRIZ E RETORNA MEDIANA
int mediana(int org[]){
	int i, aux;

    for(i = 0; i < 9; ++i) {
        if(org[i]>org[i+1]) {
            aux = org[i];
            org[i] = org[i+1];
            org[i+1] = aux;
        }
    }
    return (org[4]);
}

// GRAVA A NOVA IMAGEM LIMPA
void grava_nova(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]){
	//printf("%s, %d, %d, %d", magic_number, n, m, max);

	int i,j;

	FILE *new_arq;

	new_arq = fopen("nova_Lena.pgm", "w+");

	fprintf(new_arq, "%s\n", magic_number);
	fprintf(new_arq, "%d ", n);
	fprintf(new_arq, "%d\n", m);
	fprintf(new_arq, "%d\n", max);

	for(i = 0; i <= n-1; i++) {
		for(j = 0;j <= m-1; j++){
	    	fprintf(new_arq, " %d ", matriz[i][j]);
	    }
	}

	fclose(new_arq);
}

