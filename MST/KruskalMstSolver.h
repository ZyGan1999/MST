#pragma once
#include "IMstSolver.h"
#include "SortedEdge.h"
#include <set>
#include <queue>
#include <algorithm>
#include <exception>

/*
使用kruskal算法实现的MstSolver
*/

class KruskalMstSolver sealed: public IMstSolver {
public:
	void generateMst(const std::vector<WeightEdge>& edges);
	const std::vector<WeightEdge>& getMstEdges() const;
private:
	int * unionFind;
	int findUnion(int vertex) const;
	void unionCombine(int vertex, int vertex_) const;
	std::vector<WeightEdge> result;
};
