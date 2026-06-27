#include "define.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>


Graph::Graph(int n) {
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].distance = INT_MAX;
    }
}

void Graph::addEdge(int from, int to, int weight) {
    edge e;
    e.to = to;
    e.weight = weight;
    nodes[from].edges.push(e);
}

void Graph::printGraph() {
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << "Node " << i << " has edges to: ";
        while (!nodes[i].edges.empty()) {
            edge e = nodes[i].edges.top();
            nodes[i].edges.pop();
            std::cout << e.to << " with weight " << e.weight << ", ";
        }
        std::cout << std::endl;
    }
}

void Graph::dijkstra(int start) {
    nodes[start].distance = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, start));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        while (!nodes[u].edges.empty()) {
            edge e = nodes[u].edges.top();
            nodes[u].edges.pop();
            if (nodes[u].distance + e.weight < nodes[e.to].distance) {
                nodes[e.to].distance = nodes[u].distance + e.weight;
                pq.push(std::make_pair(nodes[e.to].distance, e.to));
            }
        }
    }
}

