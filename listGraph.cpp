#include "listGraph.hpp"

ListGraph::ListGraph(int count) 
    : graph_(count) {}

ListGraph::ListGraph(const IGraph& graph)
    : graph_(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        graph_[i] = graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    graph_[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return graph_.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return graph_[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < graph_.size(); ++i) {
        for (int j = 0; j < graph_[i].size(); ++j) {
            if (graph_[i][j] == vertex) {
                result.push_back(i);
            }
        }
    }
    return result;
}
