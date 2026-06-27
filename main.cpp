#include "define.h"

#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("input.txt");
    int n, m;
    file >> n >> m;
    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        file >> from >> to >> weight;
        graph.addEdge(from, to, weight);
    }
    graph.dijkstra(0);
    graph.printGraph();
    return 0;
}