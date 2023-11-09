#include "sgc.h"
#include <stdio.h>

// implementações das funções para usuários convencionais

// função para fazer um novo pedido
void fazerPedido() {
    if (totalProdutos == 0) {
        printf("O estoque está vazio. Não é possível fazer pedidos.\n");
        return;
    }

    // cria um novo pedido e solicita informações do usuário
    struct Pedido *p = &pedidos[totalPedidos++];
    printf("Nome de usuário: ");
    scanf("%s", p->nome_usuario);
    printf("Nome do produto: ");
    scanf("%s", p->nome_produto);
    printf("Quantidade desejada: ");
    scanf("%d", &p->quantidade);

    int produtoEncontrado = 0;
    // verifica se o produto desejado está no estoque
    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(p->nome_produto, estoque[i].nome) == 0) {
            produtoEncontrado = 1;
            // verifica se há quantidade suficiente no estoque
            if (estoque[i].quantidade >= p->quantidade) {
                estoque[i].quantidade -= p->quantidade;
                printf("Pedido feito com sucesso!\n");
            }
        }
    }

    if (!produtoEncontrado) {
        printf("Produto não encontrado no estoque.\n");
    }
}

// função para exibir todos os pedidos
void exibirPedidos() {
    if (totalPedidos == 0) {
        printf("Não há pedidos para exibir.\n");
    } else {
        printf("Pedidos:\n");
        for (int i = 0; i < totalPedidos; i++) {
            struct Pedido *p = &pedidos[i];
            // vai exibe informações detalhadas do pedido
            printf("Nome de usuário: %s, Nome do produto: %s, Quantidade: %d\n", p->nome_usuario, p->nome_produto, p->quantidade);
        }
    }
}
