#pragma once
#include "WeightEdge.h"
#include <vector>

class IMstSolver {
public:
	virtual void generateMst(const std::vector<WeightEdge>& edges) = 0;
	virtual const std::vector<WeightEdge>& getMstEdges() const = 0;
	virtual ~IMstSolver() {}
};
