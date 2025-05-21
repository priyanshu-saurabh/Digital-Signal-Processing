
#include <stdio.h>

int main() {
    int n = 0, h = 0;

    printf("Enter number of samples in Xn (n) or 'n': ");
    scanf("%d", &n);

    printf("Enter number of samples in Hn (h) or 'h': ");
    scanf("%d", &h);

    if (n >= h) {
        int Xn[n], Hn[n], Yn[n];


            for (int i = 0; i < n; i++) {
                Hn[i] = 0;
                Yn[i] = 0;
            }


        for (int i = 0; i < n; i++) {
            printf("Enter Xn[%d]: ", i);
            scanf("%d", &Xn[i]);
        }


    for (int i = 0; i < h; i++) {

        printf("Enter Hn[%d]: ", i);
        
        scanf("%d", &Hn[i]);
    }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                Yn[i] = Yn[i] + Xn[(i - j + n) % n] * Hn[j];
                
            }
        }


        for (int i = 0; i < n; i++) {
            printf("Yn[%d]: %d\n", i, Yn[i]);
        }
    }
    else {                      //when h > n
        int Xn[h], Hn[h], Yn[h];


        for (int i = 0; i < h; i++) {
            Xn[i] = 0;
            Yn[i] = 0;
        }


        for (int i = 0; i < n; i++) {
            printf("Enter Xn[%d]: ", i);
            
            scanf("%d", &Xn[i]);
        }

        // I/P Hn
        for (int i = 0; i < h; i++) {
            printf("Enter Hn[%d]: ", i);
            scanf("%d", &Hn[i]);
        }


        for (int i = 0; i < h; i++) {
            for (int j = 0; j < h; j++) {
                
                Yn[i] = Yn[i] + Xn[(i - j + h) % h] * Hn[j];
            }
        }


        for (int i = 0; i < h; i++) {
            printf("Yn[%d]: %d\n", i, Yn[i]);
        }
    }

    return 0;
}
