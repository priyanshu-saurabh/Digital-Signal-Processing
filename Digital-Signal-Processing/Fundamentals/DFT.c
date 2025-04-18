#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    float xn[N];
    float Xr[N];
    float Xi[N];

    // Taking input values
    for (int i = 0; i < N; i++) {
        printf("Enter the value of x[%d]: ", i);
        scanf("%f", &xn[i]);
    }

    for (int k = 0; k < N; k++) {
        Xr[k] = 0;
        Xi[k] = 0;
        for (int n = 0; n < N; n++) {
            Xr[k] += xn[n] * cos((2 * PI * n * k) / N);
            Xi[k] += xn[n] * sin((2 * PI * n * k) / N);
        }
        printf("X[%d] = %f + %fj\n", k, Xr[k], Xi[k]);
    }

    return 0;
}
