#include "matrixGraph.hpp"

MatrixGraph::MatrixGraph(int count) 
    : graph_(count, std::vector<bool>(count, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) 
    : graph_(graph.VerticesCount(), 
                       std::vector<bool>(graph.VerticesCount(), false)) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int j : graph.GetNextVertices(i)) {
            graph_[i][j] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    graph_[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return graph_.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < graph_.size(); ++i) {
        if (graph_[vertex][i]) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < graph_.size(); ++i) {
        if (graph_[i][vertex]) {
            result.push_back(i);
        }
    }
    return result;
}
