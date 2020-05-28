//
//  matrix_graph.cpp
//  task_3_1
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#include "matrix_graph.hpp"

MatrixGraph::MatrixGraph(int count) :
adjacency_matrix(count, vector<bool>(count, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) :
adjacency_matrix(graph.VerticesCount(), vector<bool>(graph.VerticesCount(), false)) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int j : graph.GetNextVertices(i)) {
            adjacency_matrix[i][j] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(isValid(from) && isValid(to));
    adjacency_matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return adjacency_matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(isValid(vertex));
    vector<int> result;
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        if (adjacency_matrix[vertex][i]) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(isValid(vertex));
    vector<int> result;
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        if (adjacency_matrix[i][vertex]) {
            result.push_back(i);
        }
    }
    return result;
}

bool MatrixGraph::isValid(int vertex) const {
    return vertex >= 0 && vertex < adjacency_matrix.size();
}

