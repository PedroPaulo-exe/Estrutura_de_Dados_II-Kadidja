#include <stdio.h>

// Procura um número em um vetor ordenado usando busca binária.
int busca_binaria(const int vetor[], int tamanho, int alvo) {
  int inicio = 0;
  int fim = tamanho - 1;

  while (inicio <= fim) {
    int meio = inicio + (fim - inicio) / 2; // Encontra o meio do vetor.

    if (vetor[meio] == alvo) {
      return meio; // Retorna o índice se encontrar o número.
    }

    if (vetor[meio] < alvo) {
      inicio = meio + 1; // Busca na metade da direita.
    } else {
      fim = meio - 1; // Busca na metade da esquerda.
    }
  }

  return -1; // Retorna -1 se o número não for encontrado.
}

int main() {
  int dados[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int tamanho = sizeof(dados) / sizeof(dados[0]); // Calcula a quantidade de elementos.
  int alvo = 23;

  int resultado = busca_binaria(dados, tamanho, alvo);

  if (resultado != -1) {
    printf("Elemento encontrado no indice %d.\n", resultado);
  } else {
    printf("Elemento nao encontrado.\n");
  }

  return 0;
}