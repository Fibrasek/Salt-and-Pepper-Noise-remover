//
//  img.h
//  salt-pepper-noise
//
//  Created by Gabriel Bellon on 20/05/15.
//  Copyright (c) 2015 Gabriel Bellon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 256
#define MAX 512

void limpa_imagem(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]);

void limpa_imagem_recursive(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]);

void grava_nova(char magic_number[128], int n, int m, int max, int matriz[MAX][MAX]);

int** encontra_vizinhos(int n, int m, int matriz[MAX][MAX]);

int mediana_quick(int org[9]);

int mediana_bubble(int org[]);