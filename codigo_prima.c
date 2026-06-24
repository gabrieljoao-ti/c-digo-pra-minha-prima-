#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL 10

int main() {
    int min, max;
    int numeros[TOTAL];

    srand(time(NULL));

    printf("Digite o valor minimo: ");
    scanf("%d", &min);

    printf("Digite o valor maximo: ");
    scanf("%d", &max);

    if (min >= max) {
        printf("Intervalo invalido!\n");
        return 1;
    }

    numeros[0] = min + rand() % (max - min + 1);

    for (int i = 1; i < TOTAL; i++) {
        int novo;
        int valido;
        int opcoes[4] = {-5, -3, 3, 5};

        do {
            valido = 1;

            novo = numeros[i - 1] + opcoes[rand() % 4];

            if (novo < min || novo > max) {
                valido = 0;
                continue;
            }

            int repeticoes = 0;

            for (int j = 0; j < i; j++) {
                if (numeros[j] == novo) {
                    repeticoes++;
                }
            }

            if (repeticoes >= 2) {
                valido = 0;
            }

        } while (!valido);

        numeros[i] = novo;
    }

    printf("\nNumeros gerados:\n");

    for (int i = 0; i < TOTAL; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");

    return 0;
}
