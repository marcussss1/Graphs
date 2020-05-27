//
//  set_graph.cpp
//  task_3_1
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#include "set_graph.hpp"

SetGraph::SetGraph(int count) :
hashTableList(count) {}

SetGraph::SetGraph(const IGraph& graph) :
hashTableList(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int j : graph.GetNextVertices(i)) {
            hashTableList[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(isValid(from) && isValid(to));
    hashTableList[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return hashTableList.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(isValid(vertex));
    vector<int> result;
    for (int i : hashTableList[vertex]) {
        result.push_back(i);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(isValid(vertex));
    vector<int> result;
    for (int i = 0; i < hashTableList.size(); ++i) {
        if (hashTableList[i].find(vertex) != hashTableList[i].end()) {
            result.push_back(i);
        }
    }
    return result;
}

bool SetGraph::isValid(int vertex) const {
    return vertex >= 0 && vertex < hashTableList.size();
}
