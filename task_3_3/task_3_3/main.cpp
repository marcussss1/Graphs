//
//  main.cpp
//  task_3_3
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 Требуется отыскать самый выгодный маршрут между городами.
 Требования: время работы O((N+M)logN), где N-количество городов, M-известных дорог между ними.
 Формат входных данных.
 Первая строка содержит число N – количество городов.
 Вторая строка содержит число M - количество дорог.
 Каждая следующая строка содержит описание дороги (откуда, куда, время в пути).
 Последняя строка содержит маршрут (откуда и куда нужно доехать).
 Формат выходных данных.
 Вывести длину самого выгодного маршрута.
 */

#include <iostream>
#include <vector>
#include <assert.h>
#include <limits>
#include <set>

using std::vector;
using std::pair;
using std::cin;
using std::cout;
using std::set;

struct IGraph {
    virtual ~IGraph() {}
    
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const  = 0;
    virtual std::vector<pair<int, int>> GetNextVertices(int vertex) const = 0;
};

class TimeGraph : public IGraph {
public:
    TimeGraph(int count);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<pair<int, int>> GetNextVertices(int vertex) const override;
    
    void AddEdge(int from, int to, int time);
    
private:
    bool isValid(int vertex) const;
    
    vector<vector<pair<int, int>>> adjacency_lists;
};

TimeGraph::TimeGraph(int count) :
adjacency_lists(count) {}

void TimeGraph::AddEdge(int from, int to) {
    assert(isValid(from) && isValid(to));
    adjacency_lists[from].emplace_back(to, 0);
    adjacency_lists[to].emplace_back(from, 0);
}

void TimeGraph::AddEdge(int from, int to, int time) {
    assert(isValid(from) && isValid(to) && time >= 0);
    adjacency_lists[from].emplace_back(to, time);
    adjacency_lists[to].emplace_back(from, time);
}

int TimeGraph::VerticesCount() const {
    return adjacency_lists.size();
}

std::vector<pair<int, int>> TimeGraph::GetNextVertices(int vertex) const {
    assert(isValid(vertex));
    vector<pair<int, int>> result;
    for (int i = 0; i < adjacency_lists[vertex].size(); ++i) {
        result.push_back(adjacency_lists[vertex][i]);
    }
    return result;
}

bool TimeGraph::isValid(int vertex) const {
    return vertex >= 0 && vertex < adjacency_lists.size();
}

int find_min_path(const IGraph& graph, int from, int to) {
    int size = graph.VerticesCount();
    assert(from >= 0 && from < size);
    assert(to >= 0 && to < size);
    
    vector<int> time(size, std::numeric_limits<std::int32_t>::max());
    set<int> q;
    
    time[from] = 0;
    q.insert(from);
    
    while (!q.empty()) {
        int cur_vert = *q.begin();
        q.erase(q.begin());
        
        for (pair<int, int> p : graph.GetNextVertices(cur_vert)) {
            int vert = p.first;
            int cur_time = p.second;
            if (time[cur_vert] + cur_time < time[vert]) {
                q.erase(vert);
                time[vert] = time[cur_vert] + cur_time;
                q.insert(vert);
            }
        }
    }
    return time[to];
}

int main(int argc, const char * argv[]) {
    int vertex_count = 0, node_count = 0;
    cin >> vertex_count >> node_count;
    TimeGraph graph(vertex_count);
    
    for (int i = 0; i < node_count; ++i) {
        int from = 0, to = 0, time = 0;
        cin >> from >> to >> time;
        graph.AddEdge(from, to, time);
    }
    int from = 0, to = 0;
    cin >> from >> to;
    
    int min_path_count = find_min_path(graph, from, to);
    cout << min_path_count;
    return 0;
}
