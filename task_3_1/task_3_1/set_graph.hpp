//
//  set_graph.hpp
//  task_3_1
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#ifndef set_graph_hpp
#define set_graph_hpp

#include <vector>
#include <assert.h>
#include <unordered_set>

using std::vector;
using std::unordered_set;

#include "igraph.hpp"

class SetGraph : public IGraph {
public:
    SetGraph(int count);
    SetGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    bool isValid(int vertex) const;
    
    vector<unordered_set<int>> hashTableList;
};

#endif /* set_graph_hpp */
