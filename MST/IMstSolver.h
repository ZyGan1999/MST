#pragma once
#include "WeightEdge.h"
#include <vector>

/*
为图计算MST的类的通用接口，一切用于计算MST的Solver类均继承于此，
这样在Graph中只需要保留IMstSolver类的指针
就可以替换不同实现方式的MstSolver
*/

class IMstSolver {
public:
	virtual void generateMst(const std::vector<WeightEdge>& edges) = 0;
	virtual const std::vector<WeightEdge>& getMstEdges() const = 0;
	virtual ~IMstSolver() {}
};
