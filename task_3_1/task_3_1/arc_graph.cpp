//
//  arc_graph.cpp
//  task_3_1
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#include "arc_graph.hpp"

ArcGraph::ArcGraph(int count) :
list_size(count) {}

ArcGraph::ArcGraph(const IGraph& graph) :
list_size(graph.VerticesCount()),
pairList(graph.VerticesCount()) {
    for (int i = 0; i < list_size; ++i) {
        for (int j : graph.GetNextVertices(i)) {
            pairList.emplace_back(i, j);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(isValid(from) && isValid(to));
    pairList.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return list_size;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(isValid(vertex));
    vector<int> result;
    for (pair<int, int> i : pairList) {
        if (i.first == vertex) {
            result.push_back(i.second);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(isValid(vertex));
    vector<int> result;
    for (pair<int, int> i : pairList) {
        if (i.second == vertex) {
            result.push_back(i.first);
        }
    }
    return result;
}

bool ArcGraph::isValid(int vertex) const {
    return vertex >= 0 && vertex < list_size;
}
