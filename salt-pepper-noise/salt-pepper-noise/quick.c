//
//  quick.c
//  salt-pepper-noise
//
//  Created by Gabriel Bellon on 20/05/15.
//  Copyright (c) 2015 Gabriel Bellon. All rights reserved.
//

#include "quick.h"


int particione(int a[9], int p, int r) {
    int x = a[r];
    int aux;
    
    int i = p - 1;
    int j;
    
    for(j = p; j < r; j++) {
        if(a[j] <= x){
            i = i + 1;
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }
    
    aux = a[i+1];
    a[i+1] = a[r];
    a[r] = aux;
    
    return i+1;
}

void quicksort(int a[9], int p, int r) {
    if(p < r){
        int q = particione(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}