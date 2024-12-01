#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

//vector<int> algorithm(vector<vector<pair<int, int>>>& graph, vector<int>& IntermediateStations, int start) {
//	int size = graph.size();
//	vector<int> dist(size, pow(10, 6));
//	dist[start] = 0;
//	vector <bool> visited(size);
//
//	for (int i = 0; i < size; ++i) {
//		int nearest = -1;
//		for (int v = 0; v < size; ++v) {
//			if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v])) {
//				nearest = v;
//			}
//		}
//
//		visited[nearest] = true;
//
//		for (auto& [to, weight] : graph[nearest]) {
//			if (dist[to] > dist[nearest] + weight) {
//				dist[to] = dist[nearest] + weight;
//				IntermediateStations.at(to) = nearest;
//			}
//		}
//	}
//	return dist;
//}



class Station {
public:
	int number;
	string name;
	string line;
	vector<pair<int, double>> nearstatins;
};