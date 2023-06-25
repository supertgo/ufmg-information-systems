#include "venda.hpp"

#include <iomanip>
#include <ostream>

Venda::~Venda() {}

void Venda::adicionaPedido(Pedido *p) { m_pedidos.push_back(p); }

void Venda::imprimeRelatorio() const {
  unsigned int order_number = 0;
  float total = 0;

  for (auto const &i : m_pedidos) {
    order_number++;
    std::cout << "Pedido " << order_number << std::endl;
    std::cout << i->resumo() << std::endl;
    total += i->calculaTotal();
  }

  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2)
            << total << std::endl;
  std::cout << "Total de pedidos " << m_pedidos.size() << std::endl;
}
