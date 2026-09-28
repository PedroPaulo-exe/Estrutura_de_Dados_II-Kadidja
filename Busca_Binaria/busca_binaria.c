#include <stdio.h>

int busca_binaria(const int vetor[], int tamanho, int alvo) {
  int inicio = 0;
  int fim = tamanho - 1;

  while (inicio <= fim) {
    int meio = inicio + (fim - inicio) / 2;

    if (vetor[meio] == alvo) {
      return meio;
    }

    if (vetor[meio] < alvo) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }

  return -1;
}

int main() {
  int dados[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int tamanho = sizeof(dados) / sizeof(dados[0]);
  int alvo = 23;

  int resultado = busca_binaria(dados, tamanho, alvo);

  if (resultado != -1) {
    printf("Elemento encontrado no indice %d.\n", resultado);
  } else {
    printf("Elemento nao encontrado.\n");
  }

  return 0;
}
