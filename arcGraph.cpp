#include "arcGraph.hpp"

ArcGraph::ArcGraph(int count)
    : size_(count) {}

ArcGraph::ArcGraph(const IGraph& graph)
    : size_(graph.VerticesCount()),
      graph_(graph.VerticesCount()) {
    for (int u = 0; u < size_; ++u) {
        for (int v : graph.GetNextVertices(u)) {
            graph_.emplace_back(u, v);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    graph_.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return size_;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto edge : graph_) {
        if (edge.first == vertex) {
            result.push_back(edge.second);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (auto edge : graph_) {
        if (edge.second == vertex) {
            result.push_back(edge.first);
        }
    }
    return result;
}
