#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100 // * Definindo o tamnaho máximo de produtos a ser estocado

// * Definindo a estrutura do produto que vai ser utilizado
struct Produto {
  int codigo;
  char nome[50];
  int quantidade;
};

struct Produto estoque[MAX_PRODUTOS]; // * Inicializando um vetor de produtos para armazenar os dados
int total_produtos = 0; // * Quantidade atual de produtos

// * Criando a função de insert/inserir produto
void inserirProduto(int codigo, char nome[], int quantidade){
  if (total_produtos < MAX_PRODUTOS) {
    estoque[total_produtos].codigo = codigo;
    strcpy(estoque[total_produtos].nome, nome);  // * Copiando a string de origem para a string destino
    estoque[total_produtos].quantidade = quantidade;
    total_produtos++;
    printf("Produto inserido com sucesso! \n");
  } else {
    printf("Desculpe, estoque cheio!");
  }
}

// * Criando a função de search/buscar produto
int buscarProduto(int codigo){
  for(int i = 0; i < total_produtos; i++){
    if (estoque[i].codigo == codigo) {
      return i;
    }
  }
  return -1;
}

// * Criando a funcão de delete
void deletarProduto(int codigo){
  int index = buscarProduto(codigo);
  if (index != -1){
    for (int i = index; i < total_produtos - 1; i++){
      estoque[i] = estoque[i + 1];
    }
    total_produtos --;
    printf("Produto removido com sucesso! \n");
  } else {
    printf("Reveja o codigo inserido!");
  }
}

// * Implementando uma função de listar todos os produtos
void listarProdutos(){
  if (total_produtos > 0) {
    printf("Produtos no estoque: \n");
    for (int i = 0; i < total_produtos; i++) {
      printf("Codigo: %d, Nome: %s, Quantidade: %d\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade);
  } 
  } else {
    printf("Sem produtos no estoque! \n");
  }
}

// * Implementando uma função usando ponteiro
void inserirProdutoPonteiro(struct Produto *p, int codigo, char nome[], int quantidade) {

  //  ! Imprime os endereços de p e estoque para verificar se são os mesmos caso deseja verificar 
  /* printf("Endereço do ponteiro p: %p\n", (void*)p);
  printf("Endereço do estoque: %p\n", (void*)estoque); */

  if (total_produtos < MAX_PRODUTOS){
    p[total_produtos].codigo = codigo;
    strcpy(p[total_produtos].nome, nome);
    p[total_produtos].quantidade = quantidade;
    total_produtos++;
    printf("Produto foi inserido com sucesso (usando pronteiro)! \n");
  } else {
    printf("Falha ao inserir o produto (usando ponteiro), estoque cheio!! \n");
  }
}



// * Testando funções do controle de produtos
int main() {
  int opcao = 0, codigo, quantidade;
  char nome[50];
  // * Aqui adicionamos uma referência ao ponteiro do array de produtos
  struct Produto *ponteiro_estoque = estoque;

  
  while (opcao != 6){
        printf("\n=================================================\n");
        printf("        CONTROLE DE ESTOQUE DE PRODUTOS MENU \n");
        printf("=================================================\n");
        printf("1) Inserir Produto\n");
        printf("2) Inserir Produto com ponteiro\n");
        printf("3) Buscar Produto\n");
        printf("4) Deletar Produto\n");
        printf("5) Listar Produtos\n");
        printf("6) Sair\n");
        printf("---------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
    switch (opcao) {
                case 1:
                    printf("Insira o codigo do produto: ");
                    scanf("%d", &codigo);
                    printf("Insira o nome do produto: ");
                    getchar(); // * pegando um espaço para não bugar o sistema
                    fgets(nome, sizeof(nome), stdin);  // * Capturando a entrada do campo nome, com o tamanho máximo da váriavel nome, através da função "stdin"
                    nome[strcspn(nome, "\n")] = '\0'; // * trocando o caractere \n deixado pelo scanf e colocando um nulo (0) no lugar para não bugar
                    printf("Insira a quantidade do produto: ");
                    scanf("%d", &quantidade);
                    inserirProduto(codigo, nome, quantidade); 
                    break;
                case 2: // Opção para usar ponteiro
                    printf("Insira o codigo do produto (com Ponteiro): ");
                    scanf("%d", &codigo);
                    printf("Insira o nome do produto: ");
                    getchar(); // Consumir o espaço extra
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = '\0'; // Remover o '\n' que o fgets coloca
                    printf("Insira a quantidade do produto: ");
                    scanf("%d", &quantidade);
                    inserirProdutoPonteiro(ponteiro_estoque, codigo, nome, quantidade);
                    break;

                case 3:
                    printf("Insira o codigo do produto para buscar: ");
                    scanf("%d", &codigo);
                    int index = buscarProduto(codigo);
                    if (index != -1) {
                        printf("Produto encontrado: Codigo: %d, Nome: %s, Quantidade: %d\n", estoque[index].codigo, estoque[index].nome, estoque[index].quantidade);
                    } else {
                        printf("Produto nao encontrado.\n");
                    }
                    break;

                case 4:
                    printf("Insira o codigo do produto para remover: ");
                    scanf("%d", &codigo);
                    deletarProduto(codigo);
                    break;

                case 5:
                    listarProdutos();
                    break;

                case 6:
                    printf("Saindo...\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
            }
        }
return 0;
}