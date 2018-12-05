#pragma once
#include "BasicEdge.h"

/*
继承于BasicEdge，比其多了一个权重的属性，在图中使用这个数据结构
*/

class WeightEdge : public BasicEdge {
public:
	WeightEdge(int from_, int to_, int dist_) : BasicEdge(from_, to_), distance(dist_) {}
	int getDistance() const { return distance; }
protected:
	int distance;
};
