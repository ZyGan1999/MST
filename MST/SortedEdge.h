#pragma once
#include "WeightEdge.h"

/*
可供排序的边，在优先队列中使用这种边
*/

class SortedEdge : public WeightEdge {
public:
	SortedEdge(int from_, int to_, int dist_) : WeightEdge(from_, to_, dist_) {}

	bool operator < (const SortedEdge& rhs) const {
		return distance > rhs.distance;
	}
};
