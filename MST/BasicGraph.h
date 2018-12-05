#pragma once
#include "WeightEdge.h"
#include <vector>

/*
最基本的图，只含有边的集合，其构造函数为保护的，只能通过其派生类创建
*/

class BasicGraph {
public:
	const std::vector<WeightEdge>& getEdges() const { return *edges; }
	~BasicGraph() { delete edges; }
protected:
	BasicGraph() : edges(nullptr) {}
	std::vector<WeightEdge> * edges;
};
