#include "IGraph.hpp"
#include <vector>
#include <unordered_set>

class SetGraph : public IGraph {
 public:
    SetGraph(int count);
    SetGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
    
 private:    
    std::vector<std::unordered_set<int>> graph_;
};
