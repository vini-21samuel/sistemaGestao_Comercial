#ifndef SGC_H
#define SGC_H

#include <stdio.h>
#include <string.h>
#include "sgc.h"

#define MAX_PRODUTOS 100
#define MAX_USUARIOS 100
#define MAX_PEDIDOS 100

// definição da estrutura de produto
struct Produto {
    char nome[100];
    float preco;
    int quantidade;
};

// definição da estrutura de usuário
struct Usuario {
    char nome[100];
    char senha[100];
    int nivel_privilegio; // 0 para usuário convencional, 1 para administrador
};

// definição da estrutura de pedido
struct Pedido {
    char nome_usuario[100];
    char nome_produto[100];
    int quantidade;
};

// variáveis globais para armazenar produtos, usuários e pedidos
extern struct Produto estoque[MAX_PRODUTOS];
extern int totalProdutos;

extern struct Usuario usuarios[MAX_USUARIOS];
extern int totalUsuarios;

extern struct Pedido pedidos[MAX_PEDIDOS];
extern int totalPedidos;

// esses são os protótipos de funções
int autenticar();
void adicionarProduto();
void exibirProdutos();
void adicionarUsuario();
void excluirUsuario();
void fazerPedido();
void cancelarPedido();
void exibirPedidos();
void salvarEstoque();
void salvarUsuarios();
void salvarPedidos();

#endif


