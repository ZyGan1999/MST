#pragma once
#include "WeightEdge.h"
#include <vector>

class BasicGraph {
public:
	const std::vector<WeightEdge>& getEdges() const { return *edges; }
	~BasicGraph() { delete edges; }
protected:
	BasicGraph() : edges(nullptr) {}
	std::vector<WeightEdge> * edges;
};
