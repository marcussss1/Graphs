//
//  list_graph.cpp
//  task_3_1
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#include "list_graph.hpp"

ListGraph::ListGraph(int count) :
adjacency_lists(count) {}

ListGraph::ListGraph(const IGraph& graph) :
adjacency_lists(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        adjacency_lists[i] = graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(isValid(from) && isValid(to));
    adjacency_lists[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacency_lists.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(isValid(vertex));
    return adjacency_lists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(isValid(vertex));
    vector<int> result;
    for (int i = 0; i < adjacency_lists.size(); ++i) {
        for (int j = 0; j < adjacency_lists[i].size(); ++j) {
            if (adjacency_lists[i][j] == vertex) {
                result.push_back(i);
            }
        }
    }
    return result;
}

bool ListGraph::isValid(int vertex) const {
    return vertex >= 0 && vertex < adjacency_lists.size();
}
