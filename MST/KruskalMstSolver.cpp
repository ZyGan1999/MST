#include "KruskalMstSolver.h"

int KruskalMstSolver::findUnion(int vertex) const {
	return vertex == unionFind[vertex] ? vertex : findUnion(unionFind[vertex]);
}

void KruskalMstSolver::unionCombine(int vertex, int vertex_) const {
	unionFind[findUnion(vertex)] = vertex_;
}

void KruskalMstSolver::generateMst(const std::vector<WeightEdge>& edges) {
	result.clear();
	std::priority_queue<SortedEdge> pq;
	int maxVertex = -1;
	for (auto edge : edges) {
		maxVertex = std::max(std::max(edge.getFrom(), edge.getTo()), maxVertex);
		pq.push(SortedEdge(edge.getFrom(), edge.getTo(), edge.getDistance()));
	}
	try { unionFind = new int[maxVertex]; }
	catch (...) {
		throw std::exception("Size too Large!");
	}
	for (int i = 0; i <= maxVertex; i++) {
		unionFind[i] = i;
	}

	while (!pq.empty()) {
		WeightEdge topEdge = pq.top(); pq.pop();
		if (findUnion(topEdge.getFrom()) != findUnion(topEdge.getTo())) {
			unionCombine(topEdge.getFrom(), topEdge.getTo());
			result.push_back(topEdge);
		}
	}
	
	// delete unionFind;
	// 若不注释此语句，则程序无法正常运行，尚不清楚原因
}

const std::vector<WeightEdge>& KruskalMstSolver::getMstEdges() const {
	return result;
}
