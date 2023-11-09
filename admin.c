#include "sgc.h"
#include <stdio.h>
#include <string.h>


// implementações das funções administrativas

int autenticar() {
    char senha[100];
    printf("____________________________________________________ \n");
    printf("|                                                   |\n");
    printf("| Bem-vindo ao Sistema de Gerenciamento de Estoque! |\n");
    printf("|___________________________________________________|\n");
    printf("\nSenha de administrador: ");
    scanf("%s", senha);

    // verifica se a senha inserida é igual à senha do administrador (no caso, "vinicius_admin").
    // se for igual, retorna 1, indicando autenticação bem-sucedida. Caso contrário, retorna 0.
    if (strcmp(senha, "vinicius_admin") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// função para adicionar um novo produto ao estoque
void adicionarProduto() {
    if (totalProdutos < MAX_PRODUTOS) {
        struct Produto *p = &estoque[totalProdutos++];
        printf("Nome do produto: ");
        scanf("%s", p->nome);
        printf("Preço: ");
        scanf("%f", &p->preco);
        printf("Quantidade: ");
        scanf("%d", &p->quantidade);
        printf("Produto adicionado com sucesso!\n");
    } else {
        printf("Desculpe, o estoque está cheio.\n");
    }
}

// função para exibir produtos no estoque
void exibirProdutos() {
    printf("Produtos no estoque:\n");
    for (int i = 0; i < totalProdutos; i++) {
        struct Produto *p = &estoque[i];
        // vai exibe informações detalhadas do produto.
        printf("Nome: %s, Preço: %.2f, Quantidade: %d\n", p->nome, p->preco, p->quantidade);
    }
    if (totalProdutos == 0) {
        printf("O estoque está vazio.\n");
    }
}

// função para adicionar um novo usuário (administrador ou convencional)
void adicionarUsuario() {
    if (totalUsuarios < MAX_USUARIOS) {
        struct Usuario *u = &usuarios[totalUsuarios++];
        printf("Nome de usuário: ");
        scanf("%s", u->nome);
        printf("Senha: ");
        scanf("%s", u->senha);
        printf("Nível de privilégio (0 para usuário convencional, 1 para administrador): ");
        scanf("%d", &u->nivel_privilegio);
        printf("Usuário adicionado com sucesso!\n");
    }
}

// função para excluir um usuário
void excluirUsuario() {
    char nomeUsuario[100];
    printf("Nome de usuário a ser excluído: ");
    scanf("%s", nomeUsuario);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nomeUsuario) == 0) {
            // função para remover o usuário encontrado.
            for (int j = i; j < totalUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            totalUsuarios--;

            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

// função para cancelar um pedido
void cancelarPedido() {
    char nomeProduto[100];
    printf("Nome do produto a ser cancelado: ");
    scanf("%s", nomeProduto);

    for (int i = 0; i < totalPedidos; i++) {
        if (strcmp(pedidos[i].nome_produto, nomeProduto) == 0) {
            for (int j = 0; j < totalProdutos; j++) {
                if (strcmp(nomeProduto, estoque[j].nome) == 0) {
                    estoque[j].quantidade += pedidos[i].quantidade;
                    break;
                }
            }
            // função para remover o pedido encontrado.
            for (int j = i; j < totalPedidos - 1; j++) {
                pedidos[j] = pedidos[j + 1];
            }
            totalPedidos--;

            printf("Pedido cancelado com sucesso!\n");
            return;
        }
    }

    printf("Pedido não encontrado.\n");
}

// função para salvar informações do estoque no arquivo "estoque.txt"
void salvarEstoque() {
    FILE *arquivo = fopen("estoque.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < totalProdutos; i++) {
            // salva informações do produto no formato específico.
            fprintf(arquivo, "Produto: %s\nQuantidade: %d\nPreço: %.2f\n", estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
        }
        fclose(arquivo);
    } else {
        printf("Erro ao criar ou abrir o arquivo estoque.txt\n");
    }
}

// função para salvar informações dos usuários no arquivo "usuarios.txt"
void salvarUsuarios() {
    FILE *arquivo = fopen("usuarios.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < totalUsuarios; i++) {
            // salva informações do usuário no formato específico.
            fprintf(arquivo, "Nome de Usuário: %s\nSenha: %s\nNível de Privilégio: %d\n", usuarios[i].nome, usuarios[i].senha, usuarios[i].nivel_privilegio);
        }
        fclose(arquivo);
    } else {
        printf("Erro ao criar ou abrir o arquivo usuarios.txt\n");
    }
}

// função para salvar informações de pedidos no arquivo "pedidos.txt"
void salvarPedidos() {
    FILE *arquivo = fopen("pedidos.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < totalPedidos; i++) {
            // salva informações do pedido no formato específico.
            fprintf(arquivo, "Nome do Usuário: %s\nNome do Produto: %s\nQuantidade: %d\n", pedidos[i].nome_usuario, pedidos[i].nome_produto, pedidos[i].quantidade);
        }
        fclose(arquivo);
    } else {
        printf("Erro ao criar ou abrir o arquivo pedidos.txt\n");
    }
}

// implementação da função para salvar um pedido específico em pedidos.txt
void salvarPedido(struct Pedido *p) {
    FILE *arquivo = fopen("pedidos.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s %s %d\n", p->nome_usuario, p->nome_produto, p->quantidade);
        fclose(arquivo);
    }
}