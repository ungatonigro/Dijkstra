#include "define.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

void recursion(node* n) {
    if (n == nullptr) return;

    if (n->parent) {
        recursion(n->parent);
        std::cout << " -> "; 
    }
    
    std::cout << n->id;
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
    nodes[from].edges.push_back(e);
}

void Graph::printGraph(){
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << "Node " << i << " has edges to: ";
        for (const auto e : nodes[i].edges){
            std::cout << e.to << " with weight " << e.weight << " , ";
        }
        std::cout << std::endl;
    }
}

void Graph::printRoute(int start, int end){
    if (this->nodes[end].distance == INT_MAX){
        std::cout << "No path between node " << start << " and node " << end << std::endl;
        return;
    }

    node* temp = &this->nodes[end];
    recursion(temp); 
    std::cout << std::endl << "Path length: " << temp->distance << std::endl; 
}

void Graph::dijkstra(int start) {
    nodes[start].distance = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, start));
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > nodes[u].distance) continue;
        
        for (const auto e : nodes[u].edges) {
            if (nodes[u].distance + e.weight < nodes[e.to].distance) {
                nodes[e.to].parent = &nodes[u];
                nodes[e.to].distance = nodes[u].distance + e.weight;
                pq.push(std::make_pair(nodes[e.to].distance, e.to));
            }
        }
    }
}
