#pragma once

/*
最基本的边，只有起点和终点
*/

class BasicEdge {
public:
	BasicEdge(int from_, int to_): from(from_), to(to_) {}
	int getFrom() const { return from; }
	int getTo() const { return to; }
protected:
	int from;
	int to;
};
