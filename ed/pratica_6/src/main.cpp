#include <iostream>
#include "graph.hpp"
#include <stdexcept>

int main(int argc, char *argv[]) {

    try {
    Grafo grafo;

    if (argc < 2) {
        throw std::runtime_error("argc must be 1");
    }

    switch (argv[1][1]) {
        case 'd':
            std::cout << grafo.QuantidadeVertices() << std::endl;
            std::cout << grafo.QuantidadeArestas() << std::endl;
            std::cout << grafo.GrauMinimo() << std::endl;
            std::cout << grafo.GrauMaximo() << std::endl;
            break;
        case 'n':
            for (int i = 0; i < grafo.QuantidadeVertices(); i++) {
                grafo.ImprimeVizinhos(i);
            }
            break;
        case 'k':
            int numVertices = grafo.QuantidadeVertices();
            int numEdges = grafo.QuantidadeArestas();
            int maxEdges = (numVertices * (numVertices - 1)) / 2;

            std::cout << (numEdges == maxEdges ? "1" : "0") << std::endl;
            break;
    }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 0;
    }

    return 0;
}
