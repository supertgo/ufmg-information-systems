#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "fat.h"

unsigned long long int fat_recursivo(unsigned long long int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * fat_recursivo(n-1);
    }
}

unsigned long long int fat_iterativo(unsigned long long int n){
    unsigned long long int f = 1;
    while(n > 0){
        f = f * n;
        n = n - 1;
    }
    return f;
}


