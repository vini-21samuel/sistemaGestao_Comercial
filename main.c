#include "sgc.h"

struct Produto estoque[MAX_PRODUTOS];
    int totalProdutos = 0;

struct Usuario usuarios[MAX_USUARIOS];
    int totalUsuarios = 0;

struct Pedido pedidos[MAX_PEDIDOS];
    int totalPedidos = 0;

int main() {
    int escolha;
    int autenticado = 0;
    // comentei a declaração e inicialização das variáveis autenticado, estoque, totalProdutos, usuarios, totalUsuarios, pedidos e totalPedidos.
    // isso é apenas para fins de esclarecimento, e seu código deve funcionar corretamente com ou sem essas linhas comentadas.
    
    // verifique a existência dos arquivos e crie-os, se necessário
    FILE *arquivoEstoque = fopen("estoque.txt", "r");
    if (arquivoEstoque == NULL) {
        arquivoEstoque = fopen("estoque.txt", "w");
    }
    fclose(arquivoEstoque);

    FILE *arquivoUsuarios = fopen("usuarios.txt", "r");
    if (arquivoUsuarios == NULL) {
        arquivoUsuarios = fopen("usuarios.txt", "w");
    }
    fclose(arquivoUsuarios);

    FILE *arquivoPedidos = fopen("pedidos.txt", "r");
    if (arquivoPedidos == NULL) {
        arquivoPedidos = fopen("pedidos.txt", "w");
    }
    fclose(arquivoPedidos);

    while (1) {
        if (!autenticado) {
            autenticado = autenticar();
            if (autenticado) {
                printf("Autenticado como administrador.\n");
            } else {
                printf("Falha na autenticação.\n");
                return 0;
            }
        }

        
        // menu de opção
        printf("_____________________________________________\n");
        printf("|                                            |\n");
        printf("| Selecione uma opção:                       |\n");
        printf("| 1. Adicionar produto ao estoque            |\n");
        printf("| 2. Exibir produtos no estoque              |\n");
        printf("| 3. Adicionar usuário                       |\n");
        printf("| 4. Excluir usuário                         |\n");
        printf("| 5. Fazer pedido (usuário convencional)     |\n");
        printf("| 6. Cancelar pedido (administrador)         |\n");
        printf("| 7. Exibir pedidos (administrador)          |\n");
        printf("| 8. Sair                                    |\n");
        printf("|____________________________________________|\n\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarProduto();
                salvarEstoque(); // Salvar após adicionar um produto
                break;
            case 2:
                exibirProdutos();
                break;
            case 3:
                adicionarUsuario();
                salvarUsuarios(); // Salvar após adicionar um usuário
                break;
            case 4:
                excluirUsuario();
                salvarUsuarios(); // Salvar após excluir um usuário
                break;
            case 5:
                fazerPedido();
                salvarPedidos(); // Salvar após fazer um pedido
                break;
            case 6:
                cancelarPedido();
                salvarPedidos(); // Salvar após cancelar um pedido
                break;
            case 7:
                exibirPedidos();
                break;
            case 8:
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
