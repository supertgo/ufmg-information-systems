#include "pizza.hpp"

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */

  return std::to_string(m_qtd) + "X Pizza " + sabor_ + ", " + std::to_string(pedacos_) +
         " pedacos" + (borda_recheada_ ? " e" : " e sem") + " borda recheada.";
}

Pizza::Pizza(const std::string &sabor, int pedacos, bool borda_recheada,
             int qtd, float valor_unitario) {

  sabor_ = sabor;
  pedacos_ = pedacos;
  borda_recheada_ = borda_recheada;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}
