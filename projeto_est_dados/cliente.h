#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_CLIENTES 100

typedef struct {
    int id;
    char nome[50];
    char telefone[20];
    char placa[10];
    char data[4];
} cliente;

extern cliente listaclientes[MAX_CLIENTES];
extern int totalclientes;

int buscarclienteporid(int id);
void inserircliente();
void consultarcliente();
void alterarcliente();
void excluircliente();
void marcaratendimento();

#endif
