# Controle de Estoque de Produtos em C

Este projeto foi desenvolvido como parte de uma atividade de entrega para o **TDE de Algoritmos**, abordando o tema de **Manipulação de Vetores em C**. Ele implementa um sistema CRUD (Create, Read, Update, Delete) para gerenciar produtos em estoque, com funcionalidades básicas e operações adicionais utilizando ponteiros.

## 🔧 Tecnologias Utilizadas

- Linguagem de programação **C**

## ✨ Funcionalidades

O sistema permite:

1. **Inserir produtos no estoque**: Adiciona um novo produto fornecendo código, nome e quantidade.
2. **Buscar produtos**: Localiza um produto no estoque a partir de seu código.
3. **Deletar produtos**: Remove um produto do estoque através de seu código.
4. **Listar todos os produtos**: Exibe todos os produtos atualmente cadastrados.
5. **Inserir produtos utilizando ponteiros**: Uma abordagem adicional para adicionar produtos ao estoque usando ponteiros.

## 🗋 Estruturas e Conceitos Utilizados

### Estrutura `Produto`

Cada produto possui os seguintes atributos:

```c
struct Produto {
  int codigo;
  char nome[50];
  int quantidade;
};
```

### Vetor de Produtos

A aplicação utiliza um vetor do tipo `struct Produto` com tamanho máximo definido por uma constante:

```c
#define MAX_PRODUTOS 100
struct Produto estoque[MAX_PRODUTOS];
int total_produtos = 0; // Quantidade atual de produtos no estoque
```

### Funções Implementadas

- **Inserir Produto**

  ```c
  void inserirProduto(int codigo, char nome[], int quantidade);
  ```

  Insere um novo produto no vetor, verificando se há espaço no estoque.

- **Buscar Produto**

  ```c
  int buscarProduto(int codigo);
  ```

  Retorna o índice do produto com o código especificado ou –±1 se não encontrado.

- **Deletar Produto**

  ```c
  void deletarProduto(int codigo);
  ```

  Remove um produto do vetor deslocando os elementos subsequentes.

- **Listar Produtos**

  ```c
  void listarProdutos();
  ```

  Exibe todos os produtos cadastrados no estoque.

- **Inserir Produto com Ponteiros**

  ```c
  void inserirProdutoPonteiro(struct Produto *p, int codigo, char nome[], int quantidade);
  ```

  Realiza a inserção utilizando um ponteiro para o vetor de produtos.

### Fluxo Principal

O programa apresenta um menu interativo com as opções mencionadas acima. O usuário pode navegar pelo menu para realizar as operações desejadas.

```c
while (opcao != 6) {
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
    
    // Processa a opção selecionada pelo usuário
    ...
}
```

## 🔎 Observações Importantes

- O tamanho máximo do estoque é limitado a `MAX_PRODUTOS`.
- Para evitar erros com entrada de strings, foi utilizado `fgets` e substituído o caractere de nova linha `\n`.
- Foi explorado o uso de ponteiros para manipulação de dados diretamente no vetor.

## 🔑 Compilação e Execução

Para compilar e executar o programa:

1. Salve o código em um arquivo, por exemplo, `estoque.c`.
2. Compile usando o GCC:
   ```bash
   gcc estoque.c -o estoque
   ```
3. Execute o programa:
   ```bash
   ./estoque
   ```

## 🙏 Considerações Finais

Este projeto serviu como um excelente exercício prático para consolidar conceitos de **vetores**, **structs** e **ponteiros** em C, fundamentais para compreender os fundamentos das tecnologias modernas, que estão se tornando cada vez mais de alto nível. Ele também destacou a relevância de aplicar boas práticas na manipulação de dados e na organização do código, facilitando a manutenção e a extensibilidade do sistema.

