#ifndef VETOR_18_H
#define VETOR_18_H

#include <iostream>
#include <string>
using namespace std;

using std::string;

// Define um vetor cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <typename Tipo> class Vetor {
public:
  // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
  // O valor associado aos índices é indefinido.
  // PRECONDIÇÃO: fim >= inicio.
  Vetor(int inicio, int fim) : inicio_(inicio), fim_(fim) {
    elementos_ = new Tipo[fim - inicio + 1]();
  }

  // Redimensiona o vetor de forma que os índices passam a variar
  // de 'inicio2' até 'fim2'.
  // O valor associado aos índices que estão na interseção de
  // [inicio_, fim_] e [inicio2, fim2], não se alteram.
  // Já o valor dos demais índices é indefinido.
  // PRECONDIÇÃO: fim2 >= inicio2.
  void Redimensionar(int inicio2, int fim2) {
    int tamanho_atual = fim_ - inicio_ + 1;
    int tamanho_novo = fim2 - inicio2 + 1;

    Tipo *elementos_novo = new Tipo[tamanho_novo];

    int inicio_copia = max(inicio_, inicio2);
    int fim_copia = min(fim_, fim2);

    int j = inicio_copia - inicio2;
    for (int i = inicio_copia; i <= fim_copia; i++, j++) {
      elementos_novo[j] = elementos_[i - inicio_];
    }

    delete[] elementos_;
    inicio_ = inicio2;
    fim_ = fim2;
    elementos_ = elementos_novo;
  }

  // Retorna uma referência a variável correspondente ao índice i.
  // Pode ser utilizado tanto para atribuir quanto para acessar valores.
  // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
  Tipo &operator[](int i) { return elementos_[i - inicio_]; }

  // Desaloca a memória reservada para os elementos do vetor.
  ~Vetor() { delete[] elementos_; }

private:
  int inicio_;      // Primeiro índice válido do vetor.
  int fim_;         // Último índice válido do vetor.
  Tipo *elementos_; // Elementos do vetor.
};

#endif
