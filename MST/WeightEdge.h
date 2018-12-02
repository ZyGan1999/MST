#pragma once
#include "BasicEdge.h"

class WeightEdge : public BasicEdge {
public:
	WeightEdge(int from_, int to_, int dist_) : BasicEdge(from_, to_), distance(dist_) {}
	int getDistance() const { return distance; }
protected:
	int distance;
};
