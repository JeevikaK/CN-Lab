#include<stdio.h>

int compute(int a, int m, int n){
    int y = 1;
    while(m > 0){
        if(m % 2 == 1)
            y = (y * a) % n;
        a = a * a % n;
        m /= 2;
    }
    return y;
}

int main(){
    int p, g;
    printf("Enter two prime number and alpha \n");
    scanf("%d%d", &p, &g);
    int a, b;
    int A, B;
    a = rand();
    A = compute(g, a, p);
    printf("Ya = %d", A);
    b = rand();
    B = compute(g, b, p);
    printf("Yb = %d", B);
    int keyA = compute(g, A, p);
    int keyB = compute(g, B, p);
    printf("A's secret key = %d, B's secret key = %d \n", keyA, keyB);
}