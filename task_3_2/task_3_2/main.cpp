//
//  main.cpp
//  task_3_2
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 Дан невзвешенный неориентированный граф. В графе может быть несколько
 кратчайших путей между какими-то вершинами.
 Найдите количество различных кратчайших путей между заданными вершинами.
 Требования: сложность O(V+E).
 */

#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>

using std::vector;
using std::queue;
using std::cin;
using std::cout;

struct IGraph {
    virtual ~IGraph() {}
    
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const  = 0;
    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

class ListGraph : public IGraph {
public:
    ListGraph(int count);
    ListGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    bool isValid(int vertex) const;
    
    vector<vector<int>> adjacency_lists;
};

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
    adjacency_lists[to].push_back(from);
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

int find_min_path_count(const IGraph& graph, int from, int to) {
    int size = graph.VerticesCount();
    assert(from >= 0 && from < size);
    assert(to >= 0 && to < size);
    
    vector<bool> visited(size, false);
    vector<int> dist(size, size + 1);
    vector<int> min_path_count(size, 0);
    queue<int> q;
    
    q.push(from);
    visited[from] = true;
    dist[from] = 0;
    min_path_count[from] = 1;
    
    while (!q.empty()) {
        int cur_vert = q.front();
        q.pop();
        
        for (int vert : graph.GetNextVertices(cur_vert)) {
            if (dist[cur_vert] + 1 < dist[vert]) {
                dist[vert] = dist[cur_vert] + 1;
                min_path_count[vert] = min_path_count[cur_vert];
            } else if (dist[cur_vert] + 1 == dist[vert]) {
                min_path_count[vert] += min_path_count[cur_vert];
            }
            if (!visited[vert]) {
                q.push(vert);
                visited[vert] = true;
            }
        }
    }
    return min_path_count[to];
}

int main(int argc, const char * argv[]) {
    int vertex_count = 0, node_count = 0;
    cin >> vertex_count >> node_count;
    ListGraph graph(vertex_count);
    
    for (int i = 0; i < node_count; ++i) {
        int from = 0, to = 0;
        cin >> from >> to;
        graph.AddEdge(from, to);
    }
    int from = 0, to = 0;
    cin >> from >> to;
    
    int min_path_count = find_min_path_count(graph, from, to);
    cout << min_path_count;
    return 0;
}
