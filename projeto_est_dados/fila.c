#include <stdio.h>
#include "fila.h"

static int fila[MAX_FILA];
static int inicio = 0, fim = 0;

void adicionarnafila(int id) {
    if (fim - inicio >= MAX_FILA) {
        printf("Fila cheia\n");
        return;
    }
    fila[fim % MAX_FILA] = id;
    fim++;
}

int atendercliente() {
    if (inicio == fim) {
        return -1; 
    }
    int id = fila[inicio % MAX_FILA];
    inicio++;
    return id;
}

void removerdafila(int id) {
    int nova_fila[MAX_FILA];
    int nova_fim = 0;
    for (int i = inicio; i < fim; i++) {
        int current = fila[i % MAX_FILA];
        if (current != id) {
            nova_fila[nova_fim++] = current;
        }
    }
    for (int i = 0; i < nova_fim; i++) {
        fila[(inicio + i) % MAX_FILA] = nova_fila[i];
    }
    fim = inicio + nova_fim;
}

int filavazia() {
    return inicio == fim;
}
