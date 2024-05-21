//#include <iostream>
//#include <vector>
//#include <iomanip>
//#include <fstream>
//#include "Source.cpp"
//using namespace std;
//#pragma warning(disable:4996)
//
//
//vector<double> algorithm(vector<Station>& Stations, vector<int> &IntermediateStations, int start) {
//	int size = Stations.size();
//	vector<double> dist(size, pow(10, 6));
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
//		for (auto &[to, distance] : Stations[nearest].nearstatins) {
//			if (dist[to] > dist[nearest] + distance) {
//				dist[to] = dist[nearest] + distance;
//				IntermediateStations.at(to) = nearest;
//			}
//		}
//	}
//	return dist;
//}
//
//void PrintPath(vector<Station>& Stations, vector<int>& IntermediateStations,vector<double> dist, int start, int finish) {
//	
//	vector<int> VisitedStations;
//	for (int i = finish; i != -1; i = IntermediateStations.at(i)) VisitedStations.push_back(i);
//	reverse(VisitedStations.begin(), VisitedStations.end());
//
//	double a = 0;
//	double Time = (60 * dist[finish] / AverageSpeed) + AverageTimeOfWaiting;
//
//
//	for (int i = 0; i < VisitedStations.size() - 1; ++i) {
//		if (Stations[VisitedStations[i]].line != Stations[VisitedStations[i + 1]].line) {
//			Time += AverageTransferTime + AverageTimeOfWaiting;
//
//		}
//	}
//
//	cout << "\n\n" << "Время пути:  " << setprecision(4) << Time << " мин." << "\n\n";
//
//	cout << Stations[VisitedStations[0]].name << "   " << Stations[VisitedStations[0]].line << '\n';
//
//	for (int i = 1; i < VisitedStations.size(); ++i) {
//
//		if (Stations[VisitedStations[i - 1]].line != Stations[VisitedStations[i]].line) {
//			cout << '\t' << "пересадка с слинии: " << Stations[VisitedStations[i - 1]].line
//				<< " на линию: " << Stations[VisitedStations[i]].line << '\n';
//		}
//
//		cout << "\tВремя пути до станции " << Stations[VisitedStations[i]].name << " : ";
//		cout << setprecision(2) << static_cast<double>(60 * ((dist[VisitedStations[i]] - a) / AverageSpeed)) << " мин." << "\n";
//		cout << Stations[VisitedStations[i]].name << "   " << Stations[VisitedStations[i]].line << '\n';
//
//		a += dist[VisitedStations[i]] - a;
//	}
//
//}
//
//constexpr double AverageSpeed = 45.12;
//constexpr double AverageTransferTime = 1.5;
//constexpr double AverageTimeOfWaiting = 1;
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//	freopen("текст.txt", "r", stdin);
//
//	int StationsCount, DistCount;
//	cin >> StationsCount >> DistCount;
//
//	vector<Station> Stations(StationsCount);
//	//cout << Stations.size() << '\n';
//	vector<int> IntermediateStations(StationsCount, -1);
//
//	//ifstream input;          // поток для записи
//	//input.open("Текст.txt");
//
//
//	for (int i{}; i < DistCount; ++i) {
//		int number1, number2; 
//		double distance;
//		string name1, line;
//
//		cin >> number1 >> name1 >> line;
//		cin >> number2 >> distance;
//
//		Stations[number1].name = name1;
//		Stations[number1].number = number1;
//		Stations[number1].line = line;
//		Stations[number1].nearstatins.push_back({ number2, distance });
//		Stations[number2].nearstatins.push_back({ number1, distance });
//	}
//
//	//cout << Stations[0].nearstatins.size() << '\n';
//	//cout << Stations.size() << '\n';
//	int start{};
//	int finish{};
//	string start1, finish1;
//	cin >> start1 >> finish1;
//	for (int i{}; i < StationsCount; ++i) {
//		if (start1 == Stations[i].name) start = i;
//		else if (finish1 == Stations[i].name) finish = i;
//	}
//
//
//	vector<double> dist = algorithm(Stations, IntermediateStations, start);
//
//	vector<int> VisitedStations;     
//	for (int i = finish ; i != -1; i = IntermediateStations.at(i)) VisitedStations.push_back(i);  
//	reverse(VisitedStations.begin(), VisitedStations.end());
//
//	double a = 0;
//	double Time = (60 * dist[finish] / AverageSpeed) + AverageTimeOfWaiting;
//
//
//	for (int i = 0; i < VisitedStations.size() - 1; ++i) {
//		if (Stations[VisitedStations[i]].line != Stations[VisitedStations[i + 1]].line) {
//			Time += AverageTransferTime + AverageTimeOfWaiting;
//
//		}
//	}
//
//	cout << "\n\n" << "Время пути:  " << setprecision(4) << Time << " мин." << "\n\n";
//
//	cout << Stations[VisitedStations[0]].name << "   " << Stations[VisitedStations[0]].line << '\n';
//	
//	for (int i = 1; i < VisitedStations.size() ; ++i) {
//
//		if (Stations[VisitedStations[i - 1]].line != Stations[VisitedStations[i]].line) {
//			cout << '\t' << "пересадка с слинии: " << Stations[VisitedStations[i - 1]].line
//				<< " на линию: " << Stations[VisitedStations[i]].line << '\n';
//		}
//			
//		cout << "\tВремя пути до станции " << Stations[VisitedStations[i]].name << " : ";
//		cout << setprecision(2) << static_cast<double>(60 * ((dist[VisitedStations[i]] - a) / AverageSpeed)) << " мин." << "\n";
//		cout << Stations[VisitedStations[i]].name <<  "   " << Stations[VisitedStations[i]].line << '\n';
//
//		a += dist[VisitedStations[i]] - a;
//	}
//
//
//}