#include <stdio.h>

int main() {
    int n, h;

    printf("Enter the length of i/p signal (Xn) or 'n': ");
    scanf("%d", &n);
    float Xn[n];

    printf("Enter the length of impulse response (Hn) or 'h': ");
    scanf("%d", &h);
    float Hn[h];

    int t = n + h - 1;
    float Yn[t];


    for (int i = 0; i < n; i++) {
        printf("Enter Xn[%d]: ", i);
        scanf("%f", &Xn[i]);
    }


    for (int i = 0; i < h; i++) {
        printf("Enter Hn[%d]: ", i);
        scanf("%f", &Hn[i]);
    }


    for (int i = 0; i < t; i++) {
        Yn[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            Yn[i + j] += Xn[i] * Hn[j];
        }
    }


    printf("Result: \n");
    for (int i = 0; i < t; i++) {
        printf("Yn[%d] = %.2f\n", i, Yn[i]);
    }

    return 0;
}
