#ifndef DEFINE_HPP
#define DEFINE_HPP

#include <iostream>
#include <vector>
#include <queue>

struct edge {
    int to;
    int weight;
    bool operator<(const edge& other) const ;
}; 

struct node {
    int id;
    int distance;
    node* next;
    std::priority_queue<edge> edges;
};

class Graph {
    public:
        Graph(int n);
        void addEdge(int from, int to, int weight);
        void printGraph();
        void dijkstra(int start);
        void printRoute(int start);
    private:
        std::vector<node> nodes;
};


#endif // DEFINE_H