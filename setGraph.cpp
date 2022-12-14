#include "setGraph.hpp"

SetGraph::SetGraph(int count) 
    : graph_(count) {}

SetGraph::SetGraph(const IGraph& graph) 
    : graph_(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int j : graph.GetNextVertices(i)) {
            graph_[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    graph_[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return graph_.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto v : graph_[vertex]) {
        result.push_back(v);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < graph_.size(); ++i) {
        if (graph_[i].find(vertex) != graph_[i].end()) {
            result.push_back(i);
        }
    }
    return result;
}
