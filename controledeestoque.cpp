#include <iostream> // Biblioteca para entrada e saída de dados em C++

// Função para adicionar produtos ao estoque
void adicionarProduto(std::string produtos[], int quantidades[], int tamanho, std::string produto, int quantidade)
{
    produtos[tamanho] = produto;       // Adiciona o produto ao final do array de produtos
    quantidades[tamanho] = quantidade; // Adiciona a quantidade correspondente ao produto
}

// Função para remover produtos vendidos do estoque
void removerProduto(std::string produtos[], int quantidades[], int tamanho, std::string produto, int quantidade)
{
    for (int i = 0; i < tamanho; i++) // Loop para percorrer o array de produtos
    {
        if (produtos[i] == produto) // Verifica se o produto está no estoque
        {
            quantidades[i] -= quantidade; // Remove a quantidade vendida do estoque
            if (quantidades[i] <= 0)      // Se a quantidade no estoque for menor ou igual a zero
            {
                for (int j = i; j < tamanho - 1; j++) // Loop para ajustar o array após a remoção do produto
                {
                    produtos[j] = produtos[j + 1];       // Move os produtos restantes uma posição para trás
                    quantidades[j] = quantidades[j + 1]; // Move as quantidades restantes uma posição para trás
                }
                tamanho--; // Reduz o tamanho do estoque
            }
            std::cout << "Produto '" << produto << "' removido do estoque.\n"; // Exibe mensagem de remoção
            break;                                                             // Sai do loop após encontrar e remover o produto
        }
    }
}

// Função para exibir o estoque atual
void exibirEstoque(std::string produtos[], int quantidades[], int tamanho)
{
    std::cout << "Estoque atual:\n";  // Exibe cabeçalho
    for (int i = 0; i < tamanho; i++) // Loop para percorrer o estoque
    {
        std::cout << produtos[i] << ": " << quantidades[i] << " unidades\n"; // Exibe cada produto e sua quantidade no estoque
    }
}

int main()
{
    const int maxProdutos = 100;       // Define o tamanho máximo do array de produtos
    std::string produtos[maxProdutos]; // Array para armazenar os produtos
    int quantidades[maxProdutos];      // Array para armazenar as quantidades disponíveis
    int tamanho = 0;                   // Variável para controlar o tamanho atual dos arrays

    // Adiciona produtos inicialmente ao estoque
    adicionarProduto(produtos, quantidades, tamanho, "Maçãs", 50);
    tamanho++;
    adicionarProduto(produtos, quantidades, tamanho, "Pães", 100);
    tamanho++;
    adicionarProduto(produtos, quantidades, tamanho, "Leite", 30);
    tamanho++;

    // Exibe o estoque inicial
    exibirEstoque(produtos, quantidades, tamanho);

    // Simula algumas vendas
    removerProduto(produtos, quantidades, tamanho, "Maçãs", 5);
    removerProduto(produtos, quantidades, tamanho, "Pães", 5);
    removerProduto(produtos, quantidades, tamanho, "Leite", 5);

    // Exibe o estoque após as vendas
    exibirEstoque(produtos, quantidades, tamanho);

    return 0;
}