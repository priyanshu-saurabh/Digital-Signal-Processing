// Linear convolution using DFT and IDFT
// Created by Priyan on 17-04-2025

#include <stdio.h>
#include <math.h>
#include <complex.h>
#define PI 3.14159265358979323846

// Perform DFT on real input signal
void DFT(double complex *x, double complex *X, int N) {
    for (int k = 0; k < N; k++) {
        X[k] = 0;
        for (int n = 0; n < N; n++) {
            double angle = -2 * PI * k * n / N;
            X[k] += x[n] * cexp(I * angle);  // e^(-j2πkn/N)
        }
    }
}

// Perform IDFT on complex frequency domain signal
void IDFT(double complex *X, double complex *x, int N) {
    for (int n = 0; n < N; n++) {
        x[n] = 0;
        for (int k = 0; k < N; k++) {
            double angle = 2 * PI * k * n / N;
            x[n] += X[k] * cexp(I * angle);  // e^(j2πkn/N)
        }
        x[n] /= N;  // Normalize
    }
}

// Main function to perform linear convolution using DFT and IDFT
int main() {
    int a, b;
    printf("Enter length of sequence a: ");
    scanf("%d", &a);
    printf("Enter length of sequence b: ");
    scanf("%d", &b);

    int N = a + b - 1;  // Linear convolution length

    double complex x[N], h[N], X[N], H[N], Y[N], y[N];

    // Initialize arrays to 0
    for (int i = 0; i < N; i++) {
        x[i] = 0;
        h[i] = 0;
    }

    // Take input for first signal
    printf("Enter %d elements for first sequence:\n", a);
    for (int i = 0; i < a; i++) {
        double temp;
        printf("x[%d]: ", i);
        scanf("%lf", &temp);
        x[i] = temp;
    }

    // Take input for second signal
    printf("Enter %d elements for second sequence:\n", b);
    for (int i = 0; i < b; i++) {
        double temp;
        printf("h[%d]: ", i);
        scanf("%lf", &temp);
        h[i] = temp;
    }

    // Perform DFT on both signals
    DFT(x, X, N);
    DFT(h, H, N);

    // Multiply in frequency domain
    for (int i = 0; i < N; i++) {
        Y[i] = X[i] * H[i];
    }

    // Perform IDFT to get linear convolution result
    IDFT(Y, y, N);

    // Output the result
    printf("\nLinear Convolution Result (y[n]):\n");
    for (int i = 0; i < N; i++) {
        printf("y[%d] = %.4f\n", i, creal(y[i]));  // Use creal to get real part
    }

    return 0;
}
