#include "define.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

bool edge::operator<(const edge& other) const {
        // 如果您希望權重小的先出列（最小堆），這裡要寫成 > 
        return this->weight < other.weight; 
    }

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

void Graph::printRoute(int start){
    node* temp = &this->nodes[start];
    while (temp->next){ 
        std::cout << temp->id <<" -> ";
        temp = temp->next;
    }
    std::cout << std::endl << "Path length: " << temp->distance << std::endl;
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
                nodes[u].next = &nodes[e.to];
                nodes[e.to].distance = nodes[u].distance + e.weight;
                pq.push(std::make_pair(nodes[e.to].distance, e.to));
            }
        }
    }
}

