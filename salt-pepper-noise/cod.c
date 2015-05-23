void limpa_imagem(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]) {
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
            matriz[i][j] = mediana(vizinhos);
        }
    }
}
