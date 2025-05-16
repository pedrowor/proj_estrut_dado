#include <stdio.h>
#include "cliente.h"
#include "historico.h"

static int pilha[MAX_HISTORICO];
static int topo = -1;

void adicionarhistorico(int id) {
    if (topo >= MAX_HISTORICO - 1) {
        printf("Historico cheio\n");
        return;
    }
    pilha[++topo] = id;
}

void mostrarhistorico() {
    if (topo < 0) {
        printf("Nenhum atendimento realizado ainda\n");
        return;
    }
    printf("\n Historico de Atendimentos\n");
    for (int i = topo; i >= 0; i--) {
        int pos = buscarclienteporid(pilha[i]);
        if (pos >= 0) {
            cliente c = listaclientes[pos];
            printf("%d: %s (placa: %s)\n", c.id, c.nome, c.placa);
        }
    }
}
