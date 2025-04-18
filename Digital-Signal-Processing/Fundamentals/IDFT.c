//
// Created by Priyan on 17-04-2025.
//
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// IDFT function: Computes real (x[]) and imaginary (y[]) parts of time-domain signal
// from real-valued frequency-domain signal X[] (assuming X[] has only real part)
void idft(double x[], double y[], double X[], int N) {
    double real, imag;

    for (int k = 0; k < N; k++) {
        real = 0.0;
        imag = 0.0;

        // Compute IDFT
        for (int i = 0; i < N; i++) {
            double angle = 2 * PI * i * k / N;
            real += X[i] * cos(angle);   // Real part
            imag += X[i] * sin(angle);   // Imaginary part
        }


        x[k] = real / N;
        y[k] = imag / N;
    }
}

int main() {
    int N;

    //  input for size of the signal
    printf("Enter the length of input signal (N): ");
    scanf("%d", &N);

    // hold input (X[]) and output time-domain signal (x[], y[])
    double x[N], y[N], X[N];

    // frequency-domain input (assuming only real part)
    for (int i = 0; i < N; i++) {
        printf("Enter X[%d] (Real part only): ", i);
        scanf("%lf", &X[i]);
    }


    idft(x, y, X, N);

    // result
    printf("\nTime-Domain Signal x[n]:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.4f + %.4fj\n", i, x[i], y[i]);
    }

    return 0;
}
