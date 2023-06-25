#include "pedido.hpp"
#include <list>

Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it) {
    delete *it;
  }

  m_produtos.clear();
}

void Pedido::setEndereco(const std::string &endereco) { m_endereco = endereco; }

float Pedido::calculaTotal() const {
  float total = 0;

  for (auto const &i : m_produtos) {
    total += (i->getQtd() * i->getValor());
  }

  return total;
}

void Pedido::adicionaProduto(Produto *p) { m_produtos.push_back(p); }

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  std::string output = "";

  for (auto const &i : m_produtos) {
    output += i->descricao() + "\n";
  }

  output += "Endereco: " + m_endereco;

  return output;
}
