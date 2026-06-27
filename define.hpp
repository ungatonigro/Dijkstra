#ifndef DEFINE_HPP
#define DEFINE_HPP

#include <iostream>
#include <vector>
#include <queue>

struct edge {
    int to;
    int weight;
}; 

struct node {
    int id;
    int distance;
    std::priority_queue<edge> edges;
};

class Graph {
    public:
        Graph(int n);
        void addEdge(int from, int to, int weight);
        void printGraph();
        void dijkstra(int start);
    private:
        std::vector<node> nodes;
};


#endif // DEFINE_H