#include "define.hpp"

#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("input.txt");
    int NodeCount, EdgeCount, start, end;
    file >> NodeCount >> EdgeCount >> start >> end;
    Graph graph(NodeCount);
    for (int i = 0; i < EdgeCount; i++) {
        int from, to, weight;
        file >> from >> to >> weight;
        graph.addEdge(from, to, weight);
    }
    graph.printGraph();
    graph.dijkstra(start);
    graph.printRoute(start, end); // start from 0

    return 0;
}