//
//  arc_graph.hpp
//  task_3_1
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#ifndef arc_graph_hpp
#define arc_graph_hpp

#include <vector>
#include <assert.h>

using std::vector;
using std::pair;

#include "igraph.hpp"

class ArcGraph : public IGraph {
public:
    ArcGraph(int count);
    ArcGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    bool isValid(int vertex) const;
    
    vector<pair<int, int>> pairList;
    int list_size;
};

#endif /* arc_graph_hpp */
