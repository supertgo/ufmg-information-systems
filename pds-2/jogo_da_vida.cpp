#include "jogo_da_vida.h"

JogoDaVida::JogoDaVida(int l, int c) {
  vivas_.resize(l, std::vector<bool>(c, false));
}

bool JogoDaVida::viva(int i, int j) {
  if ((0 <= i && i < linhas()) && (0 <= j && j < colunas())) {
    return vivas_[i][j];
  }

  ExcecaoCelulaInvalida e;
  e.linha = i;
  e.coluna = j;

  throw e;
}

void JogoDaVida::Matar(int i, int j) {
  if ((0 <= i && i < linhas()) && (0 <= j && j < colunas())) {
    vivas_[i][j] = false;
    return;
  }

  ExcecaoCelulaInvalida e;
  e.linha = i;
  e.coluna = j;

  throw e;
}

void JogoDaVida::Reviver(int i, int j) {
  if ((0 <= i && i < linhas()) && (0 <= j && j < colunas())) {
    vivas_[i][j] = true;
    return;
  }

  ExcecaoCelulaInvalida e;
  e.linha = i;
  e.coluna = j;

  throw e;
}

void JogoDaVida::ExecutarProximaIteracao() {
  int numLinhas = linhas();
  int numColunas = colunas();
  std::vector<std::vector<bool>> novaGeracao(vivas_);

  for (int i = 0; i < numLinhas; i++) {
    for (int j = 0; j < numColunas; j++) {
      int numVizinhasVivas = NumeroDeVizinhasVivas(i, j);

      if (vivas_[i][j]) {
        if (numVizinhasVivas < 2 || numVizinhasVivas > 3) {
          novaGeracao[i][j] = false;
        }
      } else {
        if (numVizinhasVivas == 3) {
          novaGeracao[i][j] = true;
        }
      }
    }
  }

  vivas_ = novaGeracao;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
  int numLinhas = linhas();
  int numColunas = colunas();
  int vizinhos = 0;
  int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int k = 0; k < 8; k++) {
    int nx = (x + dx[k] + numLinhas) % numLinhas;
    int ny = (y + dy[k] + numColunas) % numColunas;

    if (vivas_[nx][ny]) {
      vizinhos++;
    }
  }

  return vizinhos;
}
