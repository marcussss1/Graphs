//
//  list_graph.hpp
//  task_3_1
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#ifndef list_graph_hpp
#define list_graph_hpp

#include <vector>
#include <assert.h>

using std::vector;

#include "igraph.hpp"

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

#endif /* list_graph_hpp */
