#pragma once
#include<iostream>
#include<vector>
#include "coord.h"

struct GraphNode {
	int vertex;
	Coordinate coord;
};

class Graph
{
private:
	int noOfV;
	std::vector<std::vector<GraphNode>> adj; // Adjacency list with coordinates

public:
	Graph(int vertices){
		noOfV = vertices;
		adj.resize(noOfV);
	}

	void addV(int pos, Coordinate coord) {
		if (pos >= noOfV) {
			noOfV = pos + 1;
			adj.resize(noOfV);
		}

		GraphNode tmp;
		tmp.coord = coord;
		tmp.vertex = pos;

		adj[pos].push_back(tmp);
	}

	void addE(GraphNode u, GraphNode v) {
		adj[u.vertex].push_back(v);
		adj[v.vertex].push_back(u);
	}
};

