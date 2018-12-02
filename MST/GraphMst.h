#pragma once
#include "IMstSolver.h"
#include "BasicGraph.h"

class GraphMstBuilder;

class GraphMst sealed : BasicGraph {
public:
	friend class GraphMstBuilder;
	const std::vector<WeightEdge>& getMstEdges() const { return mstSolverPtr->getMstEdges(); }
	~GraphMst() { delete mstSolverPtr; }
private:
	GraphMst() : BasicGraph(), mstSolverPtr(nullptr) {}
	IMstSolver * mstSolverPtr;
};

class GraphMstBuilder {
public:
	GraphMstBuilder(): edges(new std::vector<WeightEdge>) {}
	GraphMstBuilder& addEdge(int from, int to, int dist) {
		edges->push_back(WeightEdge(from, to, dist));
		return *this;
	}

	GraphMstBuilder& setMstSolver(IMstSolver * mstSolver) {
		mstSolverPtr = mstSolver;
		return *this;
	}

	GraphMst* build() {
		auto res = new GraphMst();
		res->edges = edges;
		res->mstSolverPtr = mstSolverPtr;
		mstSolverPtr->generateMst(*edges);
		return res;
	}
private:
	std::vector<WeightEdge> * edges;
	IMstSolver * mstSolverPtr;
};
