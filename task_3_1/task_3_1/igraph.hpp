//
//  igraph.hpp
//  task_3_1
//
//  Created by Mac-HOME on 27.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#ifndef igraph_h
#define igraph_h

#include <vector>

struct IGraph {
    virtual ~IGraph() {}
    
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const  = 0;
    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif /* igraph_h */
