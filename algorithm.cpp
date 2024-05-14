#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)


vector<int> f(vector<vector<pair<int, int>>>& graph, vector<int> &IntermediateStations, int start) {
	int size = graph.size();
	vector<int> dist(size, pow(10, 6));
	dist[start] = 0;
	vector <bool> visited(size);

	for (int i = 0; i < size; ++i) {
		int nearest = -1;
		for (int v = 0; v < size; ++v) {
			if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v])) {
				nearest = v;
			}
		}

		visited[nearest] = true;

		for (auto &[to, weight] : graph[nearest]) {
			if (dist[to] > dist[nearest] + weight) {
				dist[to] = dist[nearest] + weight;
				IntermediateStations.at(to) = nearest;
			}
		}
	}
	return dist;
}
int main() {

	freopen("input.txt", "r", stdin);

	int StationsCount, DistCount;
	cin >> StationsCount >> DistCount;

	vector<vector<pair<int, int>>> graph(StationsCount);
	vector<int> IntermediateStations(StationsCount, -1);
	for (int i{}; i < DistCount; ++i) {
		int a, b, weight;
		cin >> a >> b >> weight;

		graph[a].push_back({ b, weight });
		graph[b].push_back({ a, weight });
	}

	int start;
	cin >> start;
	int finish;
	cin >> finish;

	vector<int> dist = f(graph, IntermediateStations, start);

	vector<int> temp;     
	for (int i = finish ; i != -1; i = IntermediateStations.at(i)) temp.push_back(i);  
	reverse(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); ++i) cout << temp.at(i) << " ";
	cout << '\n' << dist[finish];
}