#include "listGraph.hpp"
#include "matrixGraph.hpp"
#include "setGraph.hpp"
#include "arcGraph.hpp"

#include <iostream>
#include <queue>
#include <random>

void bfs(const IGraph& graph, int vertex, void (*callback)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    while(!q.empty()) {
        auto current = q.front();
        q.pop();
        callback(current);
        auto adjacentVertices = graph.GetNextVertices(current);        
        for (int v = 0; v < adjacentVertices.size(); ++v) {
            if (!visited[adjacentVertices[v]]) {
                q.push(adjacentVertices[v]);
                visited[adjacentVertices[v]] = true;
            }
        }
    }
}

void print(int v) {
    std::cout << v << " ";
}

int main() {

    ListGraph listGraph(5);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 0);
    listGraph.AddEdge(4, 2);

    bfs(listGraph, 0, &print);
    std::cout << "\n";
    
    MatrixGraph matrixGraph(5);
    matrixGraph.AddEdge(0, 1);
    matrixGraph.AddEdge(1, 3);
    matrixGraph.AddEdge(2, 3);
    matrixGraph.AddEdge(3, 4);
    matrixGraph.AddEdge(3, 0);
    matrixGraph.AddEdge(4, 2);

    bfs(matrixGraph, 0, &print);
    std::cout << "\n";
    
    SetGraph setGraph(5);
    setGraph.AddEdge(0, 1);
    setGraph.AddEdge(1, 3);
    setGraph.AddEdge(2, 3);
    setGraph.AddEdge(3, 4);
    setGraph.AddEdge(3, 0);
    setGraph.AddEdge(4, 2);

    bfs(setGraph, 0, &print);
    std::cout << "\n";
    
    ArcGraph arcGraph(5);
    arcGraph.AddEdge(0, 1);
    arcGraph.AddEdge(1, 3);
    arcGraph.AddEdge(2, 3);
    arcGraph.AddEdge(3, 4);
    arcGraph.AddEdge(3, 0);
    arcGraph.AddEdge(4, 2);

    bfs(arcGraph, 0, &print);
    std::cout << "\n";
    
    listGraph = ListGraph(arcGraph);
    matrixGraph = MatrixGraph(listGraph);
    setGraph = SetGraph(matrixGraph);
    
    bfs(setGraph, 0, &print);
    std::cout << "\n";
    
    return 0;
}
