#include <stdio.h>
#include "cliente.h"
#include "fila.h"
#include "historico.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void menu() {
    int op;
    do {
        printf("\n Oficina Mecnica\n");
        printf("1 - Cadastrar clinete\n");
        printf("2 - Consultar cliente\n");
        printf("3 - Alterar cliente\n");
        printf("4 - Excluir cliente\n");
        printf("5 - Marcar atendimento (data)\n");
        printf("6 - Atender proximo cliente\n");
        printf("7 - Ver historico de atendimentos\n");
        printf("0 - Sair\n");
        printf(": ");

        if (scanf("%d", &op) != 1) {
            printf("Entrada invalida\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        switch (op) {
            case 1: inserircliente(); break;
            case 2: consultarcliente(); break;
            case 3: alterarcliente(); break;
            case 4: excluircliente(); break;
            case 5:marcaratendimento();break;
            case 6: {
                int id = atendercliente();
                if (id != -1) {
                    int pos = buscarclienteporid(id);
                    if (pos >= 0) {
                        printf("Cliente Atendido: %s (placa: %s)\n", listaclientes[pos].nome, listaclientes[pos].placa);
                        adicionarhistorico(id);
                    }
                } else {
                    printf("Fila vazia\n");
                }
                break;
            }
            case 7: mostrarhistorico(); break;
            case 0: printf("Saindo\n"); break;
            default: printf("Opcao invalida\n");
        }
    } while (op != 0);
}

int main() {
    menu();
    return 0;
}
