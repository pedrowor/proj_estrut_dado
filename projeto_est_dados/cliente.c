#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "fila.h"

cliente listaclientes[MAX_CLIENTES];
int totalclientes = 0;
static int ultimoid = 0;

static void lerstring(const char* prompt, char* destino, int tamanho) {
    printf("%s", prompt);
    fgets(destino, tamanho, stdin);
    size_t len = strlen(destino);
    if (len > 0 && destino[len-1] == '\n') destino[len-1] = '\0';
}

int buscarclienteporid(int id) {
    for (int i = 0; i < totalclientes; i++) {
        if (listaclientes[i].id == id) return i;
    }
    return -1;
}

void inserircliente() {
    if (totalclientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    cliente c;
    c.id = ++ultimoid;
    printf("\n Novo Cliente\n");
    lerstring("Nome: ", c.nome, sizeof(c.nome));
    lerstring("Telefone: ", c.telefone, sizeof(c.telefone));
    lerstring("Placa: ", c.placa, sizeof(c.placa));

    listaclientes[totalclientes++] = c;
    adicionarnafila(c.id);

    printf("Cliente cadastrado com sucesso! ID: %d\n", c.id);
}

void consultarcliente() {
    printf("\n Consultar Cliente\n");
    printf("Informe o ID do cliente: ");
    int id;
    if (scanf("%d%*c", &id) != 1) {
        printf("Entrada invalida.\n");
        return;
    }

    int pos = buscarclienteporid(id);
    if (pos >= 0) {
        cliente c = listaclientes[pos];
        printf("ID: %d\nNome: %s\nTelefone: %s\nPlaca: %s\n", c.id, c.nome, c.telefone, c.placa);
    } else {
        printf("Cliente nao encontrado.\n");
    }
}

void alterarcliente() {
    printf("\n Alterar Cliente\n");
    printf("Informe o ID do cliente: ");
    int id;
    if (scanf("%d%*c", &id) != 1) {
        printf("Entrada invalida.\n");
        return;
    }

    int pos = buscarclienteporid(id);
    if (pos >= 0) {
        printf("Alterando cliente ID %d\n", id);
        lerstring("Novo nome (enter para proxima opcao): ", listaclientes[pos].nome, sizeof(listaclientes[pos].nome));
        lerstring("Novo telefone (enter para proxima opcao): ", listaclientes[pos].telefone, sizeof(listaclientes[pos].telefone));
        lerstring("Nova placa (enter para proxima opcao): ", listaclientes[pos].placa, sizeof(listaclientes[pos].placa));
        printf("Cliente alterado com sucesso.\n");
    } else {
        printf("Cliente nao encontrado.\n");
    }
}

void excluircliente() {
    printf("\n Excluir Cliente\n");
    printf("Informe o ID do cliente: ");
    int id;
    if (scanf("%d%*c", &id) != 1) {
        printf("Entrada invalida.\n");
        return;
    }

    int pos = buscarclienteporid(id);
    if (pos >= 0) {
        for (int i = pos; i < totalclientes - 1; i++) {
            listaclientes[i] = listaclientes[i + 1];
        }
        totalclientes--;
        removerdafila(id);
        printf("Cliente removido com sucesso.\n");
    } else {
        printf("Cliente nao encontrado.\n");
    }
}
