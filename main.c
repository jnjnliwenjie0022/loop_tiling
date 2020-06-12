#include <stdio.h>
#include <time.h>

static int a[960][960];
static int b[960][960];
static int c[960][960];
static int d[960][960];
static int e[960][960];
static int f[960][960];
int main(){
    clock_t cs;
    clock_t ps;
    double diff;
    for(int i = 0; i < 960; i++){
        for(int j = 0; j < 960; j++){
            a[i][j] = i % 4;
            b[i][j] = i % 8;
            c[i][j] = 0;
            d[i][j] = 0;
            e[j][i] = i % 8;
            f[i][j] = 0;
        }
    }

    ps = clock();
    for(int i = 0; i < 960; i++){
        for(int j = 0; j < 960; j++){
            for(int k = 0; k < 960; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cs = clock();
    diff = (double)(cs-ps);
    printf("%f\n", diff);
    ps = clock();
    for(int i = 0; i < 960; i += 4){
        for(int j = 0; j < 960; j += 4){
            for(int k = 0; k < 960; k += 4){
                for(int i_t = i; i_t < i + 4; i_t++){
                    for(int j_t = j; j_t < j + 4; j_t++){
                        for(int k_t = k; k_t < k + 4; k_t++){
                            d[i_t][j_t] +=  a[i_t][k_t] * b[k_t][j_t];
                        }
                    }
                }
            }
        }
    }
    cs = clock();
    diff = (double)(cs-ps);
    printf("%f\n", diff);
    for(int i = 0; i < 960; i++){
        for(int j = 0; j < 960; j++){
            if(c[i][j] != d[i][j]) printf("c: %d, d: %d is ERROR\n", c[i][j], d[i][j]);
        }
    }



    ps = clock();
    for(int i = 0; i < 960; i += 4){
        for(int j = 0; j < 960; j += 4){
            for(int k = 0; k < 960; k += 4){
                for(int i_t = i; i_t < i + 4; i_t++){
                    for(int j_t = j; j_t < j + 4; j_t++){
                        for(int k_t = k; k_t < k + 4; k_t++){
                            f[i_t][j_t] +=  a[i_t][k_t] * e[j_t][k_t];
                        }
                    }
                }
            }
        }
    }
    cs = clock();
    diff = (double)(cs-ps);
    printf("%f\n", diff);
    for(int i = 0; i < 960; i++){
        for(int j = 0; j < 960; j++){
            if(c[i][j] != f[i][j]) printf("c: %d, d: %d is ERROR\n", c[i][j], f[i][j]);
        }
    }
    return 0;
}
