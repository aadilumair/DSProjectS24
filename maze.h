#pragma once
#include "graph.h"
#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include </Users/salman/Desktop/SFML-2.6.1-macOS-clang-arm64/include/SFML/Graphics.hpp>

class Maze
{
public:
	
	static void setupMaze(int N, Graph & g) {
		srand(time(0));

		// Add vertices with coordinates
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				g.addV(i * N + j, Coordinate(i, j));
			}
		}

		// Add horizontal edges
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N - 1; ++j) {
				GraphNode tmpU;
				tmpU.coord = Coordinate(i, j);
				tmpU.vertex = i * N + j;

				GraphNode tmpV;
				tmpV.coord = Coordinate(i, j + 1);
				tmpV.vertex = i * N + j + 1;
				g.addE(tmpU, tmpV);
			}
		}

		// Add vertical edges
		for (int i = 0; i < N - 1; ++i) {
			for (int j = 0; j < N; ++j) {
				GraphNode tmpU;
				tmpU.coord = Coordinate(i, j);
				tmpU.vertex = i * N + j;

				GraphNode tmpV;
				tmpV.coord = Coordinate(i + 1, j);
				tmpV.vertex = (i + 1) * N + j;
				g.addE(tmpU, tmpV);
			}
		}
	}

	static void runDFS(Graph & g) {
		std::vector<bool> visited(g.noOfV, false);
		std::stack<int> dfsStack;

		int start = rand() % g.noOfV;
		dfsStack.push(start);
		visited[start] = true;

		while (!dfsStack.empty()) {
			int curr = dfsStack.top();
			dfsStack.pop();

			random_shuffle(g.adj[curr].begin(), g.adj[curr].end());

			int unvisitedNeighbours = 0;
			for (int i = 0; i < g.adj[curr].size(); i++) {
				const GraphNode neighbour = g.adj[curr][i];
				if (!visited[neighbour.vertex]) {
					unvisitedNeighbours++;
					dfsStack.push(neighbour.vertex);
					visited[neighbour.vertex] = true;
				}
			}

			if (unvisitedNeighbours == 1) {
				for (int i = 0; i < g.adj[curr].size(); i++) {
					const GraphNode neighbour = g.adj[curr][i];
					if (!visited[neighbour.vertex]) {
						removeWall(curr, neighbour.vertex, g);
					}
				}
			}

		}
	}

	static void removeWall(int u, int v, Graph & g) {
		for (int i = 0; i < g.adj[u].size(); ++i) {
			if (g.adj[u][i].vertex == v) {
				g.adj[u].erase(g.adj[u].begin() + i);
				break;
			}
		}
		for (int i = 0; i < g.adj[v].size(); ++i) {
			if (g.adj[v][i].vertex == u) {
				g.adj[v].erase(g.adj[v].begin() + i);
				break;
			}
		}
	}

	static void drawMaze(sf::RenderWindow& window, int cellSize, Graph & g) {
		sf::RectangleShape wall;
		wall.setFillColor(sf::Color::White);
		wall.setSize(sf::Vector2f(cellSize, 2)); // Horizontal walls
		sf::RectangleShape wallVertical;
		wallVertical.setFillColor(sf::Color::White);
		wallVertical.setSize(sf::Vector2f(2, cellSize)); // Vertical walls

		for (int i = 0; i < g.noOfV; ++i) {
			for (int j = 0; j < g.adj[i].size(); j++) {
				GraphNode neighbour = g.adj[i][j];
				// Draw horizontal walls
				if (neighbour.coord.y == g.adj[i][0].coord.y && neighbour.coord.x == g.adj[i][0].coord.x + 1) {
					wall.setPosition(sf::Vector2f(g.adj[i][0].coord.x * cellSize + cellSize, g.adj[i][0].coord.y * cellSize + cellSize + cellSize));
					window.draw(wall);
				}
				// Draw vertical walls
				if (neighbour.coord.x == g.adj[i][0].coord.x && neighbour.coord.y == g.adj[i][0].coord.y + 1) {
					wallVertical.setPosition(sf::Vector2f(g.adj[i][0].coord.x * cellSize + cellSize + cellSize, g.adj[i][0].coord.y * cellSize + cellSize));
					window.draw(wallVertical);
				}
			}
		}
	}
};

